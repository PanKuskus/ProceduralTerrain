// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"
Grid::Grid()
{

}


Grid::Grid(int32 _sizeX, int32 _sizeY, int32 _sizeZ, FVector _gap, FVector _offset)
{
	sizeX = _sizeX;
	sizeY = _sizeY;
	sizeZ = _sizeZ;

	SetGap(_gap);
	SetOffset(_offset);

	CreatePoints();
}

Grid::~Grid()
{
}


void Grid::CreatePoints()
{
	PerlinNoise perlin = PerlinNoise();
	values.Empty();
	values.Init(0, sizeX * sizeY * sizeZ);

	points.Empty();
	points.Init(FVector(), sizeX * sizeY * sizeZ);


	for (int32 X = 0; X < sizeX; X++)
	{
		for (int32 Y = 0; Y < sizeY; Y++)
		{
			for (int32 Z = 0; Z < sizeZ; Z++)
			{
				FVector pointLocation = FVector(X, Y, Z) * gap + offset;
				FIntVector point = FIntVector(X, Y, Z);
				SetPointLocation(pointLocation, point);
					
				float value = (perlin.simplexNoise3D(pointLocation.X / 2000.f, pointLocation.Y / 2000.f, pointLocation.Z / 2000.f) + 1) * 100.f;
				SetValue(value, point);
				//UE_LOG(LogTemp, Warning, TEXT("value, %f"), value);
			}
		}
	}
}

int32 Grid::GetValue(FIntVector point)
{
	int32 index = (point.X * sizeZ * sizeY) + (point.Y * sizeZ) + (point.Z);
	if (values.IsValidIndex(index))
		return values[index];
	else
		return -1;
}

void Grid::SetValue(int32 value, FIntVector point)
{
	int32 index = (point.X * sizeZ * sizeY) + (point.Y * sizeZ) + (point.Z);
	if (values.IsValidIndex(index))
		values[index] = value;
}


void Grid::SetGap(FVector _gap)
{
	gap = _gap;
}

void Grid::SetOffset(FVector _offset)
{
	offset = _offset;
}

void Grid::SetPointLocation(FVector location, FIntVector point)
{
	int32 index = (point.X * sizeZ * sizeY) + (point.Y * sizeZ) + (point.Z);
	if (points.IsValidIndex(index))
		points[index] = location;
}

FVector Grid::GetPointLocation(FIntVector point)
{
	int32 index = (point.X * sizeZ * sizeY) + (point.Y * sizeZ) + (point.Z);
	if (points.IsValidIndex(index))
		return points[index];
	return FVector();
}

TArray<FVector> Grid::GetCubePointsLocations(FIntVector cubeNum)
{
	TArray<FVector> pointsLocations;

	pointsLocations.Add(GetPointLocation(cubeNum + FIntVector(0, 0, 0)));
	pointsLocations.Add(GetPointLocation(cubeNum + FIntVector(1, 0, 0)));
	pointsLocations.Add(GetPointLocation(cubeNum + FIntVector(1, 1, 0)));
	pointsLocations.Add(GetPointLocation(cubeNum + FIntVector(0, 1, 0)));
	pointsLocations.Add(GetPointLocation(cubeNum + FIntVector(0, 0, 1)));
	pointsLocations.Add(GetPointLocation(cubeNum + FIntVector(1, 0, 1)));
	pointsLocations.Add(GetPointLocation(cubeNum + FIntVector(1, 1, 1)));
	pointsLocations.Add(GetPointLocation(cubeNum + FIntVector(0, 1, 1)));

	return pointsLocations;
}
TArray<int32> Grid::GetCubePointsValues(FIntVector cubeNum)
{
	TArray<int32> pointsValues;

	pointsValues.Add(GetValue(cubeNum + FIntVector(0, 0, 0)));
	pointsValues.Add(GetValue(cubeNum + FIntVector(1, 0, 0)));
	pointsValues.Add(GetValue(cubeNum + FIntVector(1, 1, 0)));
	pointsValues.Add(GetValue(cubeNum + FIntVector(0, 1, 0)));
	pointsValues.Add(GetValue(cubeNum + FIntVector(0, 0, 1)));
	pointsValues.Add(GetValue(cubeNum + FIntVector(1, 0, 1)));
	pointsValues.Add(GetValue(cubeNum + FIntVector(1, 1, 1)));
	pointsValues.Add(GetValue(cubeNum + FIntVector(0, 1, 1)));

	return pointsValues;
}