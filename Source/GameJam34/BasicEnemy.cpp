// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemy.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void ABasicEnemy::Tick(float DeltaTime)
{

}

ABasicEnemy::ABasicEnemy() 
	:Super()
{
	SetGenericTeamId(FGenericTeamId(5));
}
ETeamAttitude::Type ABasicEnemy::GetTeamAttitudeTowards(const AActor& Other) const
{

	if (const APawn* OtherPawn = Cast<APawn>(&Other)) {

		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			return Super::GetTeamAttitudeTowards(*OtherPawn->GetController());
		}
	}

	return ETeamAttitude::Neutral;
}