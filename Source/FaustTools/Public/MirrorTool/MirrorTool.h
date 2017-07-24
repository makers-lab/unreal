#pragma once

#include "Engine.h"
#include "ModuleManager.h"
#include "FaustToolsBaseClass.h"
#include "MirrorTool.generated.h"

UCLASS(Blueprintable)
class UMirrorTool : public UFaustToolsBaseClass
{
	GENERATED_BODY()

public:
	UMirrorTool();

	UPROPERTY(EditAnywhere, Category = "Settings")
	FPlane MirrorPlane;

	UFUNCTION(Exec)
	void MirrorSelectedObjects();
};
