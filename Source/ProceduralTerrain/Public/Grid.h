// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

USTRUCT()
struct FGridPoint
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere)
	FVector pointLocation;

	UPROPERTY(VisibleAnywhere)
	FIntVector point;

	UPROPERTY(VisibleAnywhere)
	int value;

	FGridPoint(){}

	FGridPoint(FVector _pointLocation, FIntVector _point, int _value)
	{
		pointLocation = _pointLocation;
		point = _point;
		value = _value;
	}
};


UCLASS()
class PROCEDURALTERRAIN_API AGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	FVector spacingDistance;

	UPROPERTY(EditAnywhere)
	int size;
	
	UPROPERTY(EditAnywhere)
	FVector offset;

public:	
	//UPROPERTY(VisibleAnywhere)
	TArray<FGridPoint> points;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void createGrid();

	void drawGrid();

	void drawLines(float time);
};
