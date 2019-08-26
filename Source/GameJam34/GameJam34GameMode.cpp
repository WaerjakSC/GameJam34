// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameJam34GameMode.h"
#include "GameJam34HUD.h"
#include "GameJam34Character.h"
#include "UObject/ConstructorHelpers.h"

AGameJam34GameMode::AGameJam34GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/Player/FirstPersonCharacter"));
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassFinder(TEXT("/Game/Blueprints/Player/BP_GameJam34PlayerController"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	PlayerControllerClass = PlayerControllerClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGameJam34HUD::StaticClass();
}
