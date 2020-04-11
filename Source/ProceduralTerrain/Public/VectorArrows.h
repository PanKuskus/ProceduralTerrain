// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"
#include "VectorArrows.generated.h"


USTRUCT()
struct FArrow
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector start;

	UPROPERTY(EditAnywhere)
	FVector vector;

	UPROPERTY(EditAnywhere)
	FVector transformedVector;

	UPROPERTY(EditAnywhere)
	FColor color {FColor::Black};

	UPROPERTY(EditAnywhere)
	float size{120.f};

	UPROPERTY(EditAnywhere)
	float thickness{5.f};

};

UCLASS()
class PROCEDURALTERRAIN_API AVectorArrows : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVectorArrows();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TArray<FArrow> arrows;

	UPROPERTY(EditAnywhere)
	FVector i {FVector(1.0, 0.0, 0.0)};

	UPROPERTY(EditAnywhere)
	FVector j {FVector(0.0, 1.0, 0.0)};

	UPROPERTY(EditAnywhere)
	FVector k {FVector(0.0, 0.0, 1.0)};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Draw();
};
