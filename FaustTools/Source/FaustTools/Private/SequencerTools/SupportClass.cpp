#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "SupportClass.h"
#include "AssetRegistryModule.h"

//Sequencer
#include "LevelSequence.h"
#include "MovieScene.h"
#include "MovieSceneCommonHelpers.h"
#include "MovieScene3DTransformSection.h"
#include "MovieScene3DTransformTrack.h"
#include "MovieSceneFloatSection.h"
#include "MovieSceneFloatTrack.h"

// Notifications
#include "NotificationManager.h"
#include "SNotificationList.h"
#include "Editor/PackagesDialog/Public/PackagesDialog.h"

#define LOCTEXT_NAMESPACE "SupportFunctions"

UMovieScene3DTransformSection* USupport::GetTransformSectionFromActor(ULevelSequence *LevelSequence, AActor *Actor)
{
	UMovieScene3DTransformSection *TransformSection = nullptr;
#if WITH_EDITOR
	if (Actor != nullptr && LevelSequence != nullptr)
	{
		for (auto b : LevelSequence->GetMovieScene()->GetBindings())
		{
			FGuid Guid = b.GetObjectGuid();
			if (Guid.IsValid())
			{
				UObject * Object = LevelSequence->FindPossessableObject(Guid, GWorld);
				if (Object != nullptr)
				{
					if (Actor == Object)
					{
						if (b.GetTracks().Num())
						{
							UMovieSceneTrack *MovieSceneTrack = b.GetTracks()[0];
							if (MovieSceneTrack->GetAllSections().Num())
							{
								UMovieSceneSection *SceneSection = MovieSceneTrack->GetAllSections()[0];
								TransformSection = Cast<UMovieScene3DTransformSection>(SceneSection);
							}
						}
						return TransformSection;
					}
				}
			}
		}
	}
#endif
	return TransformSection;
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

void USupport::GetAssetsByClass(UClass *Class, TArray<UObject*> &Objects)
{
#if WITH_EDITOR
	if (Class != nullptr)
	{
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		TArray<FAssetData> AssetData;
		FString ClassName = Class->GetName();
		AssetRegistryModule.Get().GetAssetsByClass(FName(*ClassName), AssetData);
		for (int32 i = 0; i < AssetData.Num(); i++) Objects.Add(AssetData[i].GetAsset());
	}
#endif
}

void USupport::NotificationBox(FString String, float FadeIn, float Expire, float FadeOut, bool bOutputLog)
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

#undef LOCTEXT_NAMESPACE