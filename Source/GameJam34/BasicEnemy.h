// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BasicEnemy.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM34_API ABasicEnemy : public AAIController
{
	GENERATED_BODY()
public:
	void Tick(float DeltaTime);

private:



	
};
