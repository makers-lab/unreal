#pragma once

#include "Engine.h"
#include "FaustToolsBaseClass.h"
//#include "Scaling.generated.h"
class UMovieScene3DTransformSection;
enum TransformType;
//UCLASS()
class UScale //: public UObject
{
	//GENERATED_BODY()
public:
	void ScaleTop(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float MaxValue, float MinValue, float Delta);
	void ScaleBot(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float MaxValue, float MinValue, float Delta);
	void ScaleLeft(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float MaxValue, float MinValue, float Delta, bool bScaleCapturedOnly);
	void ScaleRight(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float MaxValue, float MinValue, float Delta, bool bScaleCapturedOnly);
	void MoveHorizontal(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, TMap<EAxis::Type, TArray<float>>& TimesToEdit, float Delta);
	void MoveVertical(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, TMap<EAxis::Type, TArray<float>>& TimesToEdit, float Delta);
};