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
	MoveHorizontalValue = 1.f;
	OldMoveHorizontalValue = MoveHorizontalValue;
	MoveVerticalValue = 1.f;
	OldMoveVerticalValue = MoveVerticalValue;
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
			Scale->ScaleTop(TransformSection, CurvesValuesToEdit, Delta);
			OldScaleTopValue = ScaleTopValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleBotValue")
		{
			float Delta = OldScaleBotValue - ScaleBotValue;
			Scale->ScaleBot(TransformSection, CurvesValuesToEdit, Delta);
			OldScaleBotValue = ScaleBotValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleLeftValue")
		{
			float Delta = OldScaleLeftValue - ScaleLeftValue;
			Scale->ScaleLeft(TransformSection, CurvesValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleLeftValue = ScaleLeftValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleRightValue")
		{
			float Delta = OldScaleRightValue - ScaleRightValue;
			Scale->ScaleRight(TransformSection, CurvesValuesToEdit, Delta, bScaleCapturedRange);
			OldScaleRightValue = ScaleRightValue;
		}

		if (PropertyThatChanged->GetName() == "MoveHorizontalValue")
		{
			float Delta = OldMoveHorizontalValue - MoveHorizontalValue;
			Scale->MoveHorizontal(TransformSection, CurvesValuesToEdit, Delta);
			OldMoveHorizontalValue = MoveHorizontalValue;
		}
		if (PropertyThatChanged->GetName() == "MoveVerticalValue")
		{
			float Delta = OldMoveVerticalValue - MoveVerticalValue;
			Scale->MoveVertical(TransformSection, CurvesValuesToEdit, Delta);
			OldMoveVerticalValue = MoveVerticalValue;
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void USequencerTools::OnToolClosed()
{

}

void USequencerTools::CaptureRange()
{
	ResetCapture();
	Sequencer = Cast<ULevelSequence>(USupport::GetAssetWithOpenedEditor(ULevelSequence::StaticClass()));
	if (Sequencer->IsValidLowLevel())
	{
		FSelectionIterator Sel = GEditor->GetSelectedActorIterator();
		for (Sel; Sel; ++Sel)
		{
			AActor * SelActor = Cast<AActor >(*Sel);
			if (SelActor->IsValidLowLevel())
			{
				TransformSection = USupport::GetTransformSectionFromActor(Sequencer, SelActor);
				if (TransformSection->IsValidLowLevel())
				{
					GEditor->BeginTransaction(FText::FromString("Capture Range"));

					TransformSection->TryModify();
					float Step = Sequencer->GetMovieScene()->GetFixedFrameInterval();
					float MaxTime = TransformSection->GetEndTime() + Step;
					float Frames = FMath::RoundToFloat(MaxTime / Step);
					
					float P1 = FromFrame / Frames * 100;
					float FromTime = MaxTime / 100 * P1;
 
					float P2 = ToFrame / Frames * 100;
					float ToTime = MaxTime / 100 * P2;
					
					
					for (auto Type : TransformTypes)
					{
						if (Type == TransformType::Loc)
						{
							for (auto Axis : Axises)
							{
								GetValuesAndTimesToEditFromCurve(TransformSection->GetTranslationCurve(Axis), FromTime, ToTime, ValuesToEdit, TimesToEdit);
								CurvesValuesToEdit.Add(Axis, ValuesToEdit);
								CurvesTimesToEdit.Add(Axis, TimesToEdit);
							}
						}

						if (Type == TransformType::Rot)
						{
							for (auto Axis : Axises)
							{
								GetValuesAndTimesToEditFromCurve(TransformSection->GetTranslationCurve(Axis), FromTime, ToTime, ValuesToEdit, TimesToEdit);
								CurvesValuesToEdit.Add(Axis, ValuesToEdit);
								CurvesTimesToEdit.Add(Axis, TimesToEdit);
							}
						}

						if (Type == TransformType::Sca)
						{
							for (auto Axis : Axises)
							{
								GetValuesAndTimesToEditFromCurve(TransformSection->GetTranslationCurve(Axis), FromTime, ToTime, ValuesToEdit, TimesToEdit);
								CurvesValuesToEdit.Add(Axis, ValuesToEdit);
								CurvesTimesToEdit.Add(Axis, TimesToEdit);
							}
						}
					}
					GEditor->EndTransaction();
				}
			}
			else USupport::NotificationBox(FString("Select an Actor in Level Sequence"));
		}
	}
	else USupport::NotificationBox(FString("Open Level Sequence Editor to work with"));
}

void USequencerTools::ResetCapture()
{
	ValuesToEdit.Empty();
	TimesToEdit.Empty();
	CurvesTimesToEdit.Empty();
	CurvesValuesToEdit.Empty();
	TransformTypes.Empty();
	Axises.Empty();
}

void USequencerTools::GetValuesAndTimesToEditFromCurve(FRichCurve Curve, float FromTime, float ToTime, TArray<float>& OutValues, TArray<float>& OutTimes)
{
	OutTimes.Empty();
	OutValues.Empty();
	auto Keys = Curve.Keys;
	for (int32 Index = 0; Index < Keys.Num(); Index++)
	{
		if (Keys[Index].Time >= FromTime && Keys[Index].Time <= ToTime)
		{
			OutTimes.Add(Keys[Index].Time);
			OutValues.Add(Keys[Index].Value);
		}
	}
}

void USequencerTools::GetTransformAndCurves(TArray<TransformType>& TransformTypes, TArray<EAxis::Type>& Axises)
{
	if (Location)
		TransformTypes.Add(TransformType::Loc);
	if (Rotation)
		TransformTypes.Add(TransformType::Rot);
	if (Scaling)
		TransformTypes.Add(TransformType::Sca);

	if (X)
		Axises.Add(EAxis::Type::X);
	if (Y)
		Axises.Add(EAxis::Type::Y);
	if (Z)
		Axises.Add(EAxis::Type::Z);
}
