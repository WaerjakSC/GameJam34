// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Wanderer.generated.h"

class ASimpleWaypoint;

UCLASS()
class GAMEJAM34_API AWanderer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWanderer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	bool showPath{ true };
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
		TArray<ASimpleWaypoint*>Waypoints;
	UPROPERTY(VisibleAnywhere, Category = AI)
		bool isLit{ false };
	UPROPERTY(EditAnywhere, Category = AI)
		bool showDebugLines{ true };
	// Called to bind functionality to input
};
