// Fill out your copyright notice in the Description page of Project Settings.
 
#include "MotionVector.h"
#include "ActorsMotionVectors.h"
#include "Runtime/Engine/Private/SkeletalRenderCPUSkin.h"

// Sets default values
AActorsMotionVectors::AActorsMotionVectors()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorsMotionVectors::BeginPlay()
{
	Super::BeginPlay();
	uint32 NumVertices;

	//Get all skeletal actors on scene
	for (TActorIterator<ASkeletalMeshActor> Itr(GetWorld()); Itr; ++Itr) {
		FSkeletalMeshActorVertexPos SkeletalActor;
		SkeletalActor.SkelMeshActor = *Itr;
		if (SkeletalActor.SkelMeshActor->GetSkeletalMeshComponent()->MeshObject) {
			NumVertices = SkeletalActor.SkelMeshActor->GetSkeletalMeshComponent()->MeshObject->GetSkeletalMeshResource().LODModels[0].NumVertices;
			SkeletalActor.SkeletalCurrVertexPos.AddZeroed(NumVertices);
			SkeletalActor.SkeletalOldVertexPos.AddZeroed(NumVertices);
			SkeletalMeshVerticesPositions.Add(SkeletalActor);
		}
	}


	//Get all static actors on scene
	for (TActorIterator<AStaticMeshActor> Itr(GetWorld()); Itr; ++Itr) {
		FStaticMeshActorVertexPos StaticActor;
		StaticActor.StatMeshActor = *Itr;
		if (StaticActor.StatMeshActor->GetStaticMeshComponent()->GetStaticMesh()) {
			FPositionVertexBuffer* VertexBuffer = &StaticActor.StatMeshActor->GetStaticMeshComponent()->GetStaticMesh()->RenderData->LODResources[0].PositionVertexBuffer;
			if (VertexBuffer)
			{
				const int32 VertexCount = VertexBuffer->GetNumVertices();
				StaticActor.StaticCurrVertexPos.AddZeroed(VertexBuffer->GetNumVertices());
				StaticActor.StaticOldVertexPos.AddZeroed(VertexBuffer->GetNumVertices());
			}
			StaticMeshVerticesPositions.Add(StaticActor);
		}
	}
	
}


// Called every frame
void AActorsMotionVectors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetWorld()->GetFirstPlayerController()->GetViewportSize(/*out*/ViewPortXCoord, /*out*/ViewPortYCoord);

#pragma region SkeletalMeshActor
	for (int32 currentSkelActor = 0; currentSkelActor < SkeletalMeshVerticesPositions.Num(); currentSkelActor++) {
		if (SkeletalMeshVerticesPositions[currentSkelActor].SkelMeshActor) {
		if (SkeletalMeshVerticesPositions[currentSkelActor].SkelMeshActor->WasRecentlyRendered()) {
				SkeletalMeshVerticesPositions[currentSkelActor].SkeletalOldVertexPos =
					SkeletalMeshVerticesPositions[currentSkelActor].SkeletalCurrVertexPos; // set old vertex pos of all skel actors to curr vertex pos

				GetVertexPositions(
					SkeletalMeshVerticesPositions[currentSkelActor].SkelMeshActor->GetSkeletalMeshComponent(),
					SkelVertexPositions
				);

				SkeletalMeshVerticesPositions[currentSkelActor].SkeletalCurrVertexPos = SkelVertexPositions;

				SetVertexColors(
					SkeletalMeshVerticesPositions[currentSkelActor].SkeletalCurrVertexPos,
					SkeletalMeshVerticesPositions[currentSkelActor].SkeletalOldVertexPos,
					SkelVertexLinearColors
				);

				SkeletalMeshVerticesPositions[currentSkelActor].SkelMeshActor->GetSkeletalMeshComponent()->SetVertexColorOverride_LinearColor(0, SkelVertexLinearColors);
			}
		}
	}
#pragma endregion SkeletalMeshActor

#pragma region StaticMeshActor
	for (int32 currentStatActor = 0; currentStatActor < StaticMeshVerticesPositions.Num(); currentStatActor++) {
		if (StaticMeshVerticesPositions[currentStatActor].StatMeshActor) {
			if (StaticMeshVerticesPositions[currentStatActor].StatMeshActor->WasRecentlyRendered()) {
				StaticMeshVerticesPositions[currentStatActor].StaticOldVertexPos =
					StaticMeshVerticesPositions[currentStatActor].StaticCurrVertexPos; // set old vertex pos of all stat actors to curr vertex pos

				GetSMVertexPositions(
					StaticMeshVerticesPositions[currentStatActor].StatMeshActor->GetStaticMeshComponent(),
					SkelVertexPositions
				);

				StaticMeshVerticesPositions[currentStatActor].StaticCurrVertexPos = SkelVertexPositions;

				SetVertexColors(
					StaticMeshVerticesPositions[currentStatActor].StaticCurrVertexPos,
					StaticMeshVerticesPositions[currentStatActor].StaticOldVertexPos,
					StatVertexLinearColors
				);

				SetSMVertexColors(
					StaticMeshVerticesPositions[currentStatActor].StatMeshActor->GetStaticMeshComponent(),
					StatVertexLinearColors
				);
			}
		}
	}
#pragma endregion StaticMeshActor

}

void AActorsMotionVectors::SetVertexColors(TArray <FVector> CurrPos, TArray <FVector> OldPos, TArray<FLinearColor> &Colors) {
	FVector temp; // temporary value
	Colors.SetNum(CurrPos.Num()); // resize array of linear colors
	for (int32 i = 0; i < CurrPos.Num(); i++) {
		temp = CurrPos[i] - OldPos[i]; // subtract positions
		//
		if (temp.Normalize())//need to normalize vector before setting to linear color 
		{
			Colors[i].R = FMath::Abs(temp.X); // sets R color
			Colors[i].G = FMath::Abs(temp.Y); // sets G color
			Colors[i].B = FMath::Abs(temp.Z); // sets B color
			Colors[i].A = 0; // alpha = 0
		}
	}
}

UTexture2D * AActorsMotionVectors::GetPixelData(UTextureRenderTarget2D * TextureRenderTarget)
{
	UTexture2D *Texture = UTexture2D::CreateTransient(TextureRenderTarget->SizeX, TextureRenderTarget->SizeY, PF_B8G8R8A8);
	Texture->MipGenSettings = TMGS_NoMipmaps;
	Texture->SRGB = TextureRenderTarget->SRGB;
	TArray<FColor> SurfData;
	FRenderTarget *RenderTarget = TextureRenderTarget->GameThread_GetRenderTargetResource();
	RenderTarget->ReadPixels(SurfData);
	void* TextureData = Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	const int32 TextureDataSize = SurfData.Num() * 4;
	FMemory::Memcpy(TextureData, SurfData.GetData(), TextureDataSize);
	Texture->PlatformData->Mips[0].BulkData.Unlock();
	Texture->UpdateResource();
	return Texture;
}

void AActorsMotionVectors::GetVertexPositions(	USkeletalMeshComponent * SkelMeshComp, 	TArray <FVector> &Positions)
{
	if (SkelMeshComp) {
		const uint32 NumVertices = SkelMeshComp->MeshObject->GetSkeletalMeshResource().LODModels[0].NumVertices;
		Positions.Empty();
		for (uint32 i = 0; i < NumVertices; i++) {
			Positions.Add(SkelMeshComp->GetSkinnedVertexPosition(i));
		}
	}
}

void AActorsMotionVectors::GetSMVertexPositions(UStaticMeshComponent * StaticMeshComponent, TArray<FVector>& Positions)
{
	if (StaticMeshComponent) {
		FPositionVertexBuffer* VertexBuffer = &StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0].PositionVertexBuffer;
		FVector WorldSpaceVertexLocation;
		if (VertexBuffer)
		{
			const int32 VertexCount = VertexBuffer->GetNumVertices();
			Positions.Empty();
			for (int32 Index = 0; Index < VertexCount; Index++)
			{
				Positions.Add(StaticMeshComponent->GetComponentLocation() +
					StaticMeshComponent->GetComponentTransform().TransformVector(VertexBuffer->VertexPosition(Index)));
			}
		}
	}
}

void AActorsMotionVectors::SetSMVertexColors(UStaticMeshComponent * StaticMeshComp, TArray <FLinearColor> Colors)
{
	if (!StaticMeshComp) { return; }
	StaticMeshComp->SetLODDataCount(1, StaticMeshComp->LODData.Num());
	FStaticMeshComponentLODInfo* InstanceMeshLODInfo = &StaticMeshComp->LODData[0];
	InstanceMeshLODInfo->PaintedVertices.Empty();
	InstanceMeshLODInfo->OverrideVertexColors = new FColorVertexBuffer();
	
	FStaticMeshLODResources& LODModel = StaticMeshComp->GetStaticMesh()->RenderData->LODResources[0];
	if ((int32)LODModel.ColorVertexBuffer.GetNumVertices() >= LODModel.GetNumVertices())
	{
		InstanceMeshLODInfo->OverrideVertexColors->InitFromColorArray(&LODModel.ColorVertexBuffer.VertexColor(0), LODModel.GetNumVertices());
	}
	else
	{
		InstanceMeshLODInfo->OverrideVertexColors->InitFromSingleColor(FColor::Green, LODModel.GetNumVertices());
	}
	BeginInitResource(InstanceMeshLODInfo->OverrideVertexColors);
	StaticMeshComp->MarkRenderStateDirty();
	for (int32 i = 0; i < Colors.Num(); i++)
	{
		InstanceMeshLODInfo->OverrideVertexColors->VertexColor(i) = Colors[i].ToFColor(true);
	}
}
