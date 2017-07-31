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
	Transform Location;
	Transform Rotation;
	Transform Scale;
	void Reset()
	{
		Location.X.Indexes.Empty();
		Location.X.Times.Empty();
		Location.X.Values.Empty();
		Location.Y.Indexes.Empty();
		Location.Y.Times.Empty();
		Location.Y.Values.Empty();
		Location.Z.Indexes.Empty();
		Location.Z.Times.Empty();
		Location.Z.Values.Empty();

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