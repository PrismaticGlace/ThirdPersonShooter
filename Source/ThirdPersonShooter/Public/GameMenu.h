// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "ButtonWidget.h"
#include "GameMenu.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UGameMenu : public UUserWidget {
	GENERATED_BODY()
	

public:
	int UIscore;

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (bindWidget))
	UProgressBar* healthBar;

	UPROPERTY(meta = (bindWidget))
	UTextBlock* timerText;

	UPROPERTY(meta = (bindWidget))
	UTextBlock* scoreText;

	UPROPERTY(meta = (bindWidget))
	UTextBlock* waveText;

	UPROPERTY(meta = (bindWidget))
	UVerticalBox* buttonContainer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> ButtonWidgetClass;

	UFUNCTION()
	void UpdateHealthBar(float healthPercent);

	UFUNCTION()
	void SetTimerText(int timer);

	UFUNCTION()
	void SetScoreText(int amount);

	UFUNCTION()
	void SetWaveText(int number);

private:

};
