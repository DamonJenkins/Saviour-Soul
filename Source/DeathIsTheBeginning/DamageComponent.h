// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActorDamaged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActorKilled);

UENUM()
enum Team {
	Good UMETA(DisplayName = "Good"),
	Bad UMETA(DisplayName = "Bad"),
	Neutral UMETA(DisplayName = "Neutral")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEATHISTHEBEGINNING_API UDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		bool Damage(float _amount, Team _damageSource);

	UFUNCTION(BlueprintCallable)
		bool Heal(float _amount, Team _healSource);

	UPROPERTY(BlueprintAssignable)
		FActorDamaged damagedEvent;

	UPROPERTY(BlueprintAssignable)
		FActorKilled killedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Team)
		TEnumAsByte<Team> team;

protected:

	UFUNCTION(BlueprintCallable)
		void SetHealth(float _health);

	UPROPERTY(BlueprintReadOnly)
		float health = 0;

	UPROPERTY(BlueprintReadOnly)
		float maxHealth = 0;
};
