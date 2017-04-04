#pragma once

#include "EditorTool.generated.h"

UCLASS(Blueprintable, Abstract)
class UEditorTool : public UObject
{
	GENERATED_BODY()
public:
	virtual void OnToolTriggered() {};
	virtual void OnToolClosed() {};
};