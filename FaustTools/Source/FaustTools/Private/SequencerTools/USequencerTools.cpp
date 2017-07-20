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
			for (auto Type : TransformTypes)
			{
				for (auto Axis : Axises)
				{
					Scale->ScaleTop(TransformSection, Type, Axis, TransformToEdit, MaxValue, MinValue, ScaleTopValue);
				}
			}
		}
		if (PropertyThatChanged->GetName() == "ScaleBotValue")
		{
			for (auto Type : TransformTypes)
			{
				for (auto Axis : Axises)
				{
					Scale->ScaleBot(TransformSection, Type, Axis, TransformToEdit, MaxValue, MinValue, ScaleBotValue);
				}
			}
		}
		if (PropertyThatChanged->GetName() == "ScaleLeftValue")
		{
			float Delta = OldScaleLeftValue - ScaleLeftValue;
			//Scale->ScaleLeft(TransformSection, CurvesTimesToEdit, MaxValue, MinValue, Delta, bScaleCapturedRange);
			OldScaleLeftValue = ScaleLeftValue;
		}
		if (PropertyThatChanged->GetName() == "ScaleRightValue")
		{
			float Delta = OldScaleRightValue - ScaleRightValue;
			//Scale->ScaleRight(TransformSection, CurvesTimesToEdit, MaxValue, MinValue, Delta, bScaleCapturedRange);
			OldScaleRightValue = ScaleRightValue;
		}

		if (PropertyThatChanged->GetName() == "MoveHorizontalValue")
		{
			float Delta = OldMoveHorizontalValue - MoveHorizontalValue;
			//Scale->MoveHorizontal(TransformSection, CurvesValuesToEdit, CurvesTimesToEdit, Delta);
			OldMoveHorizontalValue = MoveHorizontalValue;
		}
		if (PropertyThatChanged->GetName() == "MoveVerticalValue")
		{
			float Delta = OldMoveVerticalValue - MoveVerticalValue;
			//Scale->MoveVertical(TransformSection, CurvesValuesToEdit, CurvesTimesToEdit, Delta);
			OldMoveVerticalValue = MoveVerticalValue;
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void USequencerTools::OnToolClosed()
{
	ResetCapture();
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
					
					GetTransformAndCurves(TransformTypes, Axises);
					
					if (Location)
					{
						if (X)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetTranslationCurve(EAxis::X),
								FromTime,
								ToTime,
								TransformToEdit.Locaion.X.Values,
								TransformToEdit.Locaion.X.Times,
								TransformToEdit.Locaion.X.Indexes);
						}
						if (Y)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetTranslationCurve(EAxis::Y),
								FromTime,
								ToTime,
								TransformToEdit.Locaion.Y.Values,
								TransformToEdit.Locaion.Y.Times,
								TransformToEdit.Locaion.Y.Indexes);
						}
						if (Z)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetTranslationCurve(EAxis::Z),
								FromTime,
								ToTime,
								TransformToEdit.Locaion.Z.Values,
								TransformToEdit.Locaion.Z.Times,
								TransformToEdit.Locaion.Z.Indexes);
						}
					}

					if (Rotation)
					{
						if (X)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetRotationCurve(EAxis::X),
								FromTime,
								ToTime,
								TransformToEdit.Rotation.X.Values,
								TransformToEdit.Rotation.X.Times,
								TransformToEdit.Rotation.X.Indexes);
						}
						if (Y)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetRotationCurve(EAxis::Y),
								FromTime,
								ToTime,
								TransformToEdit.Rotation.Y.Values,
								TransformToEdit.Rotation.Y.Times,
								TransformToEdit.Rotation.Y.Indexes);
						}
						if (Z)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetRotationCurve(EAxis::Z),
								FromTime,
								ToTime,
								TransformToEdit.Rotation.Z.Values,
								TransformToEdit.Rotation.Z.Times,
								TransformToEdit.Rotation.Z.Indexes);
						}
					}

					if (Scaling)
					{
						if (X)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetScaleCurve(EAxis::X),
								FromTime,
								ToTime,
								TransformToEdit.Scale.X.Values,
								TransformToEdit.Scale.X.Times,
								TransformToEdit.Scale.X.Indexes);
						}
						if (Y)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetScaleCurve(EAxis::Y),
								FromTime,
								ToTime,
								TransformToEdit.Scale.Y.Values,
								TransformToEdit.Scale.Y.Times,
								TransformToEdit.Scale.Y.Indexes);
						}
						if (Z)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetScaleCurve(EAxis::Z),
								FromTime,
								ToTime,
								TransformToEdit.Scale.Z.Values,
								TransformToEdit.Scale.Z.Times,
								TransformToEdit.Scale.Z.Indexes);
						}
					}
					

					TArray <float> SortedValues;
					
					SortedValues += TransformToEdit.Locaion.X.Values;
					SortedValues += TransformToEdit.Locaion.Y.Values;
					SortedValues += TransformToEdit.Locaion.Z.Values;
					SortedValues += TransformToEdit.Rotation.X.Values;
					SortedValues += TransformToEdit.Rotation.Y.Values;
					SortedValues += TransformToEdit.Rotation.Z.Values;
					SortedValues += TransformToEdit.Scale.X.Values;
					SortedValues += TransformToEdit.Scale.Y.Values;
					SortedValues += TransformToEdit.Scale.Z.Values;

					SortedValues.Sort(
						[](const float lhv, const float rhv)
					{
						return lhv < rhv;
					}
					);
					MaxValue = SortedValues.Last();
					MinValue = SortedValues[0];

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
	CurvesValuesToEdit.Empty();
	TransformTypes.Empty();
	Axises.Empty();
}

void USequencerTools::GetValuesAndTimesToEditFromCurve(FRichCurve Curve, float FromTime, float ToTime, TArray<float>& OutValues, TArray<float>& OutTimes, TArray<int32>& OutIndexes)
{
	OutValues.Empty();
	OutTimes.Empty();
	OutIndexes.Empty();
	auto Keys = Curve.Keys;
	for (int32 Index = 0; Index < Keys.Num(); Index++)
	{
		if (Keys[Index].Time >= FromTime && Keys[Index].Time <= ToTime)
		{
			OutTimes.Add(Keys[Index].Time);
			OutValues.Add(Keys[Index].Value);
			OutIndexes.Add(Index);
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
