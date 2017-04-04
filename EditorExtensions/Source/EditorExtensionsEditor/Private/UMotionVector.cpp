#include "EditorExtensionsEditorPrivatePCH.h"
#include "UnrealEd.h"
#include "MVTickObject.h"
#include "Runtime/Engine/Classes/Animation/SkeletalMeshActor.h"
#include "Runtime/Engine/Public/SkeletalRenderPublic.h"

// Notifications
#include "NotificationManager.h"
#include "SNotificationList.h"
#include "Editor/PackagesDialog/Public/PackagesDialog.h"

DEFINE_LOG_CATEGORY(MVEditor)

#define LOCTEXT_NAMESPACE "MVEditor"

UMotionVector::UMotionVector()
{
	ColorMultiply = 1;
	MinSpeed = 0.5;
	MaxSpeed = 10;
	bWasCalledInitConponentsForPIE = false;
	bWasCalledInitConponentsForEditor = false;
	GenerateMotionVectors = false;
	IncludeCamera = false;
	SkeletalMeshesCurrNum = 0;
	StaticMeshesCurrNum = 0;
}

void UMotionVector::Tick(float DeltaTime)
{
	//UE_LOG(MVEditor, Warning, TEXT("maxspeed %f"), MaxSpeed)
	if (!GEditor) return;
	if (GEditor->GetPIEWorldContext())
	{
		//////////////////////////////////////////////////////////////////////////
		//@TODO this is NOT a good solution. Need to make it better
		FVector CameraLocation = FVector::ZeroVector;
		if (IncludeCamera)
		{
			if (GEditor->GetPIEWorldContext()->World())
				if (GEditor->GetPIEWorldContext()->World()->GetFirstPlayerController())
					if (GEditor->GetPIEWorldContext()->World()->GetFirstPlayerController()->GetSpectatorPawn())
						for (auto LevelVC : GEditor->LevelViewportClients)
						{
							if (LevelVC && LevelVC->IsPerspective())
							{
								CameraLocation = LevelVC->GetViewLocation() + LevelVC->GetViewRotation().Vector()*FMath::Pow(MaxSpeed, 2);
								MotionVectors(GEditor->GetPIEWorldContext(), CameraLocation, bWasCalledInitConponentsForPIE);
								break;
							}
						}
					else
					{
						CameraLocation =
							(GEditor->GetFirstLocalPlayerController(GEditor->GetPIEWorldContext()->World())->PlayerCameraManager->GetCameraRotation().Vector()) *
							FMath::Pow(MaxSpeed, 2) +
							GEditor->GetFirstLocalPlayerController(GEditor->GetPIEWorldContext()->World())->PlayerCameraManager->GetCameraLocation();
						MotionVectors(GEditor->GetPIEWorldContext(), CameraLocation, bWasCalledInitConponentsForPIE);
					}
		}
		else
			MotionVectors(GEditor->GetPIEWorldContext(), CameraLocation, bWasCalledInitConponentsForPIE);
		bWasCalledInitConponentsForEditor = false;
		//////////////////////////////////////////////////////////////////////////
	}
	else if (&GEditor->GetEditorWorldContext())
	{
		FVector CameraLocation = FVector::ZeroVector;
		if (IncludeCamera)
		{
			if (!GEditor->GetActiveViewport()) return;
			if (!GEditor->GetActiveViewport()->GetClient()) return;
			auto Client = (FLevelEditorViewportClient*)GEditor->GetActiveViewport()->GetClient();
			if (!Client) return;
			CameraLocation = Client->GetViewLocation() + Client->GetViewRotation().Vector()*FMath::Pow(MaxSpeed, 2);
			MotionVectors(&GEditor->GetEditorWorldContext(), CameraLocation, bWasCalledInitConponentsForEditor);
		}
		else
			MotionVectors(&GEditor->GetEditorWorldContext(), CameraLocation, bWasCalledInitConponentsForEditor);
		bWasCalledInitConponentsForPIE = false;
	}
}

void UMotionVector::InitComponents(FWorldContext* WorldContext)
{
	SkeletalMeshes.Empty();
	StaticMeshes.Empty();
	//get skeletal mesh actors
	for (TActorIterator<ASkeletalMeshActor> Itr(WorldContext->World()); Itr; ++Itr)
	{
		FSkeletalMeshActorVerticesPosition SkeletalActor;
		SkeletalActor.SkeletalMeshActor = *Itr;
		if (SkeletalActor.SkeletalMeshActor->GetSkeletalMeshComponent()->MeshObject)
		{
			uint32 NumVertices =
				SkeletalActor.SkeletalMeshActor->GetSkeletalMeshComponent()->MeshObject->GetSkeletalMeshResource().LODModels[0].NumVertices;
			SkeletalActor.SkeletalCurrVerticesPosition.AddZeroed(NumVertices);
			SkeletalActor.SkeletalOldVerticesPosition.AddZeroed(NumVertices);
			SkeletalMeshes.Add(SkeletalActor);
		}
	}
	SkeletalMeshesCurrNum = SkeletalMeshes.Num();

	//get static mesh actors
	for (TActorIterator<AStaticMeshActor> Itr(WorldContext->World()); Itr; ++Itr)
	{
		FStaticMeshActorVerticesPosition StaticActor;
		StaticActor.StaticMeshActor = *Itr;
		if (StaticActor.StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh())
		{
			FPositionVertexBuffer* VertexBuffer =
				&StaticActor.StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources[0].PositionVertexBuffer;
			if (VertexBuffer)
			{
				const int32 VertexCount = VertexBuffer->GetNumVertices();
				StaticActor.StaticCurrVerticesPos.AddZeroed(VertexBuffer->GetNumVertices());
				StaticActor.StaticOldVerticesPos.AddZeroed(VertexBuffer->GetNumVertices());
			}
			StaticMeshes.Add(StaticActor);
		}
	}
	StaticMeshesCurrNum = StaticMeshes.Num();

	if (WorldContext->WorldType == EWorldType::Editor)
		bWasCalledInitConponentsForEditor = true;
	if (WorldContext->WorldType == EWorldType::PIE)
		bWasCalledInitConponentsForPIE = true;
}

void UMotionVector::MotionVectors(FWorldContext* WorldContext, FVector CameraLocation, bool bWasCalledInitConponentsForCurrentWorld)
{
	SkeletalMeshesCurrNum = 0;
	StaticMeshesCurrNum = 0;
	if (!bWasCalledInitConponentsForCurrentWorld)
		InitComponents(WorldContext);
	else
	{
		for (TActorIterator<ASkeletalMeshActor> Itr(WorldContext->World()); Itr; ++Itr)
			SkeletalMeshesCurrNum++;
		if (SkeletalMeshesCurrNum < SkeletalMeshes.Num())
			SkeletalMeshes.Empty();
		for (TActorIterator<AStaticMeshActor> Itr(WorldContext->World()); Itr; ++Itr)
			StaticMeshesCurrNum++;
		if (StaticMeshesCurrNum < StaticMeshes.Num())
			StaticMeshes.Empty();
		if (GetAllSkeletalActorsOnScene(SkeletalMeshes, WorldContext))
		{
			for (int32 currentSkelActor = 0; currentSkelActor < SkeletalMeshes.Num(); currentSkelActor++)
			{
				if (SkeletalMeshes[currentSkelActor].SkeletalMeshActor)
				{
					if (SkeletalMeshes[currentSkelActor].SkeletalMeshActor->WasRecentlyRendered())
					{
						SkeletalMeshes[currentSkelActor].SkeletalOldVerticesPosition =
							SkeletalMeshes[currentSkelActor].SkeletalCurrVerticesPosition; // set old vertex pos of all skel actors to curr vertex pos
						TArray<FVector> SkeletalVerticesPositions;
						GetSkeletalMeshVerticesPosition(
							SkeletalMeshes[currentSkelActor].SkeletalMeshActor->GetSkeletalMeshComponent(),
							SkeletalVerticesPositions, CameraLocation
						);

						SkeletalMeshes[currentSkelActor].SkeletalCurrVerticesPosition = SkeletalVerticesPositions;

						//Current skeletal actor
						TArray<FLinearColor> SkelVerticesLinearColors;
						BakeVerticesColor(
							SkeletalMeshes[currentSkelActor].SkeletalCurrVerticesPosition,
							SkeletalMeshes[currentSkelActor].SkeletalOldVerticesPosition,
							SkelVerticesLinearColors
						);

						SkeletalMeshes[currentSkelActor].SkeletalMeshActor->GetSkeletalMeshComponent()->SetVertexColorOverride_LinearColor(0, SkelVerticesLinearColors);
					}
				}
			}
		}

		if (GetAllStaticActorsOnScene(StaticMeshes, WorldContext))
		{
			for (int32 currentStatActor = 0; currentStatActor < StaticMeshes.Num(); currentStatActor++)
			{
				if (StaticMeshes[currentStatActor].StaticMeshActor)
				{
					if (StaticMeshes[currentStatActor].StaticMeshActor->WasRecentlyRendered())
					{
						StaticMeshes[currentStatActor].StaticOldVerticesPos =
							StaticMeshes[currentStatActor].StaticCurrVerticesPos; // set old vertex pos of all stat actors to curr vertex pos

						TArray<FVector> StatVerticesPositions;
						GetStaticMeshVerticesPosition(
							StaticMeshes[currentStatActor].StaticMeshActor->GetStaticMeshComponent(),
							StatVerticesPositions, CameraLocation
						);

						StaticMeshes[currentStatActor].StaticCurrVerticesPos = StatVerticesPositions;

						TArray<FLinearColor> StatVerticesLinearColors;
						BakeVerticesColor(
							StaticMeshes[currentStatActor].StaticCurrVerticesPos,
							StaticMeshes[currentStatActor].StaticOldVerticesPos,
							StatVerticesLinearColors
						);

						SetStaticMeshVerticesColors(
							StaticMeshes[currentStatActor].StaticMeshActor->GetStaticMeshComponent(),
							StatVerticesLinearColors
						);
					}
				}
			}
		}
	}
}

bool UMotionVector::GetAllSkeletalActorsOnScene(
	/*Fill this array with skeletal actors */ 
	TArray <FSkeletalMeshActorVerticesPosition> &SkelMeshes, 
	FWorldContext *WorldContext)
{	
	if (SkeletalMeshesCurrNum > SkelMeshes.Num())
		SkelMeshes.Empty();
	
	for (TActorIterator<ASkeletalMeshActor> Itr(WorldContext->World()); Itr; ++Itr)
	{
		if (FSkeletalMeshActorVerticesPosition::HasActor(SkelMeshes, *Itr))
			continue;
		FSkeletalMeshActorVerticesPosition SkeletalActor;
		SkeletalActor.SkeletalMeshActor = *Itr;
		if (SkeletalActor.SkeletalMeshActor->GetSkeletalMeshComponent()->MeshObject) 
		{
			uint32 NumVertices =
				SkeletalActor.SkeletalMeshActor->GetSkeletalMeshComponent()->MeshObject->GetSkeletalMeshResource().LODModels[0].NumVertices;
			SkeletalActor.SkeletalCurrVerticesPosition.AddZeroed(NumVertices);
			SkeletalActor.SkeletalOldVerticesPosition.AddZeroed(NumVertices);
			SkelMeshes.Add(SkeletalActor);
		}
	}
	if(SkelMeshes.Num() != 0)
		return true;
	return false;
}

bool UMotionVector::GetAllStaticActorsOnScene(
	/*Fill this array with static actors */ 
	TArray <FStaticMeshActorVerticesPosition> &StatMeshes, 
	FWorldContext *WorldContext)
{
	if (StaticMeshesCurrNum > StatMeshes.Num())
		StatMeshes.Empty();
	for (TActorIterator<AStaticMeshActor> Itr(WorldContext->World()); Itr; ++Itr)
	{
		if (FStaticMeshActorVerticesPosition::HasActor(StaticMeshes, *Itr))
			continue;
		FStaticMeshActorVerticesPosition StaticActor;
		StaticActor.StaticMeshActor = *Itr;
		if (StaticActor.StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()) 
		{
			FPositionVertexBuffer* VertexBuffer =
				&StaticActor.StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources[0].PositionVertexBuffer;
			if (VertexBuffer)
			{
				const int32 VertexCount = VertexBuffer->GetNumVertices();
				StaticActor.StaticCurrVerticesPos.AddZeroed(VertexBuffer->GetNumVertices());
				StaticActor.StaticOldVerticesPos.AddZeroed(VertexBuffer->GetNumVertices());
			}
			StatMeshes.Add(StaticActor);
		}
	}
	if(StatMeshes.Num() != 0)
		return true;
	return false;
}

void UMotionVector::GetSkeletalMeshVerticesPosition(USkeletalMeshComponent* SkeletalMeshComponent, TArray <FVector> &Positions, FVector CameraLocation)
{
	if (SkeletalMeshComponent) 
	{
		const uint32 NumVertices = SkeletalMeshComponent->MeshObject->GetSkeletalMeshResource().LODModels[0].NumVertices;
		Positions.Empty();
		for (uint32 i = 0; i < NumVertices; i++)
		{
			Positions.Add(SkeletalMeshComponent->GetSkinnedVertexPosition(i) +
				SkeletalMeshComponent->GetComponentLocation() +
				CameraLocation);
		}
	}
}

void UMotionVector::GetStaticMeshVerticesPosition(UStaticMeshComponent* StaticMeshComponent, TArray <FVector> &Positions, FVector CameraLocation)
{
	if (StaticMeshComponent) 
	{
		FPositionVertexBuffer* VertexBuffer = &StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0].PositionVertexBuffer;
		FVector WorldSpaceVertexLocation;
		if (VertexBuffer)
		{
			const int32 VertexCount = VertexBuffer->GetNumVertices();
			Positions.Empty();
			for (int32 Index = 0; Index < VertexCount; Index++)
			{
				Positions.Add(StaticMeshComponent->GetComponentLocation() +
					StaticMeshComponent->GetComponentTransform().TransformVector(VertexBuffer->VertexPosition(Index)) + CameraLocation);
			}
		}
	}
}

void UMotionVector::BakeVerticesColor(TArray <FVector> CurrPos, TArray <FVector> OldPos, TArray<FLinearColor> &Colors)
{
	FVector Temp; // temporary value
	Colors.SetNum(CurrPos.Num()); // resize array of linear colors
	for (int32 i = 0; i < CurrPos.Num(); i++)
	{
		Temp = CurrPos[i] - OldPos[i]; // subtract positions
		float Len = FVector::Distance(CurrPos[i], OldPos[i]);
		float LenMaxTransform = FMath::Clamp<float>(Len / MaxSpeed, 0, 1);
		float LenMinTransform = MinSpeed / MaxSpeed;
		float LenTransform = LenMaxTransform < LenMinTransform ? 0 : LenMaxTransform;
		Colors[i].R = FMath::Abs(LenTransform)*ColorMultiply; // sets R color
		Colors[i].G = FMath::Abs(LenTransform)*ColorMultiply; // sets G color
		Colors[i].B = FMath::Abs(LenTransform)*ColorMultiply; // sets B color
		Colors[i].A = 0; // alpha = 0
	}
}

void UMotionVector::SetStaticMeshVerticesColors(UStaticMeshComponent * StaticMeshComponent, TArray <FLinearColor> Colors)
{
	if (!StaticMeshComponent)  
		return; 
	StaticMeshComponent->SetLODDataCount(1, StaticMeshComponent->LODData.Num());
	FStaticMeshComponentLODInfo* InstanceMeshLODInfo = &StaticMeshComponent->LODData[0];
	InstanceMeshLODInfo->PaintedVertices.Empty();
	InstanceMeshLODInfo->OverrideVertexColors = new FColorVertexBuffer();

	FStaticMeshLODResources& LODModel = StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0];
	if ((int32)LODModel.ColorVertexBuffer.GetNumVertices() >= LODModel.GetNumVertices())
	{
		InstanceMeshLODInfo->OverrideVertexColors->InitFromColorArray(&LODModel.ColorVertexBuffer.VertexColor(0), LODModel.GetNumVertices());
	}
	else
	{
		InstanceMeshLODInfo->OverrideVertexColors->InitFromSingleColor(FColor::White, LODModel.GetNumVertices());
	}
	for (int32 i = 0; i < Colors.Num(); i++)
	{
		InstanceMeshLODInfo->OverrideVertexColors->VertexColor(i) = Colors[i].ToFColor(true);
	}
	BeginInitResource(InstanceMeshLODInfo->OverrideVertexColors);
	StaticMeshComponent->MarkRenderStateDirty();
}

bool UMotionVector::FSkeletalMeshActorVerticesPosition::HasActor(TArray<FSkeletalMeshActorVerticesPosition> SkelActors, ASkeletalMeshActor *SkelMeshActor)
{
	for (int32 i = 0; i < SkelActors.Num(); i++) {
		if (SkelActors[i].SkeletalMeshActor->GetName() == SkelMeshActor->GetName())
			return true;
	}
	return false;
}

bool UMotionVector::FStaticMeshActorVerticesPosition::HasActor(TArray<FStaticMeshActorVerticesPosition> StatActors, AStaticMeshActor *StatMeshActor)
{
	for (int32 i = 0; i < StatActors.Num(); i++) {
		if (StatActors[i].StaticMeshActor->GetName() == StatMeshActor->GetName())
			return true;
	}
	return false;
}

void UMotionVector::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UProperty *PropertyThatChanged = PropertyChangedEvent.Property;
	if (PropertyThatChanged)
	{
		if (PropertyThatChanged->GetFName() == FName("GenerateMotionVectors"))
		{
			ManageTickObject(GenerateMotionVectors);

		}

		if (PropertyThatChanged->GetFName() == FName("IncludeCamera"))
		{
			if (GenerateMotionVectors)
				IncludeCamera = IncludeCamera;
			else
				UMotionVector::NotificationBox(FString("Generate motion vectors first"));
		}

		if (PropertyThatChanged->GetFName() == FName("MaxSpeed"))
		{
			if (GenerateMotionVectors)
				MaxSpeed = MaxSpeed;
			else
				UMotionVector::NotificationBox(FString("Generate motion vectors first"));
		}

		if (PropertyThatChanged->GetFName() == FName("MinSpeed"))
		{
			if (GenerateMotionVectors)
				MinSpeed = MinSpeed;
			else
				UMotionVector::NotificationBox(FString("Generate motion vectors first"));
		}

		if (PropertyThatChanged->GetFName() == FName("ColorMultiply"))
		{
			if (GenerateMotionVectors)
				ColorMultiply = ColorMultiply;
			else
				UMotionVector::NotificationBox(FString("Generate motion vectors first"));
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void UMotionVector::ManageTickObject(bool Option)
{
	if (Option)
		TickObject = new FMVTickObject(this);
	else
	{
		if (TickObject)
		{
			delete TickObject;
			TickObject = nullptr;
		}
	}
}

void UMotionVector::NotificationBox(FString String, float FadeIn /*= 0.1f*/, float Expire /*= 1.5*/, float FadeOut /*= 1.f*/)
{
#if WITH_EDITOR
	const FText Message = FText::Format(LOCTEXT("NotificationInfo", "{0}"), FText::FromString(String));
	FNotificationInfo Info(Message);
	Info.FadeInDuration = FadeIn;
	Info.ExpireDuration = Expire;
	Info.FadeOutDuration = FadeOut;
	Info.bUseThrobber = false;
	Info.bUseSuccessFailIcons = true;
	Info.bUseLargeFont = true;
	Info.bFireAndForget = false;
	Info.bAllowThrottleWhenFrameRateIsLow = false;
	auto NotificationItem = FSlateNotificationManager::Get().AddNotification(Info);
	NotificationItem->SetCompletionState(SNotificationItem::CS_Success);
	NotificationItem->ExpireAndFadeout();
#endif
}

void UMotionVector::OnToolClosed()
{
	if (TickObject != nullptr)
		delete TickObject;
}
#undef LOCTEXT_NAMESPACE

