// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grid.h"
#include "MarchingCube.h"
#include "ProceduralMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Chunk.generated.h"

UCLASS()
class PROCEDURALTERRAIN_API AChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();
	void CreateCubes();
	void UpdateCube(FIntVector CubePos);
	void ChunkSetup(FIntVector Size, FVector PointGap, FVector ChunkOffset, int32 IsoLevel, UMaterialInterface* _Material);

	int32 GetCubeNum(FIntVector CubePos);
	void CreateMesh();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UProceduralMeshComponent* CustomMesh;

	UPROPERTY(EditAnywhere)
		FIntVector Size;

	UPROPERTY(EditAnywhere)
		FVector PointGap;

	UPROPERTY(EditAnywhere)
		FVector ChunkOffset;

	UPROPERTY(EditAnywhere)
		int32 IsoLevel;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material;

	//UPROPERTY(EditAnywhere)
		TArray<FVector> MeshPoints;

	//UPROPERTY(EditAnywhere)
		TArray<int32> MeshTriangles;

		TArray<FLinearColor> VertexColors;

		Grid ChunkGrid;

		TArray<MarchingCube> Cubes;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
