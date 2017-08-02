#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "UMaterialTools.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "NotificationManager.h"
#include "SNotificationList.h"
#include "SContentReference.h"

#define LOCTEXT_NAMESPACE "UMaterialTools"

FActorInstance::FActorInstance():mActor(nullptr), mMaterial(nullptr), mMaterialD(0)
{
}

FActorInstance::FActorInstance(AActor* Actor, UMaterialInterface* Material, int32 MaterialD): mActor(Actor),mMaterial(Material),mMaterialD(MaterialD)
{
}

UMaterialTools::UMaterialTools()
{
}


UTexture* UMaterialTools::GetTextureFromBaseMaterialNode(UMaterialInterface* material)
{
	UMaterial* mat  =  (UMaterial*)material;
	if (mat != nullptr)
	{
		if (mat->BaseColor.Expression != nullptr)
			return mat->BaseColor.Expression->GetReferencedTexture();
	} 
		return nullptr;
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
		InstanceList.Empty();
		TArray<FActorInstance> ActorsMaterials;
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

			//for (TActorIterator<AActor*> ActorItr(GetWorld()); ActorItr; ++ActorItr)
			//{

			//	AActor *act = Cast<AActor>(*ActorItr);

			//	if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(act))
			//	{
			//		if (SkelMeshActor && SkelMeshActor->GetSkeletalMeshComponent())
			//		{
			//			uint32 materialCounter = 0;

			//			for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
			//			{
			//				UMaterial* material = m.MaterialInterface->GetMaterial();
			//				ActorsMaterials.Add(FActorInstance(act, material, materialCounter));
			//				SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, nullptr);
			//				materialCounter++;
			//			}
			//		}
			//	}
			//}

			
			GEditor->BeginTransaction(FText::FromString("Reset skeletal actros material"));

			for (TObjectIterator<AActor> Itr; Itr; ++Itr)
			{
				// Filter out objects not contained in the target world.
					AActor *act = Cast<AActor>(*Itr);

					if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(act))
					{
						if (SkelMeshActor && SkelMeshActor->GetSkeletalMeshComponent())
						{
							uint32 materialCounter = 0;
							if(SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh != nullptr)
							for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
							{
							
								UMaterial* material = m.MaterialInterface->GetMaterial();
								ActorsMaterials.Add(FActorInstance(act, material, materialCounter));
								SkelMeshActor->GetSkeletalMeshComponent()->Modify();
								SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, nullptr);
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
										uint32 materialCounter = 0;
										for (auto materialInterface : compMaterials)
										{
										
											UMaterial* material = materialInterface->GetMaterial();
											ActorsMaterials.Add(FActorInstance(act, material, materialCounter));
											component->Modify();
											component->SetMaterial(materialCounter, nullptr);
											materialCounter++;
										
										}
									}
					
					}
			// Do stuff
			}
			GEditor->EndTransaction();


			/*	for (TActorIterator<AActor> Itr(GEditor->GetWorld()); Itr; ++Itr)
				{
					AActor *act = Cast<AActor>(*Itr);

					if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(act))
					{
						if (SkelMeshActor && SkelMeshActor->GetSkeletalMeshComponent())
						{
							uint32 materialCounter = 0;

							for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
							{
								UMaterial* material = m.MaterialInterface->GetMaterial();
								ActorsMaterials.Add(FActorInstance(act, material, materialCounter));
								SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, nullptr);
								materialCounter++;
							}
						}
					}
				}*/

			if (GEditor->GetSelectedActors()->Num() > 0)
			{
				//FSelectionIterator itSaveMaterials = GEditor->GetSelectedActorIterator();

				//for (itSaveMaterials; itSaveMaterials; ++itSaveMaterials)
				//{
				//	AActor *act = Cast<AActor>(*itSaveMaterials);

				//	if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(act))
				//	{
				//		if (SkelMeshActor && SkelMeshActor->GetSkeletalMeshComponent())
				//		{
				//			uint32 materialCounter = 0;

				//			for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
				//			{
				//				UMaterial* material = m.MaterialInterface->GetMaterial();
				//				ActorsMaterials.Add(FActorInstance(act, material, materialCounter));
				//				SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, nullptr);
				//				materialCounter++;
				//			}
				//		}
				//	}
				//	else
				//	{
				//		// actor's component materials storage, reset per iteration
				//		TArray<UMaterialInterface*> compMaterials;
				//		// actor meshes storage
				//		TArray<UStaticMeshComponent*> actorComponents;
				//		// getting meshes from actor
				//		act->GetComponents<UStaticMeshComponent>(actorComponents);
				//		UE_LOG(LogTemp, Display, TEXT("contains %d components\n"), actorComponents.Num());


				//		// get materials from each component and add to a TSet
				//		for (auto component : actorComponents)
				//		{
				//			uint32 materialCounter = 0;
				//			for (auto materialInterface : compMaterials)
				//			{
				//				UMaterial* material = materialInterface->GetMaterial();
				//				ActorsMaterials.Add(FActorInstance(act, material, materialCounter));
				//				component->SetMaterial(materialCounter, nullptr);
				//				materialCounter++;
				//			}
				//		}
				//	}
				//}

				FSelectionIterator it = GEditor->GetSelectedActorIterator();

				GEditor->BeginTransaction(FText::FromString("Set actros material"));
				for (it; it; ++it)
				{
					AActor *act = Cast<AActor>(*it);
					UE_LOG(LogTemp, Display, TEXT("Actor %s "), *act->GetName());
	
					FString FullPath;




					if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(act))
					{
						

						if (SkelMeshActor && SkelMeshActor->GetSkeletalMeshComponent())
						{
						
							FString PathToObject = SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->GetPathName();

							uint32 materialCounter = 0;
							FString directory = FPackageName::GetLongPackagePath(PackageName);// SkelMeshActor->GetPathName(); //.ToString();
							FStringAssetReference ThePath = FStringAssetReference(act);

							//for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
							//{
							//	UMaterial* material = m.MaterialInterface->GetMaterial();
							//	ActorsMaterials.Add(FActorInstance(act, material, materialCounter));
							//	SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, nullptr);
							//	materialCounter++;
							//}

							//	materialCounter = 0;

							for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
							{
								UTexture* Texture = nullptr;
								UMaterial* material = m.MaterialInterface->GetMaterial();
								Name = material->GetName();
								if(material->BaseColor.Expression != nullptr)
								Texture = material->BaseColor.Expression->GetReferencedTexture();
								//SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, nullptr);
								FullPath = SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->GetPathName();

								int32 pointer = 0;
								FullPath.FindLastChar('/', pointer);
								auto size = FullPath.GetAllocatedSize();
								auto FullPathArray = FullPath.GetCharArray();
								FullPath.RemoveAt(++pointer, FullPathArray.Num() - pointer, true);

								UMaterialInstanceConstant* instance = CreateAssetByParentMaterial(material, Factory, &FullPath, &Name);

								if (instance != nullptr)
									ActorsMaterials.Add(FActorInstance(act, instance, materialCounter));
									
								FString PathToAsset = instance->GetPathName();

								for (auto actorMaterialToSet : ActorsMaterials)
								{
								
									if (PathToAsset == actorMaterialToSet.mMaterial->GetPathName())
										actorMaterialToSet.mMaterial = instance;
								}
								//	SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, instance);
								//else
								//	SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, material);
								materialCounter++;
							}

							for (auto actorMaterialToSet : ActorsMaterials)
							{
								if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(actorMaterialToSet.mActor))
								{
									if (actorMaterialToSet.mMaterial != nullptr)
									{
									
										SkelMeshActor->GetSkeletalMeshComponent()->Modify();
										SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(actorMaterialToSet.mMaterialD, actorMaterialToSet.mMaterial);
										
									}
									else
										UMaterialTools::NotificationBox(FString("Material to set null ptr"));
								}
							}

						
							//for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
							//{
							//	UMaterial* material = m.MaterialInterface->GetMaterial();
							//	ActorsMaterials.Add(FActorInstance(act, material, materialCounter));
							//	SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, nullptr);
							//	materialCounter++;
							//}


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

							FullPath = component->StaticMesh->GetPathName();

							int32 pointer = 0;
							FullPath.FindLastChar('/', pointer);
							//pointer = FullPath.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd,20);
							auto size = FullPath.GetAllocatedSize();
							auto FullPathArray = FullPath.GetCharArray();
							
							FullPath.RemoveAt(++pointer, FullPathArray.Num() - pointer, true);


							for (auto materialInterface : compMaterials)
							{
								UMaterial* material = materialInterface->GetMaterial();
								Name = material->GetName();

								UMaterialInstanceConstant* instance = CreateAssetByParentMaterial(material, Factory, &FullPath, &Name);
								if (instance != nullptr)
								{
									component->Modify();
									component->SetMaterial(materialCounter, instance);
								}
								materialCounter++;
							}
						}
					}

					count++;
				}
				GEditor->EndTransaction();
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


	PathToAsset->Append("/MaterialInstance");
	AssetName->Append("_Instance");
	FString AbsoluteDirPath = FPaths::GameContentDir();

	FString RelativePath = *PathToAsset;
  
	 int32 pointer = RelativePath.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromStart, 1);

	//pointer = FullPath.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd,20);

	 RelativePath.RemoveAt(0, pointer+1, true);

	 AbsoluteDirPath.Append(RelativePath);

	FString FullPathName = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*AbsoluteDirPath)+"/"+ *AssetName + FString(".uasset");


	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*FullPathName))
	bool deleted = FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*FullPathName);


	FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");

	UMaterialInstanceConstant** KeyExist = nullptr;
	KeyExist = InstanceList.Find(FullPathName);

	if (KeyExist == nullptr)
	{
		UObject* NewAsset = AssetToolsModule.Get().CreateAsset(*AssetName, *PathToAsset, UMaterialInstanceConstant::StaticClass(), Factory);


		if (NewAsset != nullptr)
		{
			UMaterialInstanceConstant* instance = (UMaterialInstanceConstant*)NewAsset;
			if (ParentMaterial->BaseColor.Expression != nullptr)
			{
				UTexture* Texture = ParentMaterial->BaseColor.Expression->GetReferencedTexture();
				instance->SetTextureParameterValueEditorOnly("Texture", Texture);
			}

			InstanceList.Add(FullPathName, instance);

			return instance;
		}
		else
			return nullptr;
	}
	else
		return *KeyExist;
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