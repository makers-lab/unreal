#pragma once

#include "Engine.h"
#include "Filters.generated.h"

class UMovieScene3DTransformSection;

UCLASS()
class UFilters : public UObject
{
	GENERATED_BODY()
public:
	static void Butterworth(TransformType Type, EAxis::Type Axis, UMovieScene3DTransformSection* TransformSection, TArray<FKeyHandle> CurveHandles, float CutOff);
	static void FilterKeys(TransformType Type, EAxis::Type Axis, UMovieScene3DTransformSection* TransformSection, TArray<FKeyHandle> CurveHandles, float Delta);

private:
	static void CurveCorrection(float DeltaTimeInSeconds, TArray<float> &ValuesToEdit, float CutOff);
	static void KeysCorrection(TArray<float> &ValuesToEdit, float Delta);
};