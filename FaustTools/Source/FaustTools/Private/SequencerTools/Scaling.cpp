#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "Scaling.h"
#include "MovieScene3DTransformSection.h"



void UScale::ScaleTop(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float MaxValue, float MinValue, float Delta)
{
	if (Type == TransformType::Loc)
	{
		if (Axis == EAxis::X)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Locaion.X.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Locaion.X.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Locaion.X.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
		if (Axis == EAxis::Y)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Locaion.Y.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Locaion.Y.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Locaion.Y.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
		if (Axis == EAxis::Z)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Locaion.Z.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Locaion.Z.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Locaion.Z.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
	}

	if (Type == TransformType::Rot)
	{
		if (Axis == EAxis::X)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Rotation.X.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Rotation.X.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Rotation.X.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
		if (Axis == EAxis::Y)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Rotation.Y.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Rotation.Y.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Rotation.Y.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
		if (Axis == EAxis::Z)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Rotation.Z.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Rotation.Z.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Rotation.Z.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
	}

	if (Type == TransformType::Sca)
	{
		if (Axis == EAxis::X)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Scale.X.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Scale.X.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Scale.X.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
		if (Axis == EAxis::Y)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Scale.Y.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Scale.Y.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Scale.Y.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
		if (Axis == EAxis::Z)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Scale.Z.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMinNext = Transform.Scale.Z.Values[Index] - MinValue;
				float MultiplyDiffMinNext = DiffMinNext * Delta;
				float ChangedDiffMinNext = MultiplyDiffMinNext + MinValue;
				Keys[Transform.Scale.Z.Indexes[Index]].Value = ChangedDiffMinNext;
			}
		}
	}
}

void UScale::ScaleBot(UMovieScene3DTransformSection * TransformSection, TransformType Type, EAxis::Type Axis, CustomTransform Transform, float MaxValue, float MinValue, float Delta)
{
	if (Type == TransformType::Loc)
	{
		if (Axis == EAxis::X)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Locaion.X.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Locaion.X.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Locaion.X.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
		if (Axis == EAxis::Y)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Locaion.Y.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Locaion.Y.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Locaion.Y.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
		if (Axis == EAxis::Z)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Locaion.Z.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Locaion.Z.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Locaion.Z.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
	}

	if (Type == TransformType::Rot)
	{
		if (Axis == EAxis::X)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Rotation.X.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Rotation.X.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Rotation.X.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
		if (Axis == EAxis::Y)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Rotation.Y.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Rotation.Y.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Rotation.Y.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
		if (Axis == EAxis::Z)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Rotation.Z.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Rotation.Z.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Rotation.Z.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
	}

	if (Type == TransformType::Sca)
	{
		if (Axis == EAxis::X)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Scale.X.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Scale.X.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Scale.X.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
		if (Axis == EAxis::Y)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Scale.Y.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Scale.Y.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Scale.Y.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
		if (Axis == EAxis::Z)
		{
			auto& Keys = TransformSection->GetTranslationCurve(Axis).Keys;
			int32 Num = Transform.Scale.Z.Values.Num();
			for (int32 Index = 0; Index < Num; Index++)
			{
				float DiffMaxNext = Transform.Scale.Z.Values[Index] - MaxValue;
				float MultiplyDiffMaxNext = DiffMaxNext * Delta;
				float ChangedDiffMaxNext = MultiplyDiffMaxNext + MaxValue;
				Keys[Transform.Scale.Z.Indexes[Index]].Value = ChangedDiffMaxNext;
			}
		}
	}
}

void UScale::ScaleLeft(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float MaxValue, float MinValue, float Delta, bool bScaleCapturedOnly)
{
	
}

void UScale::ScaleRight(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, float MaxValue, float MinValue, float Delta, bool bScaleCapturedOnly)
{
	
}

void UScale::MoveHorizontal(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, TMap<EAxis::Type, TArray<float>>& TimesToEdit, float Delta)
{

}

void UScale::MoveVertical(UMovieScene3DTransformSection * TransformSection, TMap<EAxis::Type, TArray<float>>& ValuesToEdit, TMap<EAxis::Type, TArray<float>>& TimesToEdit, float Delta)
{
	
}
