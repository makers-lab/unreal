#pragma once

#include "Engine.h"
#include "ModuleManager.h"
#include "FaustToolsBaseClass.h"
#include "Animation/SkeletalMeshActor.h"
#include "BlueprintEditorUtils.h"
#include "Materials/MaterialExpressionConstant.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionConstant3Vector.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceConstant.h"
#include "IContentBrowserSingleton.h"
#include "ContentBrowserModule.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#include "UObject/ConstructorHelpers.h"


#include "USequencerTools.generated.h"


UCLASS(Blueprintable)
class USequencerTools : public UFaustToolsBaseClass
{
	GENERATED_BODY()
public:
	TSet<UMaterial*> GetSelectedActorMaterials();
	TSet<UMaterial*> GetSelectedMaterialsInContentBrowser();

	USequencerTools();

	virtual void PreEditChange(UProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void OnToolClosed() override;

	UFUNCTION(Exec)
		void CaptureRange();
	UFUNCTION(Exec)
		void ResetCapture();

	UPROPERTY(EditAnywhere, Category = "Transform Parameters")
		bool Location;

};


