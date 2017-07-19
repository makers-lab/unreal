#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "USequencerTools.h"
#include "Scaling.h"
#include "SupportClass.h"


USequencerTools::USequencerTools()
{
	ScaleTopValue = 1.f;
	OldScaleTopValue = ScaleTopValue;
	ScaleBotValue = 1.f;
	OldScaleBotValue = ScaleBotValue;
	ScaleLeftValue = 1.f;
	OldScaleLeftValue = ScaleLeftValue;
	ScaleRightValue = 1.f;
	OldScaleRightValue = ScaleRightValue;

	Scaling = MakeShared<Scale>();
}

void USequencerTools::PreEditChange(UProperty* PropertyAboutToChange)
{

}

void USequencerTools::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UProperty *PropertyThatChanged = PropertyChangedEvent.Property;
	if (PropertyThatChanged)
	{
		if (PropertyThatChanged->GetName() == "FromFrame")
		{
			FromFrame = FromFrame;
		}
		if (PropertyThatChanged->GetName() == "ToFrame")
		{
			ToFrame = ToFrame;
		}

		if (PropertyThatChanged->GetName() == "bScaleCapturedRange")
		{
			bScaleCapturedRange = bScaleCapturedRange;
		}
		if (PropertyThatChanged->GetName() == "ScaleTopValue")
		{
			float Delta = OldScaleTopValue - ScaleTopValue;
			Scaling->ScaleTop(ValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleTopValue = ScaleTopValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleBotValue")
		{
			float Delta = OldScaleBotValue - ScaleBotValue;
			Scaling->ScaleBot(ValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleBotValue = ScaleBotValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleLeftValue")
		{
			float Delta = OldScaleLeftValue - ScaleLeftValue;
			Scaling->ScaleLeft(ValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleLeftValue = ScaleLeftValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleRightValue")
		{
			float Delta = OldScaleRightValue - ScaleRightValue;
			Scaling->ScaleRight(ValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleRightValue = ScaleRightValue;
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void USequencerTools::OnToolClosed()
{

}

void USequencerTools::CaptureRange()
{
	ULevelSequence * Sequencer = Cast<ULevelSequence>(USupport::GetAssetWithOpenedEditor(ULevelSequence::StaticClass()));
}

void USequencerTools::ResetCapture()
{

}