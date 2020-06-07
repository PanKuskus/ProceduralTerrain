

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
