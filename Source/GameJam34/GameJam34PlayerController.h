// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "GameJam34PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM34_API AGameJam34PlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
public:
	AGameJam34PlayerController();
private:
	// Implement The Generic Team Interface 
	FGenericTeamId TeamId;
	FGenericTeamId GetGenericTeamId() const;
};
