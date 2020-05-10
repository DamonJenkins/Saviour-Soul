// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"

#define MOVEMENTSYSTEM 1

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsule = GetCapsuleComponent();
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Sideways", this, &APlayerCharacter::MoveRight);

}

void APlayerCharacter::MoveForward(float value)
{

#if MOVEMENTSYSTEM
	FRotator rot = capsule->GetComponentRotation();

	FVector MoveDir = FVector(1.0f, 0.0f, 0.0f);

	AddMovementInput(
		MoveDir.RotateAngleAxis(rot.Yaw, FVector(0.0f, 0.0f, 1.0f)),
		value
	);
#else

	AddMovementInput(
		FVector(1.0f, 0.0f, 0.0f),
		value
	);

#endif


	

}

void APlayerCharacter::MoveRight(float value)
{

#if MOVEMENTSYSTEM
	FRotator rot = capsule->GetComponentRotation();

	FVector MoveDir = FVector(0.0f, 1.0f, 0.0f);

	AddMovementInput(
		MoveDir.RotateAngleAxis(rot.Yaw, FVector(0.0f, 0.0f, 1.0f)),
		value
	);
#else

	AddMovementInput(
		FVector(0.0f, 1.0f, 0.0f),
		value
	);

#endif

}
