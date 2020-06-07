// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"
#include "GameFramework/Actor.h"
#include "ChunkGenerator.generated.h"

UCLASS()
class PROCEDURALTERRAIN_API AChunkGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunkGenerator();
	FVector CalculateChunkLocation(FIntVector Chunk);
	void CreateChunk();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		TArray<AChunk*> LoadedChunks;

	UPROPERTY(EditAnywhere, category = "ChunkSetup")
		FIntVector ChunkSize;

	UPROPERTY(EditAnywhere, category = "ChunkSetup")
		FVector PointsGap;

	UPROPERTY(EditAnywhere, category = "ChunkSetup")
		int32 IsoLevel;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
