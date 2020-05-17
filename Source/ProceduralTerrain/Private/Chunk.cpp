// Fill out your copyright notice in the Description page of Project Settings.


#include "Chunk.h"

// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	chunkSize = 5;
}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();
	spawnChunk(FVector(0.f, 0.f, 0.f));
	spawnCubes();
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateCubes();
}

void AChunk::spawnChunk(FVector chunkLocation)
{
	offsets.Empty();
	values.Empty();
	for (int32 x = 0; x < chunkSize; x++)
	{
		for (int32 y = 0; y < chunkSize; y++)
		{
			for (int32 z = 0; z < chunkSize; z++)
			{
				offsets.Add(FVector(x * 100.f, y * 100.f, z * 100.f) + chunkLocation);

				if (z < 1)
				{
					values.Add(0);
				}
				else if (z == 1)
				{
					values.Add(10);
				}
				else values.Add(20);
				
			}

		}
	}
}


void AChunk::updateCubes()
{
	int32 index[8];
	int32 num = 0;
	for (int32 x = 0; x < chunkSize - 1; x++)
	{
		for (int32 y = 0; y < chunkSize - 1; y++)
		{
			for (int32 z = 0; z < chunkSize - 1; z++)
			{
				
				index[0] = x * chunkSize * chunkSize + y * chunkSize + z;
				index[1] = (x + 1) * chunkSize * chunkSize + y * chunkSize + z;
				index[2] = (x + 1) * chunkSize * chunkSize + (y + 1) * chunkSize + z;
				index[3] = x * chunkSize * chunkSize + (y + 1) * chunkSize + z;
				index[4] = x * chunkSize * chunkSize + y * chunkSize + (z + 1);
				index[5] = (x + 1) * chunkSize * chunkSize + y * chunkSize + (z + 1);
				index[6] = (x + 1) * chunkSize * chunkSize + (y + 1) * chunkSize + (z + 1);
				index[7] = x * chunkSize * chunkSize + (y + 1) * chunkSize + (z + 1);

				int32 pointsValues[8];
				
				for (int32 i = 0; i < 8; i++)
				{
					if (values.IsValidIndex(index[i]))
					{
						pointsValues[i] = values[index[i]];
					}
					else pointsValues[i] = 40;
				}
				if (cubes.IsValidIndex(num))
				{
					cubes[num]->SetValues(pointsValues);
					cubes[num]->SetIsoLevel(isolevel);
				}
				
				num++;
			}
		}
	}
}

void AChunk::spawnCubes()
{
	int32 index;
	for (int32 x = 0; x < chunkSize-1; x++)
	{
		for (int32 y = 0; y < chunkSize-1; y++)
		{
			for (int32 z = 0; z < chunkSize-1; z++)
			{
			index = x * chunkSize * chunkSize + y * chunkSize + z;
			

			FActorSpawnParameters SpawnParams;
			ASingleCube* SpawnedCube = GetWorld()->SpawnActor<ASingleCube>(cubeClass, SpawnParams);

			while (!offsets.IsValidIndex(index));

			SpawnedCube->SetOffset(offsets[index]);

			cubes.Add(SpawnedCube);
			}
		}
	}
}