// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DeathIsTheBeginningGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DEATHISTHEBEGINNING_API ADeathIsTheBeginningGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	public: 

	virtual void Tick(float _dTime) override;

};
