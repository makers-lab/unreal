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
					MinTime = UnsortedTimes[0];
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
					MaxTime = UnsortedTimes[UnsortedTimes.Num() - 1];
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

					TransformSection->Modify();
					
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

					GetInfoFromTransformSection(TransformSection, FromTime, ToTime, TransformToEdit, UnsortedTimes, UnsortedValues);
				
					if(UnsortedTimes.Num() && UnsortedValues.Num())
					{
						UnsortedValues.Sort();
						MaxValue = UnsortedValues[UnsortedValues.Num() - 1];
						MinValue = UnsortedValues[0];

						UnsortedTimes.Sort();
						MaxTime = UnsortedTimes[UnsortedTimes.Num() - 1];
						MinTime = UnsortedTimes[0];
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
	TransformToEdit.Reset();
	MinTime = 0.f;
	MaxTime = 0.f;
	MinValue = 0.f;
	MaxValue = 0.f;

	ScaleTopValue = 1.f;
	OldScaleTopValue = ScaleTopValue;
	ScaleBotValue = 1.f;
	OldScaleBotValue = ScaleBotValue;
	ScaleLeftValue = 1.f;
	OldScaleLeftValue = ScaleLeftValue;
	ScaleRightValue = 1.f;
	OldScaleRightValue = ScaleRightValue;

	
}

void USequencerTools::Apply()
{
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

					TransformSection->Modify();

					GEditor->EndTransaction();
				}
			}
			else USupport::NotificationBox(FString("Select an Actor in Level Sequence"));
		}
	}
	else USupport::NotificationBox(FString("Open Level Sequence Editor to work with"));
}

void USequencerTools::GetInfoFromTransformSection(UMovieScene3DTransformSection * TransformSection, float FromTime, float ToTime, CustomTransform& Transform, TArray <float>& UnsortedTimes, TArray <float>& UnsortedValues)
{
	if(Location)
	{
		for (auto Axis : Axises)
		{
			auto Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			for (int32 Index = 0; Index < Keys.Num(); Index++)
			{
				if (Keys[Index].Time < FromTime)
				{
					Transform.Location.GetCurve(Axis).HandlesLeftOutOfRange.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Keys[Index].Time));
				}
				if (Keys[Index].Time >= FromTime && Keys[Index].Time <= ToTime)
				{
					Transform.Location.GetCurve(Axis).HandlesToEdit.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Keys[Index].Time));
					Transform.Location.GetCurve(Axis).Indexes.Add(Index);
					Transform.Location.GetCurve(Axis).Times.Add(Keys[Index].Time);
					UnsortedValues.Add(Keys[Index].Value);
					UnsortedTimes.Add(Keys[Index].Time);
				}
				if (Keys[Index].Time > ToTime)
				{
					Transform.Location.GetCurve(Axis).HandlesRightOutOfRange.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Keys[Index].Time));
				}
			}
		}
	}

	if (Rotation)
	{
		for (auto Axis : Axises)
		{
			auto Keys = TransformSection->GetRotationCurve(Axis).Keys;
			for (int32 Index = 0; Index < Keys.Num(); Index++)
			{
				if (Keys[Index].Time < FromTime)
				{
					Transform.Rotation.GetCurve(Axis).HandlesLeftOutOfRange.Add(TransformSection->GetRotationCurve(Axis).FindKey(Keys[Index].Time));
				}
				if (Keys[Index].Time >= FromTime && Keys[Index].Time <= ToTime)
				{
					Transform.Rotation.GetCurve(Axis).HandlesToEdit.Add(TransformSection->GetRotationCurve(Axis).FindKey(Keys[Index].Time));
					Transform.Rotation.GetCurve(Axis).Indexes.Add(Index);
					Transform.Rotation.GetCurve(Axis).Times.Add(Keys[Index].Time);
					UnsortedValues.Add(Keys[Index].Value);
					UnsortedTimes.Add(Keys[Index].Time);
				}
				if (Keys[Index].Time > ToTime)
				{
					Transform.Rotation.GetCurve(Axis).HandlesRightOutOfRange.Add(TransformSection->GetRotationCurve(Axis).FindKey(Keys[Index].Time));
				}
			}
		}
	}

	if (Scaling)
	{
		for (auto Axis : Axises)
		{
			auto Keys = TransformSection->GetScaleCurve(Axis).Keys;
			for (int32 Index = 0; Index < Keys.Num(); Index++)
			{
				if (Keys[Index].Time < FromTime)
				{
					Transform.Scale.GetCurve(Axis).HandlesLeftOutOfRange.Add(TransformSection->GetScaleCurve(Axis).FindKey(Keys[Index].Time));
				}
				if (Keys[Index].Time >= FromTime && Keys[Index].Time <= ToTime)
				{
					Transform.Scale.GetCurve(Axis).HandlesToEdit.Add(TransformSection->GetScaleCurve(Axis).FindKey(Keys[Index].Time));
					Transform.Scale.GetCurve(Axis).Indexes.Add(Index);
					Transform.Scale.GetCurve(Axis).Times.Add(Keys[Index].Time);
					UnsortedValues.Add(Keys[Index].Value);
					UnsortedTimes.Add(Keys[Index].Time);
				}
				if (Keys[Index].Time > ToTime)
				{
					Transform.Scale.GetCurve(Axis).HandlesRightOutOfRange.Add(TransformSection->GetScaleCurve(Axis).FindKey(Keys[Index].Time));
				}
			}
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
		TransformTypes.Add(TransformType::Scal);

	if (X)
		Axises.Add(EAxis::Type::X);
	if (Y)
		Axises.Add(EAxis::Type::Y);
	if (Z)
		Axises.Add(EAxis::Type::Z);
}
