#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "USequencerTools.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"

USequencerTools::USequencerTools()
{
}

void USequencerTools::PreEditChange(UProperty* PropertyAboutToChange)
{

}

void USequencerTools::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	
}

void USequencerTools::OnToolClosed()
{

}

void USequencerTools::CaptureRange()
{
		TSet<UMaterial*> ContentSelectedMaterials = GetSelectedMaterialsInContentBrowser();
		TSet<UMaterial*> ActorSelectedMaterials = GetSelectedActorMaterials();



		UMaterial* BaseMaterial = LoadObject<UMaterial>(NULL, TEXT("/Engine/EngineMaterials/BaseFlattenMaterial.BaseFlattenMaterial"), NULL, LOAD_None, NULL);
		check(BaseMaterial);

		const FString DefaultSuffix = TEXT("_Inst");


		// Create an appropriate and unique name 
		FString Name;
		FString PackageName;
		FString CurrentInstanceName;
		FString InstanceName;

		int32 count = 0;

		GEditor->GetSelectedActors();


		UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
		Factory->InitialParent = nullptr;

		for (UMaterial* material : ContentSelectedMaterials)
		{

			PackageName = material->GetPathName();
			Factory->InitialParent = material;
		}



		FSelectionIterator it = GEditor->GetSelectedActorIterator();
		for (it; it; ++it)
		{
			AActor *act = Cast<AActor>(*it);
			UE_LOG(LogTemp, Display, TEXT("Actor %s "), *act->GetName());
			if (ASkeletalMeshActor* SkelMeshActor = Cast<ASkeletalMeshActor>(act))
			{
				if (SkelMeshActor && SkelMeshActor->GetSkeletalMeshComponent())
				{
					uint32 materialCounter = 0;


					for (auto m : SkelMeshActor->GetSkeletalMeshComponent()->SkeletalMesh->Materials)
					{
						auto material = m.MaterialInterface->GetMaterial();
						
						
				
						Name = material->GetName();

						auto Texture = material->BaseColor.Expression->GetReferencedTexture();

						FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
						UObject* NewAsset = AssetToolsModule.Get().CreateAsset(Name + "_Instance" + FString::FromInt(count), FPackageName::GetLongPackagePath(PackageName), UMaterialInstanceConstant::StaticClass(), Factory);

						UMaterialInstanceConstant* instance = (UMaterialInstanceConstant*)NewAsset;

						instance->SetTextureParameterValueEditorOnly("Texture", Texture);


						SkelMeshActor->GetSkeletalMeshComponent()->SetMaterial(materialCounter, instance);


						materialCounter++;
						//outMaterials.Add(material);
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
					uint32 materialCounter = 0;
					for (auto materialInterface : compMaterials)
					{

						UMaterial* material = materialInterface->GetMaterial();
						Name = material->GetName();
						


						FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
						UObject* NewAsset = AssetToolsModule.Get().CreateAsset(Name + "_Instance" + FString::FromInt(count), FPackageName::GetLongPackagePath(PackageName), UMaterialInstanceConstant::StaticClass(), Factory);

						UMaterialInstanceConstant* instance = (UMaterialInstanceConstant*)NewAsset;
						if (material->BaseColor.Expression != nullptr)
						{
							auto Texture = material->BaseColor.Expression->GetReferencedTexture();
							instance->SetTextureParameterValueEditorOnly("Texture", Texture);
						}

						c->SetMaterial(materialCounter, instance);

						materialCounter++;
					}

				}
			}

			count++;
		}




		//if (Factory->InitialParent != nullptr)
		//for (auto actorMaterials : ActorSelectedMaterials)
		//{


		//				auto Texture = actorMaterials->BaseColor.Expression->GetReferencedTexture();
	
		//				//UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
		//				//Factory->InitialParent = BaseMaterial;// (UMaterial*)DynMaterial;
		//				FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
		//				UObject* NewAsset = AssetToolsModule.Get().CreateAsset(Name+"_Instance"+ FString::FromInt(count) , FPackageName::GetLongPackagePath(PackageName), UMaterialInstanceConstant::StaticClass(), Factory);
		//					
		//				UMaterialInstanceConstant* instance = (UMaterialInstanceConstant*)NewAsset;
		//				
		//				instance->SetTextureParameterValueEditorOnly("Texture", Texture);
		//	
		//				
		//				
		//				
		//				
		//				
		//				count++;
		//}





		//if (ContentSelectedMaterials->Contains())
		//{
		//UE_LOG(LogTemp, Display, TEXT("contains %d components\n"), actorComponents.Num());

		/*	CurrentInstanceName = FPackageName::GetLongPackagePath(PackageName) + Name + actorMaterials->GetName() + "_Ins";
		InstanceName = Name + actorMaterials->GetName() + "_Ins";
		FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		ContentBrowserModule.Get().CreateNewAsset(Name+ actorMaterials->GetName() + "_Ins", FPackageName::GetLongPackagePath(PackageName), UMaterialInstanceConstant::StaticClass(), Factory);

		ContentBrowserModule.ShutdownModule();
		ContentBrowserModule.StartupModule();*/

		//SetMaterial(0, DynamicMaterial);

		/*CurrentInstanceName = FPackageName::GetLongPackagePath(PackageName) + Name + actorMaterials->GetName() + "_Ins";
		InstanceName = Name + actorMaterials->GetName() + "_Ins";
		FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		ContentBrowserModule.Get().CreateNewAsset(Name+ actorMaterials->GetName() + "_Ins", FPackageName::GetLongPackagePath(PackageName), UMaterialInstanceConstant::StaticClass(), FactoryDyn);

		ContentBrowserModule.ShutdownModule();
		ContentBrowserModule.StartupModule();
		*/

		//actorMaterials[0].GetUsedTexturesAndIndices
		//DynMaterial->Se
		//UMaterialInstanceConstant * cloudMaterialPtr = ConstructorHelpers::FObjectFinderOptional<UMaterialInstanceConstant>((TEXT("MaterialInstanceConstant %s"), CurrentInstanceName)).Get();
		//	ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> BaseMaterial(*CurrentInstanceName);

		//	UMaterialInstanceConstant* Instance = LoadObject<UMaterialInstanceConstant>(NULL, *CurrentInstanceName, NULL, LOAD_None, NULL);
		//	check(Instance);

		//	UObject* 	Parent = FindPackage(NULL, *PackageName);
		//	UObject* NewAsset = FindObject<UObject>(Parent, *InstanceName, false);
		//	if (NewAsset)
		//	{
		//		TArray<UObject*> NewAssets;
		//		NewAssets.Add(NewAsset);
		//	}

		////	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> ObjectFinder(FObjectFinder);
		//	check(NewAsset);
		//	

		//UE_LOG(LogTemp, Warning, TEXT(" MATERIAL INSTANCE LOADED %s\n"), CurrentInstanceName);


		/*if (cloudMaterialPtr != nullptr)
		{

		}
		else
		{
		UE_LOG(LogTemp, Warning, TEXT(" MATERIAL INSTANCE FAILED %s\n"), CurrentInstanceName);
		}*/
		/*			if(Factory->CanCreateNew())
		ContentBrowserModule.Get().CreateNewAsset(Name + actorMaterials->GetName() + "_Ins2", FPackageName::GetLongPackagePath(PackageName), UMaterialInstanceConstant::StaticClass(), Factory);
		*/					//}


		//FString Name;
		//FString PackagePath;
		//CreateUniqueAssetName(Object->GetOutermost()->GetName(), DefaultSuffix, PackagePath, Name);



		//	auto mat = INST->GetBaseMaterial();
		//auto mat2 = INST->GetBaseMaterial();

		/*		for (auto material : ActorSelectedMaterials)
		{
		material = mat;

		*/
		//FSelectionIterator it = GEditor->GetSelectedActorIterator();
		//for (it; it; ++it)
		//{
		//	AActor *act = Cast<AActor>(*it);
		//	UE_LOG(LogTemp, Display, TEXT("Actor %s "), *act->GetName());
		//	if (act->IsValidLowLevel())
		//	{
		//		act->Tick(0.f);
		//	}

		//}


	
}


void USequencerTools::ResetCapture()
{
	Location = true;
}



TSet<UMaterial*> USequencerTools::GetSelectedActorMaterials()
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


TSet<UMaterial*> USequencerTools::GetSelectedMaterialsInContentBrowser()
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