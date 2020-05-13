// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGrid::AGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();

	spacingDistance = FVector(20.f, 20.f, 30.f);
	offset = FVector(1000.f, 600.f, 2000.f);
	size = 3;
	
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	createGrid();
	drawLines(DeltaTime);
}


void AGrid::drawGrid()
{
	for (int i = 0; i < points.Num(); i++)
	{
		DrawDebugPoint(GetWorld(), points[i].pointLocation, 50, FColor(52, 220, 239), true);
	}
}


void AGrid::drawLines(float time)
{
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			for (int z = 0; z < size; z++)
			{
				int size2 = size * size;
				int point = x * size2 + y * size + z;

				int leftPoint = (x + 1) * size2 + y * size + z;

				int backPoint = x * size2 + (y + 1) * size + z;

				int topPoint = x * size2 + y * size + (z + 1);

				FlushPersistentDebugLines(GetWorld());
				if (x != size-1)
				{
					DrawDebugLine(GetWorld(), points[point].pointLocation, points[leftPoint].pointLocation, FColor::Red, false, -1, 0, 1);
					
				}
				if (y != size - 1)
				{
					DrawDebugLine(GetWorld(), points[point].pointLocation, points[backPoint].pointLocation, FColor::Green, false, -1, 0, 1);
				}
				
				if (z != size - 1)
				{
					DrawDebugLine(GetWorld(), points[point].pointLocation, points[topPoint].pointLocation, FColor::Blue, false, -1, 0, 1);
				}
				
			}
		}
	}



}
void AGrid::createGrid()
{
	points.Empty();
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			for (int z = 0; z < size; z++)
			{
				FVector location = FVector(x * spacingDistance.X + offset.X, y * spacingDistance.Y + offset.Y, z * spacingDistance.Z + offset.Z);
				FIntVector pointNum = FIntVector(x, y, z);
				points.Add(FGridPoint(location, pointNum, 10));
			}
		}
	}
}