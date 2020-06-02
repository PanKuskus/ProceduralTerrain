// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ChunkMesh.generated.h"

UCLASS()
class PROCEDURALTERRAIN_API AChunkMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunkMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	void CreatePoints();

	void CreateMeshSection(FIntVector SectionLocation);
	void CalculateMesh(FIntVector SectionLocation);
	FVector VertexInterp(int32 IsoLevel, FVector Point1, FVector Point2, int32 ValueP1, int32 ValueP2);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProceduralMeshComponent* CustomMesh;

	//Level of detail of our mesh
	UPROPERTY(EditAnywhere)
	FIntVector NumberOfPoints;	

	//How close are Points. Used for LOD.
	//PointGap * NumberOfPoints = Chunk Size
	UPROPERTY(EditAnywhere)
	FVector PointGap;

	//Chunk location
	UPROPERTY(EditAnywhere)
	FVector Offset;

	UPROPERTY(EditAnywhere)
	int32 IsoLevel;

	//Array of points values. How much point is above or bellow surface
	UPROPERTY(EditAnywhere)
	TArray<int32> PointsValues;

	//Mesh points in single MarchingCube
	TArray<FVector> MeshSectionPoints;

	TArray<int32> SectionTriangles;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Used for setting points values
	void SetPointValue(int32 value, FIntVector Location);
	int32 GetPointValue(FIntVector Location);
	
};
