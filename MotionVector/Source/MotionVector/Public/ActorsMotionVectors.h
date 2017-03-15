// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Editor.h"
#include "UnrealEd.h"


#include "SkeletalMeshActorStruct.h"
#include "GameFramework/Actor.h"

#include "ActorsMotionVectors.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class AActorsMotionVectors : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorsMotionVectors();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Vertex Color")
	void SetVertexColors(TArray <FVector> CurrPos, TArray <FVector> OldPos, TArray<FLinearColor> &Colors);

	UFUNCTION(BlueprintCallable, Category = "Vertex Color")
	UTexture2D* GetPixelData(UTextureRenderTarget2D * TextureRenderTarget);

	UFUNCTION(BlueprintCallable, Category = "Vertex Color")
	void GetVertexPositions(USkeletalMeshComponent * SkelMeshComp, TArray <FVector> &Positions
	);

	UFUNCTION(BlueprintCallable, Category = "Vertex Color")
	void GetSMVertexPositions(UStaticMeshComponent * StaticMeshComponent, TArray <FVector> &Positions);

	UFUNCTION(BlueprintCallable, Category = "Vertex Color")
	void SetSMVertexColors(UStaticMeshComponent * StaticMeshComp, TArray <FLinearColor> Colors);

	
private:

	TArray <FSkeletalMeshActorVertexPos> SkeletalMeshVerticesPositions;
	TArray <FStaticMeshActorVertexPos> StaticMeshVerticesPositions;


	int32 ViewPortXCoord = 0;
	int32 ViewPortYCoord = 0;


	TArray<FVector> SkelVertexPositions;
	TArray<FLinearColor> SkelVertexLinearColors;
	FVector2D SkelActorScreenPos;

	FVector SkelActorBoundLocationOrigin;
	FVector SkelActorBoundLocationBoxExtend;

 
	TArray<FVector> StatVertexPositions;
	TArray<FLinearColor> StatVertexLinearColors;
	FVector2D StatActorScreenPos;

	FVector StatActorBoundLocationOrigin;
	FVector StatActorBoundLocationBoxExtend;

	int32 InCrunch;
	int32 OutCrunch;
};
