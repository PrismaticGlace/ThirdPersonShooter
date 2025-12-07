// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Attack.h"

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
    ABaseCharacter* player = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    AAIController* AIController = OwnerComp.GetAIOwner();
    
    player->OnHurtPlayer(5.0f);

    return EBTNodeResult::Succeeded;
}