// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleWaypoint.h"

// Sets default values
ASimpleWaypoint::ASimpleWaypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimpleWaypoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

