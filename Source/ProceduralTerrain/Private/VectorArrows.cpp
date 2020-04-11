// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorArrows.h"

// Sets default values
AVectorArrows::AVectorArrows()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVectorArrows::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVectorArrows::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Draw();

}

void AVectorArrows::Draw()
{
	for (int32 index = 0; index<arrows.Num(); index++)
	{
		FVector start = arrows[index].start;
		FVector vector = arrows[index].vector;
		vector = vector.X * i + vector.Y * j + vector.Z * k;
		arrows[index].transformedVector = vector;
		vector *= 100;
		start = arrows[index].start * 100;
		
		DrawDebugDirectionalArrow(GetWorld(), start, vector + start, arrows[index].size, arrows[index].color, false, 0.0, 0, arrows[index].thickness);
	}
	
	

	DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + i * 100, 100.0, FColor::Red, false, 0.0, 0, 2.5);
	DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + j * 100, 100.0, FColor::Green, false, 0.0, 0, 2.5);
	DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + k * 100, 100.0, FColor::Blue, false, 0.0, 0, 2.5);

}

