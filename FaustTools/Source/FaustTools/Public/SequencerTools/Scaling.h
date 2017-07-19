#pragma once

#include "Engine.h"
#include "FaustToolsBaseClass.h"
//#include "Scaling.generated.h"

//UCLASS()
class UScale //: public UObject
{
	//GENERATED_BODY()
public:
	void ScaleTop(TArray<float>& ValuesToEdit, float Delta, bool bScaleCapturedOnly);
	void ScaleBot(TArray<float>& ValuesToEdit, float Delta, bool bScaleCapturedOnly);
	void ScaleLeft(TArray<float>& ValuesToEdit, float Delta, bool bScaleCapturedOnly);
	void ScaleRight(TArray<float>& ValuesToEdit, float Delta, bool bScaleCapturedOnly);
};