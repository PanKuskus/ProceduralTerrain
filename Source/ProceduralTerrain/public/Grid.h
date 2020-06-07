// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PerlinNoise.h"

/**
 * 
 */
class PROCEDURALTERRAIN_API Grid
{
public:

	Grid();
	Grid(int32 _sizeX, int32 _sizeY, int32 _sizeZ, FVector _gap, FVector _offset);
	~Grid();


	void SetGap(FVector gap);
	void SetOffset(FVector offset);

	void CreatePoints();
	void SetPointLocation(FVector location, FIntVector point);

	int32 GetValue(FIntVector point);
	void SetValue(int32 value, FIntVector point);
	FVector GetPointLocation(FIntVector point);
	TArray<FVector> GetCubePointsLocations(FIntVector cubeNum);
	TArray<int32> GetCubePointsValues(FIntVector cubeNum);


private:
	int32 sizeX;
	int32 sizeY;
	int32 sizeZ;
	FVector gap;
	FVector offset;
	TArray<int32> values;
	TArray<FVector> points;

};
