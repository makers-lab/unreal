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
};