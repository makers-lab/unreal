#pragma once

#include "Engine.h"
#include "../MovieSceneTracks/Public/Sections/MovieScene3DTransformSection.h"
#include "../LevelSequence/Public/LevelSequence.h"
#include "SupportClass.generated.h"


UCLASS()
class USupport : public UObject
{
	GENERATED_BODY()
public:
	static UMovieScene3DTransformSection* GetTransformSectionFromActor(ULevelSequence *LevelSequence, AActor *Actor);
	static UObject* GetAssetWithOpenedEditor(UClass *Class);


};