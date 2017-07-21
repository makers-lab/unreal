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
	void ScaleTop(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float& MaxValue, float& MinValue, float Delta, TArray<float>& KeysValuesToSort);
	void ScaleBot(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float& MaxValue, float& MinValue, float Delta, TArray<float>& KeysValuesToSort);
	void ScaleLeft(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform& Transform, float& MaxTime, float& MinTime, float Delta, TArray<float>& KeysTimesToSort, bool bScaleCapturedOnly);
	void ScaleRight(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform& Transform, float& MaxTime, float& MinTime, float Delta, TArray<float>& KeysTimesToSort, bool bScaleCapturedOnly);
};