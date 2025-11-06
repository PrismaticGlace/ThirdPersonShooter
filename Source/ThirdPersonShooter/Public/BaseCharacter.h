// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
//#include "Camera/SpringArmComponent.h" Need to find how to include the spring arm
#include "RifleFire.h"

//Keep at the end
#include "BaseCharacter.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ARifleFire> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Moving Forward/Back
	UFUNCTION()
	void MoveForward(float value);

	//Moving Right/Left
	UFUNCTION()
	void MoveRight(float value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	UFUNCTION()
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;
};
