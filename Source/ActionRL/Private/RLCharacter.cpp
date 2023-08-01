// Fill out your copyright notice in the Description page of Project Settings.


#include "RLCharacter.h"

#include "VectorTypes.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARLCharacter::ARLCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom")); 
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->SetupAttachment(RootComponent); //Links the camera component to transformations applied to Root Component
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(CameraBoom);//Links the camera component to transformations applied to Root Component
	CameraComp->bUsePawnControlRotation = true;
	
}

// Called when the game starts or when spawned
void ARLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARLCharacter::MoveForward(float value)
{
	AddMovementInput(CameraComp->GetForwardVector(), value);
}

void ARLCharacter::MoveBackward(float value)
{
	AddMovementInput(-CameraComp->GetForwardVector(), value);
}

void ARLCharacter::MoveLeft(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(-RightVector, value);
}
void ARLCharacter::MoveRight(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector, value);
}
// Called to bind functionality to input
void ARLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARLCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveBackwards", this, &ARLCharacter::MoveBackward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &ARLCharacter::MoveLeft);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARLCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookYaw", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookPitch", this, &APawn::AddControllerPitchInput);


}

