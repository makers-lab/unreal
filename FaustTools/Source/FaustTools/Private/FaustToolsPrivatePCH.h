#pragma once

#include "Engine.h"
#include "Editor.h"
#include "SlateBasics.h"

enum TransformType
{
	Loc,
	Rot,
	Scal
};

struct Curve
{
	TArray<float> Values;
	TArray<float> Times;
	TArray<int32> Indexes;
	TArray<FKeyHandle> HandlesToEdit;
	TArray<FKeyHandle> HandlesLeftOutOfRange;
	TArray<FKeyHandle> HandlesRightOutOfRange;

	void Reset()
	{
		Values.Empty();
		Times.Empty();
		Indexes.Empty();
		HandlesToEdit.Empty();
		HandlesLeftOutOfRange.Empty();
		HandlesRightOutOfRange.Empty();
	}
};

struct Transform
{
	Curve X;
	Curve Y;
	Curve Z;

	FORCEINLINE Curve& GetCurve(EAxis::Type Axis)
	{
		switch (Axis)
		{
		case EAxis::None:
			break;
		case EAxis::X:
			return X;
			break;
		case EAxis::Y:
			return Y;
			break;
		case EAxis::Z:
			return Z;
			break;
		default:
			break;
		}
	}
};

struct CustomTransform
{
	Transform Location;
	Transform Rotation;
	Transform Scale;

	void Reset()
	{
		Location.X.Reset();
		Location.Y.Reset();
		Location.Z.Reset();

		Rotation.X.Reset();
		Rotation.Y.Reset();
		Rotation.Z.Reset();

		Scale.X.Reset();
		Scale.Y.Reset();
		Scale.Z.Reset();
	}
};