#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "Scaling.h"
#include "MovieScene3DTransformSection.h"



void UScale::ScaleTop(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float& MaxValue, float& MinValue, float Delta, TArray<float>& KeysValuesToSort)
{
	if (Type == TransformType::Loc)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.X.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetTranslationCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.Y.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetTranslationCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.Z.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetTranslationCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle));
			}
		}
	}

	if (Type == TransformType::Rot)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.X.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetRotationCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.Y.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetRotationCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.Z.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetRotationCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle));
			}

		}
	}

	if (Type == TransformType::Sca)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.X.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetScaleCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.Y.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetScaleCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.Y.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle) - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				TransformSection->GetScaleCurve(Axis).SetKeyValue(Handle, ChangedDiffMinNext);
				KeysValuesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle));
			}
		}
	}
}

void UScale::ScaleBot(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float& MaxValue, float& MinValue, float Delta, TArray<float>& KeysValuesToSort)
{
	if (Type == TransformType::Loc)
	{		
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.X.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetTranslationCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.Y.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetTranslationCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.Z.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetTranslationCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyValue(Handle));
			}
		}
	}

	if (Type == TransformType::Rot)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.X.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetRotationCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.Y.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetRotationCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.Z.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetRotationCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyValue(Handle));
			}

		}
	}

	if (Type == TransformType::Sca)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.X.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetScaleCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.Y.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetScaleCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle));
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.Y.Times[Index]));
			}
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle) - MaxValue;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxValue;
				TransformSection->GetScaleCurve(Axis).SetKeyValue(Handle, ChangedDiffMaxPrev);
				KeysValuesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyValue(Handle));
			}
		}
	}
}

void UScale::ScaleLeft(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform& Transform, float& MaxTime, float& MinTime, float Delta, TArray<float>& KeysTimesToSort, bool bScaleCapturedOnly)
{
	if (Type == TransformType::Loc)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.X.Times[Index]));
			}

			float OldTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle));
				Transform.Location.X.Times[Index++] = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Location.X.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetTranslationCurve(Axis).FindKey(TransformSection->GetTranslationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.Y.Times[Index]));
			}

			float OldTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle));
				Transform.Location.Y.Times[Index++] = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Location.Y.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetTranslationCurve(Axis).FindKey(TransformSection->GetTranslationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.Z.Times[Index]));
			}

			float OldTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle));
				Transform.Location.Z.Times[Index++] = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Location.Z.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetTranslationCurve(Axis).FindKey(TransformSection->GetTranslationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}

	if (Type == TransformType::Rot)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.X.Times[Index]));
			}

			float OldTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle));
				Transform.Rotation.X.Times[Index++] = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Rotation.X.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetRotationCurve(Axis).FindKey(TransformSection->GetRotationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.Y.Times[Index]));
			}

			float OldTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle));
				Transform.Rotation.Y.Times[Index++] = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Rotation.Y.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetRotationCurve(Axis).FindKey(TransformSection->GetRotationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.Z.Times[Index]));
			}

			float OldTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle));
				Transform.Rotation.Z.Times[Index++] = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Rotation.Z.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetRotationCurve(Axis).FindKey(TransformSection->GetRotationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}

	if (Type == TransformType::Sca)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.X.Times[Index]));
			}

			float OldTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle));
				Transform.Scale.X.Times[Index++] = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Scale.X.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetScaleCurve(Axis).FindKey(TransformSection->GetScaleCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.Y.Times[Index]));
			}

			float OldTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle));
				Transform.Scale.Y.Times[Index++] = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Scale.Y.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetScaleCurve(Axis).FindKey(TransformSection->GetScaleCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Rotation.Z.Times[Index]));
			}

			float OldTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[0]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMaxPrev = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle) - MaxTime;
				float MultiplyDiffMaxPrev = DiffMaxPrev * Delta;
				float ChangedDiffMaxPrev = MultiplyDiffMaxPrev + MaxTime;
				TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, ChangedDiffMaxPrev);
				KeysTimesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle));
				Transform.Rotation.Z.Times[Index++] = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
			}
			float CurrTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[0]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = 0; Index < Transform.Rotation.Z.Indexes[0]; Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetScaleCurve(Axis).FindKey(TransformSection->GetScaleCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}
}

void UScale::ScaleRight(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform& Transform, float& MaxTime, float& MinTime, float Delta, TArray<float>& KeysTimesToSort, bool bScaleCapturedOnly)
{
	if (Type == TransformType::Loc)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.X.Times[Index]));
			}

			float OldTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle));
				Transform.Location.X.Times[Index++] = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Location.X.Indexes[Transform.Location.X.Indexes.Num() - 1] + 1; Index < TransformSection->GetTranslationCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetTranslationCurve(Axis).FindKey(TransformSection->GetTranslationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.Y.Times[Index]));
			}

			float OldTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle));
				Transform.Location.Y.Times[Index++] = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Location.Y.Indexes[Transform.Location.Y.Indexes.Num() - 1] + 1; Index < TransformSection->GetTranslationCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetTranslationCurve(Axis).FindKey(TransformSection->GetTranslationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Location.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetTranslationCurve(Axis).FindKey(Transform.Location.Z.Times[Index]));
			}

			float OldTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle));
				Transform.Location.Z.Times[Index++] = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Location.Z.Indexes[Transform.Location.Z.Indexes.Num() - 1] + 1; Index < TransformSection->GetTranslationCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetTranslationCurve(Axis).FindKey(TransformSection->GetTranslationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetTranslationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetTranslationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}

	if (Type == TransformType::Rot)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.X.Times[Index]));
			}

			float OldTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle));
				Transform.Rotation.X.Times[Index++] = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Rotation.X.Indexes[Transform.Rotation.X.Indexes.Num() - 1] + 1; Index < TransformSection->GetRotationCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetRotationCurve(Axis).FindKey(TransformSection->GetRotationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.Y.Times[Index]));
			}

			float OldTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle));
				Transform.Rotation.Y.Times[Index++] = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Rotation.Y.Indexes[Transform.Rotation.Y.Indexes.Num() - 1] + 1; Index < TransformSection->GetRotationCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetRotationCurve(Axis).FindKey(TransformSection->GetRotationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Rotation.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetRotationCurve(Axis).FindKey(Transform.Rotation.Z.Times[Index]));
			}

			float OldTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle));
				Transform.Rotation.Z.Times[Index++] = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Rotation.Z.Indexes[Transform.Rotation.Z.Indexes.Num() - 1] + 1; Index < TransformSection->GetRotationCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetRotationCurve(Axis).FindKey(TransformSection->GetRotationCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetRotationCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetRotationCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}

	if (Type == TransformType::Sca)
	{
		if (Axis == EAxis::X)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.X.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.X.Times[Index]));
			}

			float OldTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle));
				Transform.Scale.X.Times[Index++] = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Scale.X.Indexes[Transform.Scale.X.Indexes.Num() - 1] + 1; Index < TransformSection->GetScaleCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetScaleCurve(Axis).FindKey(TransformSection->GetScaleCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Y)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.Y.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.Y.Times[Index]));
			}

			float OldTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle));
				Transform.Scale.Y.Times[Index++] = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Scale.Y.Indexes[Transform.Scale.Y.Indexes.Num() - 1] + 1; Index < TransformSection->GetScaleCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetScaleCurve(Axis).FindKey(TransformSection->GetScaleCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
		if (Axis == EAxis::Z)
		{
			TArray<FKeyHandle> Handles;
			for (int32 Index = 0; Index < Transform.Scale.Z.Times.Num(); Index++)
			{
				Handles.Add(TransformSection->GetScaleCurve(Axis).FindKey(Transform.Scale.Z.Times[Index]));
			}

			float OldTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);
			int32 Index = 0;
			for (auto& Handle : Handles)
			{
				float DiffMinNext = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle) - MinTime;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinTime;
				TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, ChangedDiffMinNext);
				KeysTimesToSort.Add(TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle));
				Transform.Scale.Z.Times[Index++] = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
			}

			float CurrTime = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handles[Handles.Num() - 1]);

			if (!bScaleCapturedOnly)
			{
				TArray<FKeyHandle> HandlesOutOfRange;
				for (int32 Index = Transform.Scale.Z.Indexes[Transform.Scale.Z.Indexes.Num() - 1] + 1; Index < TransformSection->GetScaleCurve(Axis).Keys.Num(); Index++)
				{
					HandlesOutOfRange.Add(TransformSection->GetScaleCurve(Axis).FindKey(TransformSection->GetScaleCurve(Axis).Keys[Index].Time));
				}
				for (auto& Handle : HandlesOutOfRange)
				{
					float Time = TransformSection->GetScaleCurve(Axis).GetKeyTime(Handle);
					TransformSection->GetScaleCurve(Axis).SetKeyTime(Handle, Time - (OldTime - CurrTime));
				}
			}
		}
	}
}

