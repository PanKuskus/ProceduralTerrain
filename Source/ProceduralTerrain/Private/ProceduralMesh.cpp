// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/ProceduralMesh.h"

// Sets default values
AProceduralMesh::AProceduralMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomMesh = CreateDefaultSubobject<UProceduralMeshComponent>("CustomMesh");
	SetRootComponent(CustomMesh);
	CustomMesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AProceduralMesh::BeginPlay()
{
	Super::BeginPlay();
	GenerateCubeMesh();
}

// Called every frame
void AProceduralMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CustomMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV, VertexColors, Tangents, true);

}

void AProceduralMesh::AddTriangle(int32 V1, int32 V2, int32 V3)
{
	Triangles.Add(V1);
	Triangles.Add(V2);
	Triangles.Add(V3);
}

void AProceduralMesh::GenerateCubeMesh()
{
	//6 sides on cube, 4 verts each (corners)

	//These are relative locations to the placed Actor in the world
	Vertices.Add(FVector(0, -40, 0)); //lower left - 0
	Vertices.Add(FVector(0, -100, 100)); //upper left - 1
	Vertices.Add(FVector(0, 100, 0)); //lower right - 2 
	Vertices.Add(FVector(0, 100, 100)); //upper right - 3

	
	//Back face of cube
	AddTriangle(0, 2, 3);
	AddTriangle(3, 1, 0);

	
	VertexColors.Add(FLinearColor(0.f, 0.f, 1.f));
	VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));

	UV.Add(FVector2D(0, 1));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(1, 1));
	UV.Add(FVector2D(1, 0));

	Normals.Add(FVector(-1, 0, 0));
	Normals.Add(FVector(-1, 0, 0));
	Normals.Add(FVector(-1, 0, 0));
	Normals.Add(FVector(-1, 0, 0));

	Tangents.Add(FProcMeshTangent(0, 1, 0));
	Tangents.Add(FProcMeshTangent(0, 1, 0));
	Tangents.Add(FProcMeshTangent(0, 1, 0));
	Tangents.Add(FProcMeshTangent(0, 1, 0));
	
}

