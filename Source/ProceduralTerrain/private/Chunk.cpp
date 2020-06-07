// Fill out your copyright notice in the Description page of Project Settings.


#include "Chunk.h"


// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CustomMesh = CreateDefaultSubobject<UProceduralMeshComponent>("CustomMesh");
	SetRootComponent(CustomMesh);
	CustomMesh->bUseAsyncCooking = true;
	

}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChunk::ChunkSetup(FIntVector _Size, FVector _PointGap, FVector _ChunkOffset, int32 _IsoLevel, UMaterialInterface* _Material)
{
	Material = _Material;
	MeshPoints.Init(FVector(), _Size.X * _Size.Y * _Size.Z * 12);
	VertexColors.Init(FLinearColor(), _Size.X * _Size.Y * _Size.Z * 12);
	Size = _Size;
	PointGap = _PointGap;
	ChunkOffset = _ChunkOffset;
	IsoLevel = _IsoLevel;

	CustomMesh->SetMaterial(0, Material);
	ChunkGrid = Grid(Size.X, Size.Y, Size.Z, PointGap, ChunkOffset);

	CreateCubes();
}

void AChunk::CreateMesh()
{
	CustomMesh->CreateMeshSection_LinearColor(0, MeshPoints, MeshTriangles, TArray<FVector>(), TArray<FVector2D>(), VertexColors, TArray<FProcMeshTangent>(), true);
}

void AChunk::CreateCubes()
{
	for (int32 X=0; X < Size.X-1; X++)
	{
		for (int32 Y=0; Y < Size.Y-1; Y++)
		{
			for (int32 Z=0; Z < Size.Z-1; Z++)
			{
				FIntVector CubePos = FIntVector(X, Y, Z);
				MarchingCube Cube = MarchingCube(ChunkGrid.GetCubePointsLocations(CubePos), ChunkGrid.GetCubePointsValues(CubePos), IsoLevel);
				Cubes.Add(Cube);
				UpdateCube(CubePos);
			}
		}
	}
}





void AChunk::UpdateCube(FIntVector CubePos)
{
	int32 CubeNum = GetCubeNum(CubePos);
	Cubes[CubeNum].UpdateCube(ChunkGrid.GetCubePointsLocations(CubePos), ChunkGrid.GetCubePointsValues(CubePos), IsoLevel);
	

	PerlinNoise perlin = PerlinNoise();

	TArray<FVector> CubePoints = Cubes[CubeNum].GetMeshPointsLocations();
	TArray<int32> CubeTriangles = Cubes[CubeNum].GetMeshTriangles();
	
	for (int32 i = 0; i < 12; i++)
	{
		MeshPoints[CubeNum * 12 + i] = CubePoints[i];

		float red = perlin.simplexNoise3D(CubePoints[i].X / 5000.f, 0.0, 0.0);
		float green = perlin.simplexNoise3D(CubePoints[i].Y / 5000.f, 0.0, 0.0);
		float blue = perlin.simplexNoise3D(CubePoints[i].Z / 5000.f, 0.0, 0.0);

		red = (red + 1) / 1.5;
		green = (green + 1) / 1.5;
		blue = (blue + 1) / 1.5;

		VertexColors[CubeNum * 12 + i] = FLinearColor(red, green, blue);
	}
	
	for (int32 i = 0; i < Cubes[CubeNum].GetNumberOfTriangles() * 3; i++)
	{
		//if(CubeTriangles.IsValidIndex(i))
			MeshTriangles.Add(CubeTriangles[i] + CubeNum * 12);
	}
	

}

int32 AChunk::GetCubeNum(FIntVector CubePos)
{
	int32 CubeNum = (CubePos.X * (Size.Z-1) * (Size.Y-1)) + (CubePos.Y * (Size.Z-1)) + (CubePos.Z);
	return CubeNum;
}