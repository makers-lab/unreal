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
			float Delta = ScaleTopValue / OldScaleTopValue;
			TArray<float> UnsortedValues;
			for (auto Type : TransformTypes)
			{
				for (auto Axis : Axises)
				{
					Scale->ScaleTop(TransformSection, Type, Axis, TransformToEdit, MaxValue, MinValue, Delta, UnsortedValues);
				}
			}
			if(UnsortedValues.Num())
			{
				UnsortedValues.Sort();
				MaxValue = UnsortedValues[UnsortedValues.Num() - 1];
				OldScaleTopValue = ScaleTopValue;
			}
		}
		if (PropertyThatChanged->GetName() == "ScaleBotValue")
		{
			TArray<float> UnsortedValues;
			float Delta = ScaleBotValue / OldScaleBotValue;
			for (auto Type : TransformTypes)
			{
				for (auto Axis : Axises)
				{
					Scale->ScaleBot(TransformSection, Type, Axis, TransformToEdit, MaxValue, MinValue, Delta, UnsortedValues);
				}
			}
			if(UnsortedValues.Num())
			{
				UnsortedValues.Sort();
				MinValue = UnsortedValues[0];
				OldScaleBotValue = ScaleBotValue;
			}
		}
		if (PropertyThatChanged->GetName() == "ScaleLeftValue")
		{
			TArray<float> UnsortedTimes;
			float Delta = ScaleLeftValue / OldScaleLeftValue;
			if(TransformTypes.Num())
			{
				for (auto Type : TransformTypes)
				{
					for (auto Axis : Axises)
					{
						Scale->ScaleLeft(TransformSection, Type, Axis, TransformToEdit, MaxTime, MinTime, Delta, UnsortedTimes, bScaleCapturedRange);
					}
				}

				if (UnsortedTimes.Num())
				{
					UnsortedTimes.Sort();
					MinValue = UnsortedTimes[0];
					OldScaleLeftValue = ScaleLeftValue;
				}
			}
		}
		if (PropertyThatChanged->GetName() == "ScaleRightValue")
		{
			TArray<float> UnsortedTimes;
			float Delta = ScaleRightValue / OldScaleRightValue;
			if (TransformTypes.Num())
			{
				for (auto Type : TransformTypes)
				{
					for (auto Axis : Axises)
					{
						Scale->ScaleRight(TransformSection, Type, Axis, TransformToEdit, MaxTime, MinTime, Delta, UnsortedTimes, bScaleCapturedRange);
					}
				}

				if (UnsortedTimes.Num())
				{
					UnsortedTimes.Sort();
					MinValue = UnsortedTimes[UnsortedTimes.Num() - 1];
					OldScaleRightValue = ScaleRightValue;
				}
			}
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
	TransformToEdit.Reset();
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
					float LastTime = TransformSection->GetEndTime() + Step;
					float Frames = FMath::RoundToFloat(LastTime / Step);
					
					float P1 = FromFrame / Frames * 100;
					float FromTime = LastTime / 100 * P1;
 
					float P2 = ToFrame / Frames * 100;
					float ToTime = LastTime / 100 * P2;
					
					GetTransformAndCurves(TransformTypes, Axises);
					
					TArray <float> UnsortedValues;
					TArray <float> UnsortedTimes;

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
							UnsortedValues += TransformToEdit.Locaion.X.Values;
							UnsortedTimes += TransformToEdit.Locaion.X.Times;
						}
						if (Y)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetTranslationCurve(EAxis::Y),
								FromTime,
								ToTime,
								TransformToEdit.Locaion.Y.Values,
								TransformToEdit.Locaion.Y.Times,
								TransformToEdit.Locaion.Y.Indexes);
							UnsortedValues += TransformToEdit.Locaion.Y.Values;
							UnsortedTimes += TransformToEdit.Locaion.Y.Times;
						}
						if (Z)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetTranslationCurve(EAxis::Z),
								FromTime,
								ToTime,
								TransformToEdit.Locaion.Z.Values,
								TransformToEdit.Locaion.Z.Times,
								TransformToEdit.Locaion.Z.Indexes);
							UnsortedValues += TransformToEdit.Locaion.Z.Values;
							UnsortedTimes += TransformToEdit.Locaion.Z.Times;
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
							UnsortedValues += TransformToEdit.Rotation.X.Values;
							UnsortedTimes += TransformToEdit.Rotation.X.Times;
						}
						if (Y)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetRotationCurve(EAxis::Y),
								FromTime,
								ToTime,
								TransformToEdit.Rotation.Y.Values,
								TransformToEdit.Rotation.Y.Times,
								TransformToEdit.Rotation.Y.Indexes);
							UnsortedValues += TransformToEdit.Rotation.Y.Values;
							UnsortedTimes += TransformToEdit.Rotation.Y.Times;
						}
						if (Z)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetRotationCurve(EAxis::Z),
								FromTime,
								ToTime,
								TransformToEdit.Rotation.Z.Values,
								TransformToEdit.Rotation.Z.Times,
								TransformToEdit.Rotation.Z.Indexes);
							UnsortedValues += TransformToEdit.Rotation.Z.Values;
							UnsortedTimes += TransformToEdit.Rotation.Z.Times;
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
							UnsortedValues += TransformToEdit.Scale.X.Values;
							UnsortedTimes += TransformToEdit.Scale.X.Times;
						}
						if (Y)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetScaleCurve(EAxis::Y),
								FromTime,
								ToTime,
								TransformToEdit.Scale.Y.Values,
								TransformToEdit.Scale.Y.Times,
								TransformToEdit.Scale.Y.Indexes);
							UnsortedValues += TransformToEdit.Scale.Y.Values;
							UnsortedTimes += TransformToEdit.Scale.Y.Times;
						}
						if (Z)
						{
							GetValuesAndTimesToEditFromCurve(TransformSection->GetScaleCurve(EAxis::Z),
								FromTime,
								ToTime,
								TransformToEdit.Scale.Z.Values,
								TransformToEdit.Scale.Z.Times,
								TransformToEdit.Scale.Z.Indexes);
							UnsortedValues += TransformToEdit.Scale.Z.Values;
							UnsortedTimes += TransformToEdit.Scale.Z.Times;
						}
					}
				
					if(UnsortedTimes.Num() && UnsortedValues.Num())
					{
						UnsortedValues.Sort();
						MaxValue = UnsortedValues[UnsortedValues.Num() - 1];
						MinValue = UnsortedValues[0];

						UnsortedTimes.Sort();
						MaxTime = UnsortedTimes[UnsortedTimes.Num() - 1];
						MinTime = UnsortedTimes[0];
						GEditor->EndTransaction();
					}
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
	TransformToEdit.Reset();
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
	TransformTypes.Empty();
	Axises.Empty();
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
