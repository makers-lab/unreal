#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "SupportClass.h"



UMovieScene3DTransformSection* USupport::GetTransformSectionFromActor(ULevelSequence *LevelSequence, AActor *Actor)
{
	return new UMovieScene3DTransformSection();
}

UObject * USupport::GetAssetWithOpenedEditor(UClass *Class)
{
	UObject * ReturnAsset = nullptr;
#if WITH_EDITOR
	if (Class->IsValidLowLevel())
	{
		TArray <UObject*> Assets;
		GetAssetsByClass(Class, Assets);
		TArray <IAssetEditorInstance*> AssetEditorInstances;
		for (UObject *Asset : Assets)
		{
			IAssetEditorInstance *AssetEditorInstance = FAssetEditorManager::Get().FindEditorForAsset(Asset, true);
			if (AssetEditorInstance != nullptr) ReturnAsset = Asset;
		}
	}
#endif
	return ReturnAsset;
}