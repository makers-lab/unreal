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


#include "UMaterialTools.generated.h"

USTRUCT(Blueprintable)
struct FActorInstance
{
	GENERATED_BODY()
	AActor* mActor;
	UMaterialInterface* mMaterial;
	int32 mMaterialD;
	FActorInstance();
	FActorInstance(AActor* Actor, UMaterialInterface* Material, int32 MaterialD);
};


UCLASS(Blueprintable)
class UMaterialTools : public UFaustToolsBaseClass
{
	GENERATED_BODY()
public:
	UMaterialInstanceConstant* CreateAssetByParentMaterial(UMaterial* ParentMaterial, UMaterialInstanceConstantFactoryNew* Factory, FString* PathToAsset, FString* AssetName);
	TSet<UMaterial*> GetSelectedActorMaterials();
	TSet<UMaterial*> GetSelectedMaterialsInContentBrowser();
	
	UMaterialTools();

	virtual void PreEditChange(UProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void OnToolClosed() override;
	
	// List of existing material instance
	TMap< FString, UMaterialInstanceConstant* > InstanceList;
	
	UPROPERTY(EditAnywhere, Category = "Material for instance")
	UMaterial* BaseMaterialForInstance;

	UFUNCTION(Exec)
	void CreateInstance();

	UFUNCTION(BlueprintCallable, Category = "Faust Tools")
	static UTexture* GetTextureFromBaseMaterialNode(UMaterialInterface* material);

	static void NotificationBox(FString String, float FadeIn = 0.1f, float Expire = 1.5, float FadeOut = 1.f);

};


