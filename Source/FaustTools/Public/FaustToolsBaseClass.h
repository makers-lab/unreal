#pragma once

#include "FaustToolsBaseClass.generated.h"

#define _LOG(_TEXT_, ...) UE_LOG(LogTemp, Warning, TEXT(_TEXT_), __VA_ARGS__)

UCLASS(Blueprintable, Abstract)
class UFaustToolsBaseClass : public UObject
{
	GENERATED_BODY()
public:
	virtual void OnToolTriggered() {};
	virtual void OnToolClosed() {};
};