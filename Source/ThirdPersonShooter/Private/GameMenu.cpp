// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMenu.h"

void UGameMenu::NativeConstruct() {
	Super::NativeConstruct();

	UpdateHealthBar(1.0f);
	SetTimerText(60);
	SetScoreText(0);
	SetWaveText(1);
}

void UGameMenu::UpdateHealthBar(float healthPercent) {
	if (!healthBar) return;

	healthBar->SetPercent(healthPercent);
}

void UGameMenu::SetTimerText(int timer) {
	if (!timerText) return;

	timerText->SetText(FText::FromString("Timer: " + FString::FromInt(timer)));
}

void UGameMenu::SetScoreText(int amount) {
	if (!scoreText) return;

	UIscore += amount;
	scoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIscore)));
}

void UGameMenu::SetWaveText(int number) {
	if (!waveText) return;

	waveText->SetText(FText::FromString("Wave: " + FString::FromInt(number)));
}
