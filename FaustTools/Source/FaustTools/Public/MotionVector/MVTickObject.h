#pragma once
#include "Engine.h"
#include "UMotionVector.h"


class FMVTickObject : FTickableGameObject
{
public:
	FMVTickObject(UMotionVector *_Owner)
		:Owner(_Owner)
	{}

	virtual void Tick(float DeltaTime) override
	{
		if (!Owner) return;
		Owner->Tick(DeltaTime);
	}

	virtual bool IsTickable() const override
	{
		return true;
	}
	virtual bool IsTickableWhenPaused() const override
	{
		return true;
	}
	virtual bool IsTickableInEditor() const override
	{
		return true;
	}

	virtual UWorld* GetTickableGameObjectWorld() const override
	{
		return nullptr;
	}

	virtual TStatId GetStatId() const override {
		RETURN_QUICK_DECLARE_CYCLE_STAT(FSampleEdModule, STATGROUP_Tickables);
	}

private:
	UMotionVector *Owner = nullptr;
};