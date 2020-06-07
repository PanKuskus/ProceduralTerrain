// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



/**
 * 
 */
class PROCEDURALTERRAIN_API MarchingCube
{
public:
	MarchingCube(TArray<FVector> _CubeCornersLocations, TArray<int32> _CubeCornersValues, int32 _IsoLevel);
	~MarchingCube();
	void UpdateCube(TArray<FVector> _CubeCornersLocations, TArray<int32> _CubeCornersValues, int32 _IsoLevel);
	TArray<FVector> GetMeshPointsLocations();
	TArray<int32> GetMeshTriangles();
	int32 GetNumberOfTriangles();
private:

	void CalculateMeshPointsLocations();

	TArray<FVector> CubeCornersLocations;
	TArray<int32> CubeCornersValues;
	int32 IsoLevel;

	TArray<FVector> MeshPointsLocations;
	TArray<int32> Triangles;

	int32 NumberOfTriangles;
};
