#pragma once

#include "Engine.h"
#include "FaustToolsBaseClass.h"
//#include "Scaling.generated.h"
class UMovieScene3DTransformSection;
//UCLASS()
class UScale //: public UObject
{
	//GENERATED_BODY()
public:
	void ScaleTop(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta);
	void ScaleBot(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta);
	void ScaleLeft(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta, bool bScaleCapturedOnly);
	void ScaleRight(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta, bool bScaleCapturedOnly);
	void MoveHorizontal(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta);
	void MoveVertical(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta);
};