#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "Scaling.h"
#include "MovieScene3DTransformSection.h"



void UScale::ScaleTop(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float& MaxValue, float& MinValue, float Delta, TArray<float>& KeysValuesToSort)
{
	switch (Type)
	{
	case Loc:
	{
		TArray<FKeyHandle> HandlesToEdit = Transform.Location.GetCurve(Axis).HandlesToEdit;

		for (auto& Handle : HandlesToEdit)
		{
			float DiffMinNext = TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle) - MinValue;
			float MultiplyDiffMinNext = DiffMinNext * Delta;
			float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
			TransformSection->GetTranslationCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
			KeysValuesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle));
		}
	}
		break;
	case Rot:
	{
		TArray<FKeyHandle> HandlesToEdit = Transform.Rotation.GetCurve(Axis).HandlesToEdit;
		for (auto& Handle : HandlesToEdit)
		{
			float DiffMinNext = TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle) - MinValue;
			float MultiplyDiffMinNext = DiffMinNext * Delta;
			float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
			TransformSection->GetRotationCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
			KeysValuesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle));
		}
	}
		break;
	case Scal:
	{
		TArray<FKeyHandle> HandlesToEdit = Transform.Scale.GetCurve(Axis).HandlesToEdit;

		for (auto& Handle : HandlesToEdit)
		{
			float DiffMinNext = TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle) - MinValue;
			float MultiplyDiffMinNext = DiffMinNext * Delta;
			float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
			TransformSection->GetScaleCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
			KeysValuesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle));
		}
	}
		break;
	default:
		break;
	}
}

void UScale::ScaleBot(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float& MaxValue, float& MinValue, float Delta, TArray<float>& KeysValuesToSort)
{
	switch (Type)
	{
	case Loc:
	{
		TArray<FKeyHandle> HandlesToEdit = Transform.Location.GetCurve(Axis).HandlesToEdit;

		for (auto& Handle : HandlesToEdit)
		{
			float DiffMaxPrev = TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle) - MaxValue;
			float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
			float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
			TransformSection->GetTranslationCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
			KeysValuesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle));
		}
	}
	break;
	case Rot:
	{
		TArray<FKeyHandle> HandlesToEdit = Transform.Rotation.GetCurve(Axis).HandlesToEdit;
		for (auto& Handle : HandlesToEdit)
		{
			float DiffMaxPrev = TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle) - MaxValue;
			float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
			float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
			TransformSection->GetRotationCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
			KeysValuesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle));
		}
	}
	break;
	case Scal:
	{
		TArray<FKeyHandle> HandlesToEdit = Transform.Scale.GetCurve(Axis).HandlesToEdit;

		for (auto& Handle : HandlesToEdit)
		{
			float DiffMaxPrev = TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle) - MaxValue;
			float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
			float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
			TransformSection->GetScaleCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
			KeysValuesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle));
		}
	}
	break;
	default:
		break;
	}
}

void UScale::ScaleLeft(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform& Transform, float& MaxTime, float& MinTime, float Delta, TArray<float>& KeysTimesToSort, bool bScaleCapturedOnly)
{
	switch (Type)
	{
	case Loc:
	{
		TArray<FKeyHandle> Handles = Transform.Location.GetCurve(Axis).HandlesToEdit;

		if (Handles.Num())
		{
			float OldTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[0]);

			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle));
			}
			float CurrTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange = Transform.Location.GetCurve(Axis).HandlesLeftOutOfRange;

				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}
		break;

	case Rot:
	{
		TArray<FKeyHandle> Handles = Transform.Rotation.GetCurve(Axis).HandlesToEdit;

		if (Handles.Num())
		{
			float OldTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[0]);

			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle));
			}

			float CurrTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange = Transform.Rotation.GetCurve(Axis).HandlesLeftOutOfRange;

				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}
		break;

	case Scal:
	{
		TArray<FKeyHandle> Handles = Transform.Scale.GetCurve(Axis).HandlesToEdit;

		if (Handles.Num())
		{
			float OldTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[0]);

			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle));
			}

			float CurrTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange = Transform.Scale.GetCurve(Axis).HandlesLeftOutOfRange;

				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}
		break;
	default:
		break;
	}
}

void UScale::ScaleRight(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform& Transform, float& MaxTime, float& MinTime, float Delta, TArray<float>& KeysTimesToSort, bool bScaleCapturedOnly)
{
	switch (Type)
	{
	case Loc:
	{
		TArray<FKeyHandle> Handles = Transform.Location.GetCurve(Axis).HandlesToEdit;

		if (Handles.Num())
		{
			float OldTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle));
			}
			float CurrTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange = Transform.Location.GetCurve(Axis).HandlesRightOutOfRange;

				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}
	break;

	case Rot:
	{
		TArray<FKeyHandle> Handles = Transform.Rotation.GetCurve(Axis).HandlesToEdit;

		if (Handles.Num())
		{
			float OldTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle));
			}
			float CurrTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange = Transform.Rotation.GetCurve(Axis).HandlesRightOutOfRange;

				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}
	break;

	case Scal:
	{
		TArray<FKeyHandle> Handles = Transform.Scale.GetCurve(Axis).HandlesToEdit;

		if (Handles.Num())
		{
			float OldTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle));
			}
			
			float CurrTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange = Transform.Scale.GetCurve(Axis).HandlesRightOutOfRange;

				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}
	break;
	default:
		break;
	}
}

