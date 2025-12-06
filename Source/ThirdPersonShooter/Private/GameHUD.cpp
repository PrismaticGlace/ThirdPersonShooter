// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

void AGameHUD::BeginPlay() {
	Super::BeginPlay();

	SpawnGameMenu(StartingGameMenu);
}


void AGameHUD::SpawnGameMenu(TSubclassOf<UGameMenu> NewGameMenu) {
	if (GameMenuContainer) {
		GameMenuContainer->RemoveFromParent();
		GameMenuContainer = nullptr;
	}

	GameMenuContainer = CreateWidget<UGameMenu>(GetWorld(), NewGameMenu);
	GameMenuContainer->AddToViewport();
}
