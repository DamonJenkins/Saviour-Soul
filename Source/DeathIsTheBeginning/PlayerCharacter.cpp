// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	UE_LOG(LogTemp, Warning, TEXT("Your message"));
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

	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), value);

}

void APlayerCharacter::MoveRight(float value)
{

	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), value);

}
