// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkGenerator.h"

// Sets default values
AChunkGenerator::AChunkGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChunkGenerator::BeginPlay()
{
	Super::BeginPlay();
	CreateChunk();
}

// Called every frame
void AChunkGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AChunkGenerator::CreateChunk()
{
	FActorSpawnParameters SpawnParams;
	for (int32 x = 0; x < 4; x++)
	{
		for (int32 y = 0; y < 4; y++)
		{
			for (int32 z = 0; z < 4; z++)
			{
				AChunk* SpawnedChunk = GetWorld()->SpawnActor<AChunk>(SpawnParams);
				SpawnedChunk->ChunkSetup(ChunkSize, PointsGap, CalculateChunkLocation(FIntVector(x, y, z)), IsoLevel, Material);
				SpawnedChunk->CreateMesh();

				LoadedChunks.Add(SpawnedChunk);
			}
		}
	}
	
}

FVector AChunkGenerator::CalculateChunkLocation(FIntVector Chunk)
{
	return FVector(ChunkSize-FIntVector(1)) * PointsGap * FVector(Chunk);
}
