// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameJam34Character.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AGameJam34Character

AGameJam34Character::AGameJam34Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Setup the flashlight transforms
	Flashlight = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Flashlight"));
	Flashlight->SetupAttachment(FirstPersonCameraComponent);
	Flashlight->RelativeLocation = FVector(-20.f, 58.f, -174.f); 
	Flashlight->RelativeRotation = FRotator(0.f, -90.f, 0.f);
	Flashlight->RelativeScale3D = FVector(0.6f, 0.6f, 0.6f);

}

void AGameJam34Character::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

}

//////////////////////////////////////////////////////////////////////////
// Input

void AGameJam34Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AGameJam34Character::OnFire);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AGameJam34Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGameJam34Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AGameJam34Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGameJam34Character::LookUpAtRate);
}

void AGameJam34Character::OnFire()
{
	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{

	}
}

void AGameJam34Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AGameJam34Character::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AGameJam34Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGameJam34Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
