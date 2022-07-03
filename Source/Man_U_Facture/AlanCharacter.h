// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AlanCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
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
	
	void TurnToMouse();

	void Move(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category="Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, Category="Movement")
	float MoveSpeed = 100.f;
};