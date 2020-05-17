// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SingleCube.h"
#include "Chunk.generated.h"

UCLASS()
class PROCEDURALTERRAIN_API AChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		TArray<ASingleCube*> cubes;

	UPROPERTY(EditAnywhere, category = "ChunkSetup")
		int32 chunkSize;

	UPROPERTY(EditAnywhere, category = "ChunkSetup")
		float isolevel;

	UPROPERTY(EditAnywhere)
		TArray<int32> values;

	UPROPERTY(EditAnywhere)
		TArray<FVector> offsets;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ASingleCube> cubeClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void spawnChunk(FVector chunkLocation);

	void spawnCubes();

	void updateCubes();

};
