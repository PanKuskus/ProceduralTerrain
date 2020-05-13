// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralMesh.generated.h"


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
		double val[8];
};


UCLASS()
class PROCEDURALTERRAIN_API AProceduralMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralMesh();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProceduralMeshComponent* CustomMesh;

	FTRIANGLE* TrianglesFromMarching;

	UPROPERTY(EditAnywhere)
	FGRIDCELL grid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float isolevel;

	// The vertices of the mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Vertices;

	// The triangles of the mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> Triangles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLinearColor> VertexColors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> UV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Normals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FProcMeshTangent> Tangents;

	void AddTriangle(int32 V1, int32 V2, int32 V3);

	void GenerateMesh();

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int Polygonise(FGRIDCELL grid, float isolevel, FTRIANGLE* triangles);
};
