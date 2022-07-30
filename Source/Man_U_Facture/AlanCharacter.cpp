// Fill out your copyright notice in the Description page of Project Settings.

#include "AlanCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "HealthComponent.h"
#include "HarvestTool.h"
#include "Resource.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"
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

	InteractRange = CreateDefaultSubobject<UBoxComponent>(TEXT("Interact Range"));
	InteractRange->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAlanCharacter::BeginPlay()
{
	Super::BeginPlay();
	//grabs the health component on the blueprint
	HealthComponent = FindComponentByClass<UHealthComponent>();
	//grabs the action cast component on the blueprint
	AlanController = UGameplayStatics::GetPlayerController(this,0);
	//checks to see if the health component is attached
	if(!HealthComponent)
	{
		UE_LOG(LogTemp,Error,TEXT("No Health Component Attached!"));
	}
}

// Called every frame
void AAlanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//TurnToMouse();
	RotateCharacter(DeltaTime, NewRotation);
	
	//checks to see if move speed has changed and sets the new speed on the component
	if(GetCharacterMovement()->MaxWalkSpeed != MoveSpeed)
	{
		GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
	}
	//checks the health component every frame if the character has died
	if(HealthComponent && HealthComponent->GetHasDied())
	{
		Die();
	}
}

// Called to bind functionality to input
void AAlanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

//smoothly rotates the controller to the clicked position
void AAlanCharacter::RotateCharacter(float DeltaTime, FRotator Direction)
{
	if(!AlanController) return;
	if(AlanController->GetControlRotation() != Direction)
	{
		FRotator SmoothRotation = FMath::RInterpTo(GetControlRotation(),Direction,DeltaTime,TurnSpeed);
		AlanController->SetControlRotation(SmoothRotation);
	}
}

//with a point and click interface, the entire ActionCast may be useless(I'm cool with that)
void AAlanCharacter::Interact(AActor* HitActor)
{
	if(AResource* Resource = Cast<AResource>(HitActor))
	{
		//check if player can harvest
		const FString Type = Resource->GetType();
		if(Type == "Wood")
		{
			UE_LOG(LogTemp,Warning,TEXT("Hit Wood!"));
		}
		else if(Type == "Metal")
		{
			UE_LOG(LogTemp,Warning,TEXT("Hit Metal"));
		}
		else if(Type == "Chemical")
		{
			UE_LOG(LogTemp,Warning,TEXT("Hit Chemical"));
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("No Type Found!"));
		}
		
	}
	//add logic for enemies and buildings
}


//Called on blueprint if player dies and any damage is taken
void AAlanCharacter::Die()
{
	//Shoves player off of controller
	DetachFromControllerPendingDestroy();
	//Plays death animation
	//The health component tells the game mode the player has died and the controller handles the UI
}