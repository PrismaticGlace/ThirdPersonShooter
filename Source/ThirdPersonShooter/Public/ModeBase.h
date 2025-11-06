// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

//Keep at the end
#include "ModeBase.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API AModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
};
