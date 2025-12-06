// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameMenu.h"

#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameMenu> StartingGameMenu;
	UGameMenu* GameMenuContainer;

	void SpawnGameMenu(TSubclassOf<UGameMenu> NewGameMenu);
};
