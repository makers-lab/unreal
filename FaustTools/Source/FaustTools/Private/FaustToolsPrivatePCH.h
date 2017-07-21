#pragma once

#include "Engine.h"
#include "Editor.h"
#include "SlateBasics.h"

enum TransformType
{
	Loc,
	Rot,
	Sca
};

struct Curve
{
	TArray<float> Values;
	TArray<float> Times;
	TArray<int32> Indexes;
};

struct Transform
{
	Curve X;
	Curve Y;
	Curve Z;
};

struct CustomTransform
{
	Transform Locaion;
	Transform Rotation;
	Transform Scale;
	void Reset()
	{
		Locaion.X.Indexes.Empty();
		Locaion.X.Times.Empty();
		Locaion.X.Values.Empty();
		Locaion.Y.Indexes.Empty();
		Locaion.Y.Times.Empty();
		Locaion.Y.Values.Empty();
		Locaion.Z.Indexes.Empty();
		Locaion.Z.Times.Empty();
		Locaion.Z.Values.Empty();

		Rotation.X.Indexes.Empty();
		Rotation.X.Times.Empty();
		Rotation.X.Values.Empty();
		Rotation.Y.Indexes.Empty();
		Rotation.Y.Times.Empty();
		Rotation.Y.Values.Empty();
		Rotation.Z.Indexes.Empty();
		Rotation.Z.Times.Empty();
		Rotation.Z.Values.Empty();

		Scale.X.Indexes.Empty();
		Scale.X.Times.Empty();
		Scale.X.Values.Empty();
		Scale.Y.Indexes.Empty();
		Scale.Y.Times.Empty();
		Scale.Y.Values.Empty();
		Scale.Z.Indexes.Empty();
		Scale.Z.Times.Empty();
		Scale.Z.Values.Empty();
	}
};