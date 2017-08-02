#pragma once
#include "Engine.h"
#include "MayaToUE.h"

class FEditorTickObject : FTickableGameObject
{
public:

	FEditorTickObject(UMayaToUE *_Owner)
		:Owner(_Owner)
	{}

	virtual void Tick(float DeltaTime) override
	{
		check(Owner != NULL);
		Owner->Tick(DeltaTime);
	}

	virtual bool IsTickable() const override { return true; }

	virtual bool IsTickableWhenPaused() const override { return true; }

	virtual bool IsTickableInEditor() const override { return true; }

	virtual UWorld* GetTickableGameObjectWorld() const override { return nullptr; }

	virtual TStatId GetStatId() const override 
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FSampleEdModule, STATGROUP_Tickables);
	}

private:
	UMayaToUE *Owner = nullptr;
};