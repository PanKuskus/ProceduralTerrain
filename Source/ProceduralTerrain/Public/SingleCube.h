// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "SingleCube.generated.h"



struct FTRIANGLE
{
	FVector p[3];
};

USTRUCT()
struct FGRIDCELL
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere)
	FVector p[8];
	UPROPERTY(EditAnywhere)
	float val[8];
};


UCLASS()
class PROCEDURALTERRAIN_API ASingleCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASingleCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProceduralMeshComponent* CustomMesh;

	UPROPERTY(EditAnywhere)
	FGRIDCELL grid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float isolevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector offset;

	FTRIANGLE* TrianglesFromMarching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector> Vertices;

	// The triangles of the mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> Triangles;


	UPROPERTY(BlueprintReadWrite)
	TArray<FLinearColor> VertexColors;

	UPROPERTY(BlueprintReadWrite)
	TArray<FVector2D> UV;

	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> Normals;

	UPROPERTY(BlueprintReadWrite)
	TArray<FProcMeshTangent> Tangents;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int Polygonise(FGRIDCELL grid, float isolevel, FTRIANGLE* triangles);

	void GenerateMesh();

	void SetIsoLevel(float isolevel);

	void SetOffset(FVector offset);

	void SetValues(int32 values[8]);

};
