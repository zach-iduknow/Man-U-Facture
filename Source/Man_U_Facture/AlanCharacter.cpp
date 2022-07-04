// Fill out your copyright notice in the Description page of Project Settings.

#include "AlanCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "HealthComponent.h"
// Sets default values
AAlanCharacter::AAlanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);

	//Stops the camera from using relative rotation;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritRoll = false;
	CameraBoom->bInheritPitch = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void AAlanCharacter::BeginPlay()
{
	Super::BeginPlay();
	//grabs the health component on the blueprint
	HealthComponent = FindComponentByClass<UHealthComponent>();
	AlanController = UGameplayStatics::GetPlayerController(this,0);
	if(!HealthComponent)
	{
		UE_LOG(LogTemp,Error,TEXT("No Health Component Attached!"));
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Health Component Attached!"));
	}
}

// Called every frame
void AAlanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TurnToMouse();
}

// Called to bind functionality to input
void AAlanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &AAlanCharacter::Move);
	
}
//Gets the cursor's location and rotates controller in that direction
void AAlanCharacter::TurnToMouse()
{
	FHitResult Hit;
	//gets hit result from cursor location in world space
	
	if(!AlanController) return;
	AlanController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,Hit);
	FRotator LookDirection = UKismetMathLibrary::FindLookAtRotation(GetCapsuleComponent()->GetComponentLocation(),Hit.ImpactPoint);
	//this one goddamn line crashed the engine
	//VARIABLE NAME CONSISTENCY IS IMPORTANT
	AlanController->SetControlRotation(FRotator(0.f,LookDirection.Yaw,0.f));
}

void AAlanCharacter::Move(float Value)
{
	if(!AlanController) return;
	AddMovementInput(GetCapsuleComponent()->GetForwardVector(),Value * MoveSpeed);
}
