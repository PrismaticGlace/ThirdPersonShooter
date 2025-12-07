// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "BTT_GetRandomPatrolLocation.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UBTT_GetRandomPatrolLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	FVector RandomLocation;
	UNavigationSystemV1* NavSystem;


	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
