#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "Filters.h"
#include "MovieScene3DTransformSection.h"
#include "SupportClass.h"

void UFilters::Butterworth(TransformType Type, EAxis::Type Axis, UMovieScene3DTransformSection* TransformSection, TArray<FKeyHandle> CurveHandles, float CutOff)
{
	TArray<float> ValuesToEdit;
	TArray<float> Time;
	if (CurveHandles.Num() > 2 && CutOff > 0)
	{
		switch (Type)
		{
		case Loc:
		{
			ValuesToEdit.Empty();
			Time.Empty();

			auto& Curve = TransformSection->GetTranslationCurve(Axis);
			for (auto Handle : CurveHandles)
			{
				ValuesToEdit.Add(Curve.GetKeyValue(Handle));
				Time.Add(Curve.GetKeyTime(Handle));
			}

			float DeltaTimeInSeconds = 0;

			if (Time.Num())
				DeltaTimeInSeconds = ((Time[Time.Num() - 1] - Time[0])) / float(Time.Num() - 1);

			CurveCorrection(DeltaTimeInSeconds, ValuesToEdit, CutOff);

			int32 Index = 0;
			for (auto Handle : CurveHandles)
			{
				Curve.SetKeyValue(Handle, ValuesToEdit[Index++], true);
			}
		}
		break;

		case Rot:
		{
			ValuesToEdit.Empty();
			Time.Empty();

			auto& Curve = TransformSection->GetRotationCurve(Axis);
			for (auto Handle : CurveHandles)
			{
				ValuesToEdit.Add(Curve.GetKeyValue(Handle));
				Time.Add(Curve.GetKeyTime(Handle));
			}

			float DeltaTimeInSeconds = 0;

			if (Time.Num())
				DeltaTimeInSeconds = ((Time[Time.Num() - 1] - Time[0])) / float(Time.Num() - 1);

			CurveCorrection(DeltaTimeInSeconds, ValuesToEdit, CutOff);

			int32 Index = 0;
			for (auto Handle : CurveHandles)
			{
				Curve.SetKeyValue(Handle, ValuesToEdit[Index++], true);
			}
		}
		break;

		case Scal:
		{
			ValuesToEdit.Empty();
			Time.Empty();

			auto& Curve = TransformSection->GetScaleCurve(Axis);
			for (auto Handle : CurveHandles)
			{
				ValuesToEdit.Add(Curve.GetKeyValue(Handle));
				Time.Add(Curve.GetKeyTime(Handle));
			}

			float DeltaTimeInSeconds = 0;

			if (Time.Num())
				DeltaTimeInSeconds = ((Time[Time.Num() - 1] - Time[0])) / float(Time.Num() - 1);

			CurveCorrection(DeltaTimeInSeconds, ValuesToEdit, CutOff);

			int32 Index = 0;
			for (auto Handle : CurveHandles)
			{
				Curve.SetKeyValue(Handle, ValuesToEdit[Index++], true);
			}
		}
		break;
		default:
			break;
		}
	}
}

void UFilters::FilterKeys(TransformType Type, EAxis::Type Axis, UMovieScene3DTransformSection* TransformSection, TArray<FKeyHandle> CurveHandles, float Delta)
{
	TArray<float> ValuesToEdit;
	if (CurveHandles.Num() > 2 && Delta > 0)
	{
		switch (Type)
		{
		case Loc:
		{
			ValuesToEdit.Empty();

			auto& Curve = TransformSection->GetTranslationCurve(Axis);
			for (auto Handle : CurveHandles)
			{
				ValuesToEdit.Add(Curve.GetKeyValue(Handle));
			}

			KeysCorrection(ValuesToEdit, Delta);

			int32 Index = 0;
			for (auto Handle : CurveHandles)
			{
				Curve.SetKeyValue(Handle, ValuesToEdit[Index++], true);
			}
		}
		break;

		case Rot:
		{
			ValuesToEdit.Empty();

			auto& Curve = TransformSection->GetRotationCurve(Axis);
			for (auto Handle : CurveHandles)
			{
				ValuesToEdit.Add(Curve.GetKeyValue(Handle));
			}

			KeysCorrection(ValuesToEdit, Delta);

			int32 Index = 0;
			for (auto Handle : CurveHandles)
			{
				Curve.SetKeyValue(Handle, ValuesToEdit[Index++], true);
			}
		}
		break;

		case Scal:
		{
			ValuesToEdit.Empty();

			auto& Curve = TransformSection->GetScaleCurve(Axis);
			for (auto Handle : CurveHandles)
			{
				ValuesToEdit.Add(Curve.GetKeyValue(Handle));
			}

			KeysCorrection(ValuesToEdit, Delta);

			int32 Index = 0;
			for (auto Handle : CurveHandles)
			{
				Curve.SetKeyValue(Handle, ValuesToEdit[Index++], true);
			}
		}
		break;
		default:
			break;
		}
	}
}

void UFilters::KeysCorrection(TArray<float> &ValuesToEdit, float Delta)
{
	TArray<int32> KeysIndexOutOfDelta;
	int32 EnterPointIndex = 0;
	int32 LeavePointIndex = 0;

	if (ValuesToEdit.Num() > 2)
	{
		for (int32 Index = 1; Index < ValuesToEdit.Num() - 1; Index++)
		{
			KeysIndexOutOfDelta.Empty();
			EnterPointIndex = 0;
			LeavePointIndex = 0;
			if (FMath::Abs(ValuesToEdit[Index - 1] - ValuesToEdit[Index]) > Delta)
			{
				KeysIndexOutOfDelta.Add(Index);
				EnterPointIndex = Index - 1;
				for (int32 i = Index + 1; i < ValuesToEdit.Num() - 1; i++)
				{
					if ((FMath::Abs(ValuesToEdit[EnterPointIndex] - ValuesToEdit[i]) > Delta) &&
						(FMath::Abs(ValuesToEdit[i - 1] - ValuesToEdit[i]) < Delta)
						||
						(FMath::Abs(ValuesToEdit[EnterPointIndex] - ValuesToEdit[i]) < Delta) &&
						((FMath::Abs(ValuesToEdit[i - 1] - ValuesToEdit[i]) > Delta) &&
						(FMath::Abs(ValuesToEdit[i] - ValuesToEdit[i + 1]) > Delta))
						||
						(FMath::Abs(ValuesToEdit[EnterPointIndex] - ValuesToEdit[i]) > Delta) &&
						((FMath::Abs(ValuesToEdit[i - 1] - ValuesToEdit[i]) > Delta) &&
						(FMath::Abs(ValuesToEdit[i] - ValuesToEdit[i + 1]) > Delta)))
					{
						KeysIndexOutOfDelta.Add(i);
					}
					else
					{
						LeavePointIndex = i;
						Index = LeavePointIndex;
						break;
					}
				}

				for (int32 Ind = 0; Ind < KeysIndexOutOfDelta.Num(); Ind++)
				{
					ValuesToEdit[KeysIndexOutOfDelta[Ind]] = (ValuesToEdit[EnterPointIndex] + ValuesToEdit[LeavePointIndex]) / 2;
				}
			}
		}
	}
	else
		USupport::NotificationBox("Select more then 2 frames");
}

void UFilters::CurveCorrection(float DeltaTimeInSeconds, TArray<float> &ValuesToEdit, float CutOff)
{
	if (ValuesToEdit.Num() > 2)
	{
		float SamplingRate = 1 / DeltaTimeInSeconds;
		int32 dF2 = ValuesToEdit.Num() - 1; // The data range is set with dF2
		TArray<float> Dat2;
		Dat2.SetNumZeroed(dF2 + 4); // Array with 4 extra points front and back

		for (int32 r = 0; r < dF2; r++)
		{
			Dat2[2 + r] = ValuesToEdit[r];
		}

		Dat2[1] = Dat2[0] = ValuesToEdit[0];
		Dat2[dF2 + 3] = Dat2[dF2 + 2] = ValuesToEdit[dF2];

		//variables for filter
		const float pi = 3.14159265358979;
		float wc = FMath::Tan(CutOff * pi / SamplingRate);
		float k1 = 1.414213562 * wc; // Sqrt(2) * wc
		float k2 = wc * wc;
		float a = k2 / (1 + k1 + k2);
		float b = 2 * a;
		float c = a;
		float k3 = b / k2;
		float d = -2 * a + k3;
		float e = 1 - (2 * a) - k3;

		// recursive triggers - enable filter is performed (first, last points constant)
		TArray<float> DatYt;
		DatYt.SetNumZeroed(dF2 + 4);

		DatYt[1] = DatYt[0] = ValuesToEdit[0];
		for (int32 s = 2; s < dF2 + 3; s++) {
			DatYt[s] = a * Dat2[s] + b * Dat2[s - 1] + c * Dat2[s - 2]
				+ d * DatYt[s - 1] + e * DatYt[s - 2];
		}
		DatYt[dF2 + 3] = DatYt[dF2];

		// forward filter
		TArray<float> DatZt;
		DatZt.SetNumZeroed(dF2 + 2);

		DatZt[dF2] = DatYt[dF2 + 2];
		DatZt[dF2 + 1] = DatYt[dF2 + 3];

		for (int32 t = -dF2 + 1; t <= 0; t++) {
			DatZt[-t] = a * DatYt[-t + 2] + b * DatYt[-t + 3] + c * DatYt[-t + 4]
				+ d * DatZt[-t + 1] + e * DatZt[-t + 2];
		}

		// Calculated points copied 
		for (int32 p = 1; p < dF2 - 1; p++) {
			ValuesToEdit[p] = DatZt[p];
		}

		//second and last-1 key correction
		ValuesToEdit[1] = (ValuesToEdit[0] + ValuesToEdit[2]) / 2;
		ValuesToEdit[dF2 - 1] = (ValuesToEdit[dF2 - 2] + ValuesToEdit[dF2]) / 2;
	}
	else
		USupport::NotificationBox("Select more then 2 frames");
}
