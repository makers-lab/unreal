#pragma once

#include "FaustToolsBaseClass.generated.h"

UCLASS(Blueprintable, Abstract)
class UFaustToolsBaseClass : public UObject
{
	GENERATED_BODY()
public:
	virtual void OnToolTriggered() {};
	virtual void OnToolClosed() {};
};