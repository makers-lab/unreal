#pragma once
#include "Engine.h"
#include "ModuleManager.h"
#include "EditorTool.h"
#include "UMotionVector.generated.h"

class FMVTickObject;


DECLARE_LOG_CATEGORY_EXTERN(MVEditor, All, All)


class USkeletalMeshComponent;
class UStaticMeshComponent;
class ASkeletalMeshActor;
class AStaticMeshActor;

UCLASS(Blueprintable)
class UMotionVector : public UEditorTool
{
	GENERATED_BODY()
private:
	struct FSkeletalMeshActorVerticesPosition
	{
		ASkeletalMeshActor *SkeletalMeshActor = nullptr;
		TArray<FVector> SkeletalOldVerticesPosition;// this array keeps old vertex pos of all skeletal actors 
		TArray<FVector> SkeletalCurrVerticesPosition; // this array keeps curr vertex pos of all skeletal actors

		static bool HasActor(TArray<FSkeletalMeshActorVerticesPosition> SkelActors, ASkeletalMeshActor *SkelMeshActor);
	};

	struct FStaticMeshActorVerticesPosition
	{
		AStaticMeshActor *StaticMeshActor = nullptr;
		TArray<FVector> StaticOldVerticesPos;// this array keeps old vertex pos of all skeletal actors 
		TArray<FVector> StaticCurrVerticesPos; // this array keeps curr vertex pos of all skeletal actors

		static bool HasActor(TArray<FStaticMeshActorVerticesPosition> StatActors, AStaticMeshActor *StatMeshActor);
	};

	
public:
	UMotionVector();

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void OnToolClosed() override;

	void Tick(float DeltaTime);

	void MotionVectors(FWorldContext* WorldContext, FVector CameraLocation, bool bWasCalledInitConponentsForCurrentWorld);
	void BakeVerticesColor(TArray <FVector> CurrPos, TArray <FVector> OldPos, TArray<FLinearColor> &Colors);
	void GetSkeletalMeshVerticesPosition(USkeletalMeshComponent* SkeletalMeshComponent, TArray <FVector> &Positions, FVector CameraLocation);
	void GetStaticMeshVerticesPosition(UStaticMeshComponent* StaticMeshComponent, TArray <FVector> &Positions, FVector CameraLocation);
	void SetStaticMeshVerticesColors(UStaticMeshComponent* StaticMeshComponent, TArray <FLinearColor> Colors);

	//Return true if at least one skeletal actor is present on scene
	bool GetAllSkeletalActorsOnScene(
		/*Fill this array with skeletal actors */
		TArray <FSkeletalMeshActorVerticesPosition> &SkelMeshes,
		FWorldContext *WorldContext
	);

	//Return true if at least one static actor is present on scene
	bool GetAllStaticActorsOnScene(
		/*Fill this array with static actors */
		TArray <FStaticMeshActorVerticesPosition> &StatMeshes,
		FWorldContext *WorldContext
	);

	static void NotificationBox(FString String, float FadeIn = 0.1f, float Expire = 1.5, float FadeOut = 1.f);

	UPROPERTY(EditAnywhere, Category = "Commands")
	bool GenerateMotionVectors;

	UPROPERTY(EditAnywhere, Category = "Commands")
	bool IncludeCamera;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	float ColorMultiply;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	float MinSpeed;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	float MaxSpeed;

private:
	void InitComponents(FWorldContext* WorldContext);

	/*
	* param Option: if true - creates tick object, false - delete if exists
	*/
	void ManageTickObject(bool Option);

	bool bWasCalledInitConponentsForPIE;
	bool bWasCalledInitConponentsForEditor;
	
	TArray <FSkeletalMeshActorVerticesPosition> SkeletalMeshes;
	TArray <FStaticMeshActorVerticesPosition> StaticMeshes;
	int32 SkeletalMeshesCurrNum;
	int32 StaticMeshesCurrNum;
	FMVTickObject* TickObject = nullptr;
};