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

	Scale = MakeShared<UScale>();
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
			Scale->ScaleTop(ValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleTopValue = ScaleTopValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleBotValue")
		{
			float Delta = OldScaleBotValue - ScaleBotValue;
			Scale->ScaleBot(ValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleBotValue = ScaleBotValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleLeftValue")
		{
			float Delta = OldScaleLeftValue - ScaleLeftValue;
			Scale->ScaleLeft(ValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleLeftValue = ScaleLeftValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleRightValue")
		{
			float Delta = OldScaleRightValue - ScaleRightValue;
			Scale->ScaleRight(ValuesToEdit, Delta, bScaleCapturedRange);
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
	if (Sequencer->IsValidLowLevel())
	{
		FSelectionIterator Sel = GEditor->GetSelectedActorIterator();
		for (Sel; Sel; ++Sel)
		{
			AActor * SelActor = Cast<AActor >(*Sel);
			if (SelActor->IsValidLowLevel())
			{
				UMovieScene3DTransformSection * TransformSection = USupport::GetTransformSectionFromActor(Sequencer, SelActor);
				if (TransformSection->IsValidLowLevel())
				{
					GEditor->BeginTransaction(FText::FromString("Capture Range"));

					

					GEditor->EndTransaction();
				}
			}
		}
	}
	else USupport::NotificationBox(FString("Open Level Sequence Editor to work with!"));
}

void USequencerTools::ResetCapture()
{

}