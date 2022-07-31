// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TraceQueryTestResults.h"
#include "GameFramework/Character.h"
#include "AlanCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UHealthComponent;
class UActionCast;
class UBoxComponent;
UCLASS()
class MAN_U_FACTURE_API AAlanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAlanCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	APlayerController* AlanController;

	void TurnToMouse();

	void Move(float Value);

	//using this to test a point and click move system
	void ClickMove();

	//used to rotate pawn to new location
	void RotateCharacter(float DeltaTime, FRotator Direction = FRotator::ZeroRotator);
	void Die();

	//function to see what player clicked on and what to do
	UFUNCTION(BlueprintCallable, Category="Interaction")
	void Interact(AActor* HitActor);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, Category="Movement")
	FRotator NewRotation;

private:
	UPROPERTY(EditAnywhere, Category="Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, Category="Interaction")
	UBoxComponent* InteractRange;
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float MoveSpeed = 600.f;
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnSpeed = 12.f;
	
	UPROPERTY(EditAnywhere, Category = "Stats")
	UHealthComponent* HealthComponent;
	

};
