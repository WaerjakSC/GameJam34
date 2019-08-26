// Fill out your copyright notice in the Description page of Project Settings.


#include "Wanderer.h"
#include "SimpleWaypoint.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Public/DrawDebugHelpers.h"

// Sets default values
AWanderer::AWanderer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->MaxWalkSpeed = 150.f;
}

// Called when the game starts or when spawned
void AWanderer::BeginPlay()
{
	Super::BeginPlay();
	if (showDebugLines) {

		for (auto i = 0; i < Waypoints.Num() - 1; i++)
		{
			FVector Waypoint1 = Cast<AActor>(Waypoints[i])->GetActorLocation();
			Waypoint1.Y += 30.f;
			FVector Waypoint2 = Cast<AActor>(Waypoints[i + 1])->GetActorLocation();
			Waypoint2.Y += 30.f;
			DrawDebugLine(GetWorld(), Waypoint1, Waypoint2, FColor::Red, true, -1, 0, 1);
		}
	}
}

// Called every frame
void AWanderer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


