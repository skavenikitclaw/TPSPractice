// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "tpsdemoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class tpsdemo_API AtpsdemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	virtual void StartPlay() override;
};
