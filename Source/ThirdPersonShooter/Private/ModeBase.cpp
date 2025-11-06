// Fill out your copyright notice in the Description page of Project Settings.


#include "ModeBase.h"

void AModeBase::StartPlay() {
	Super::StartPlay();

	check(GEngine != nullptr);


	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Gih"));
}
