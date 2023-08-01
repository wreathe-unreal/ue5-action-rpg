// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "RLCharacter.generated.h"

UCLASS()
class ACTIONRL_API ARLCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARLCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveForward(float value);
	void MoveBackward(float value);
	void MoveLeft(float X);
	void MoveRight(float X);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
