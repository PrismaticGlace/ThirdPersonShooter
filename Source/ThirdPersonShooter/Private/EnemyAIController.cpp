// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

AEnemyAIController::AEnemyAIController() {
	PrimaryActorTick.bCanEverTick = true;

	if (!PawnSensing) {
		PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
		PawnSensing->OnSeePawn.AddDynamic(this, &AEnemyAIController::OnSeePawn);
	}
}

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();

	RunBehaviorTree(StartingBehaviorTree);

}

void AEnemyAIController::OnSeePawn(APawn* SeenPawn) {
	ABaseCharacter* PlayerCharacter = Cast<ABaseCharacter>(SeenPawn);
	if (!PlayerCharacter) {
		return;
	}

	OnCanSeePlayer(true, SeenPawn);

	RunRetriggerableTimer();
}

void AEnemyAIController::OnCanSeePlayer(bool SeePlayer, UObject* PlayerObject) {
	UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
	BlackboardComp->SetValueAsBool("CanSeePlayer", SeePlayer);

	if (SeePlayer) {
		BlackboardComp->SetValueAsObject("Player", PlayerObject);
	}

}

void AEnemyAIController::RunRetriggerableTimer() {
	GetWorldTimerManager().ClearTimer(RetriggerableTimeHandle);
	FunctionDelegate.BindUFunction(this, FName("OnCanSeePlayer"), false, nullptr);
	GetWorldTimerManager().SetTimer(RetriggerableTimeHandle, FunctionDelegate, PawnSensing->SensingInterval * 2.0f, false);
}
