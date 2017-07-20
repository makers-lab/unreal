#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "Scaling.h"
#include "MovieScene3DTransformSection.h"


void UScale::ScaleTop(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta)
{
	_LOG("%s",*TransformSection->GetName());
}

void UScale::ScaleBot(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta)
{
	_LOG("%s", *TransformSection->GetName());
}

void UScale::ScaleLeft(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta, bool bScaleCapturedOnly)
{
	_LOG("%s", *TransformSection->GetName());
}

void UScale::ScaleRight(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta, bool bScaleCapturedOnly)
{
	_LOG("%s", *TransformSection->GetName());
}

void UScale::MoveHorizontal(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta)
{
	_LOG("%s", *TransformSection->GetName());
}

void UScale::MoveVertical(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float Delta)
{
	_LOG("%s", *TransformSection->GetName());
}
