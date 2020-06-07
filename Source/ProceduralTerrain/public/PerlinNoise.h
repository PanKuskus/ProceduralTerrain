// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PROCEDURALTERRAIN_API PerlinNoise
{
public:
	PerlinNoise();
	~PerlinNoise();

	double simplexNoise3D(double x, double y, double z);
};
