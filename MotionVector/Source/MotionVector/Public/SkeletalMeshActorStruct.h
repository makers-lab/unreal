#pragma once

#include "Engine.h"
#include "Runtime/Engine/Classes/Animation/SkeletalMeshActor.h"

/*struct FSkeletalMeshActorStruct : public ASkeletalMeshActor
{
	TArray<FVector> SkeletalOldVertexPos; // this array keeps old vertex pos of all skeletal actors 
	TArray<FVector> SkeletalCurrVertexPos; // this array keeps curr vertex pos of all skeletal actors 

	FORCEINLINE bool operator==(const FSkeletalMeshActorStruct &otherActor) {
		return( (this->SkeletalOldVertexPos == otherActor.SkeletalOldVertexPos) && (this->SkeletalCurrVertexPos == otherActor.SkeletalCurrVertexPos));
	}

	
};*/


struct FSkeletalMeshActorVertexPos
{
	ASkeletalMeshActor *SkelMeshActor = nullptr;
	TArray<FVector> SkeletalOldVertexPos;// this array keeps old vertex pos of all skeletal actors 
	TArray<FVector> SkeletalCurrVertexPos; // this array keeps curr vertex pos of all skeletal actors
};

struct FStaticMeshActorVertexPos
{
	AStaticMeshActor *StatMeshActor = nullptr;
	TArray<FVector> StaticOldVertexPos;// this array keeps old vertex pos of all skeletal actors 
	TArray<FVector> StaticCurrVertexPos; // this array keeps curr vertex pos of all skeletal actors
};