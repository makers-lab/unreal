#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "UMaterialTools.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "NotificationManager.h"
#include "SNotificationList.h"
#include "SContentReference.h"

#define LOCTEXT_NAMESPACE "UMaterialTools"

UMaterialTools::UMaterialTools()
{
}

void UMaterialTools::NotificationBox(FString String, float FadeIn /*= 0.1f*/, float Expire /*= 1.5*/, float FadeOut /*= 1.f*/)
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



void UMaterialTools::PreEditChange(UProperty* PropertyAboutToChange)
{

}

void UMaterialTools::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	
}

void UMaterialTools::OnToolClosed()
{

}




void UMaterialTools::CreateInstance()
{
		TSet<UMaterial*> ContentSelectedMaterials = GetSelectedMaterialsInContentBrowser();
		TSet<UMaterial*> ActorSelectedMaterials = GetSelectedActorMaterials();


		// Create an appropriate and unique name 
		FString Name;
		FString PackageName;
		FString CurrentInstanceName;
		FString InstanceName;

		int32 count = 0;

		GEditor->GetSelectedActors();


		UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
		Factory->InitialParent = nullptr;

		if (ContentSelectedMaterials.Num() > 0 || this->BaseMaterialForInstance != nullptr)
		{

			if (BaseMaterialForInstance == nullptr)
			{
				for (UMaterial* material : ContentSelectedMaterials)
				{
					PackageName = material->GetPathName();
					Factory->InitialParent = material;
				}
			}
			else
			{
				PackageName = this->BaseMaterialForInstance->GetPathName();
				Factory->InitialParent = this->BaseMaterialForInstance;
			}
			
			if (GEditor->GetSelectedActors()->Num() > 0)
			{
				FSelectionIterator it = GEditor->GetSelectedActorIterator();
				for (it; it; ++it)
				{
					AActor *act = Cast<AActor>(*it);
					UE_LOG(LogTemp, Display, TEXT("Actor %s "), *act->GetName());
			
						
					FString NewFolder = FPaths::GetPath(PackageName);
		
					FString FullPath = FPaths::GameContentDir()+"MaterialInstanceFolder";
					
					FString FullPath2 = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*FullPath);

					FullPath = "/Game/MaterialInstanceFolder/" + act->GetHumanReadableName();

					if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(act))
					{
						

						if (SkelMeshActor && SkelMeshActor->GetSkeletalMeshComponent())
						{
						
							FString PathToObject = SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->GetPathName();

							uint32 materialCounter = 0;
							FString directory = FPackageName::GetLongPackagePath(PackageName);// SkelMeshActor->GetPathName(); //.ToString();
							FStringAssetReference ThePath = FStringAssetReference(act);


							for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
							{
								
								UMaterial* material = m.MaterialInterface->GetMaterial();
								Name = material->GetName();
								
								UTexture* Texture = material->BaseColor.Expression->GetReferencedTexture();

								SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, nullptr);
								FullPath = SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->GetPathName();

								Name = SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->GetExporterName().ToString();

								Name = SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->GetFullName();

								 SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->AppendName(Name);

								FullPath.RemoveFromEnd(SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->GetFName().ToString());



								UMaterialInstanceConstant* instance = CreateAssetByParentMaterial(material, Factory, &FullPath, &Name);

								if (instance != nullptr)
									SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, instance);
								else
									SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, material);

								materialCounter++;
							}
						}
					}
					else
					{
						// actor's component materials storage, reset per iteration
						TArray<UMaterialInterface*> compMaterials;
						// actor meshes storage
						TArray<UStaticMeshComponent*> actorComponents;
						// getting meshes from actor
						act->GetComponents<UStaticMeshComponent>(actorComponents);
						UE_LOG(LogTemp, Display, TEXT("contains %d components\n"), actorComponents.Num());


						// get materials from each component and add to a TSet
						for (auto component : actorComponents)
						{
							compMaterials.Reset();
							component->GetUsedMaterials(compMaterials);
							uint32 materialCounter = 0;
							for (auto materialInterface : compMaterials)
							{
								UMaterial* material = materialInterface->GetMaterial();
								Name = material->GetName();

								UMaterialInstanceConstant* instance = CreateAssetByParentMaterial(material, Factory, &FullPath, &Name);

								if (instance != nullptr)
									component->SetMaterial(materialCounter, instance);
								materialCounter++;
							}
						}
					}

					count++;
				}
			}
			else
			UMaterialTools::NotificationBox(FString("Select Actor in Viewport"));
		}
		else
			UMaterialTools::NotificationBox(FString("Select Base Material in Plugin or Content browser"));
	
}


TSet<UMaterial*> UMaterialTools::GetSelectedActorMaterials()
{
	TSet<UMaterial*> outMaterials;

	FSelectionIterator it = GEditor->GetSelectedActorIterator();
	for (it; it; ++it)
	{
		AActor *act = Cast<AActor>(*it);
		UE_LOG(LogTemp, Display, TEXT("Actor %s "), *act->GetName());
		if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(act))
		{
			if (SkelMeshActor && SkelMeshActor->GetSkeletalMeshComponent())
			{
				for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
				{
					auto material = m.MaterialInterface->GetMaterial();
					outMaterials.Add(material);
				}
				UE_LOG(LogTemp, Display, TEXT("%d materials collected\n"), SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials.Num());
			}
		}
		else
		{
			// actor's component materials storage, reset per iteration
			TArray<UMaterialInterface*> compMaterials;
			// actor meshes storage
			TArray<UStaticMeshComponent*> actorComponents;
			// getting meshes from actor
			act->GetComponents<UStaticMeshComponent>(actorComponents);
			UE_LOG(LogTemp, Display, TEXT("contains %d components\n"), actorComponents.Num());

			// get materials from each component and add to a TSet
			for (auto c : actorComponents)
			{
				compMaterials.Reset();
				c->GetUsedMaterials(compMaterials);
				for (auto m : compMaterials)
					outMaterials.Add(m->GetMaterial());
			}
			UE_LOG(LogTemp, Display, TEXT("%d materials collected\n"), outMaterials.Num());
		}
	}
	return outMaterials;
}

UMaterialInstanceConstant*  UMaterialTools::CreateAssetByParentMaterial(UMaterial* ParentMaterial , UMaterialInstanceConstantFactoryNew* Factory,  FString* PathToAsset , FString* AssetName)
{
	
	/*FString RelativePath = FPaths::GameContentDir();

	FString FullPathName = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*RelativePath) + FString("MaterialInstanceFolder/") + act->GetHumanReadableName() + FString("/") + *AssetName + FString("_Instance.uasset");


	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*FullPathName))

		UMaterialTools::NotificationBox(FString("Deleted Files "));
	bool deleted = FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*FullPathName);

	if (deleted)
		UMaterialTools::NotificationBox(FString("Created New Files "));
	*/

	FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
	UObject* NewAsset = AssetToolsModule.Get().CreateAsset(*AssetName + "_Instance", *PathToAsset, UMaterialInstanceConstant::StaticClass(), Factory);

	if (NewAsset != nullptr)
	{
		UMaterialInstanceConstant* instance = (UMaterialInstanceConstant*)NewAsset;
		if (ParentMaterial->BaseColor.Expression != nullptr)
		{
			UTexture* Texture = ParentMaterial->BaseColor.Expression->GetReferencedTexture();
			instance->SetTextureParameterValueEditorOnly("Texture", Texture);
		}
		return instance;
	}
	else
		return nullptr;
}

TSet<UMaterial*> UMaterialTools::GetSelectedMaterialsInContentBrowser()
{
	TSet<UMaterial*> outMaterials;
	TArray<FAssetData> selections;
	GEditor->GetContentBrowserSelections(selections);
	for (auto i : selections)
	{

		if (i.GetAsset()->IsA(UMaterial::StaticClass()))
		{
			UMaterial* material = Cast<UMaterial>(i.GetAsset());
			outMaterials.Add(material);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("%d materials collected\n"), outMaterials.Num());
	return outMaterials;
}


#undef LOCTEXT_NAMESPACE