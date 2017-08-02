#pragma once

#include "Engine.h"
#include "SupportClass.generated.h"

class UMovieScene3DTransformSection;
class ULevelSequence;

UCLASS()
class USupport : public UObject
{
	GENERATED_BODY()
public:
	static UMovieScene3DTransformSection* GetTransformSectionFromActor(ULevelSequence *LevelSequence, AActor *Actor);
	static UObject* GetAssetWithOpenedEditor(UClass *Class);
	static void GetAssetsByClass(UClass *Class, TArray<UObject*> &Objects);
	static void NotificationBox(FString String, float FadeIn = 0.1f, float Expire = 1.5, float FadeOut = 1.2f, bool bOutputLog = true);
};