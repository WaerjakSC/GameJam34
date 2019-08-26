// Fill out your copyright notice in the Description page of Project Settings.


#include "GameJam34PlayerController.h"

AGameJam34PlayerController::AGameJam34PlayerController() 
{
	PrimaryActorTick.bCanEverTick = true;
	TeamId = FGenericTeamId(10);
}
FGenericTeamId AGameJam34PlayerController::GetGenericTeamId() const
{
	return TeamId;
}