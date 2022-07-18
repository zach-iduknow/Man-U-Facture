// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AlanCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UHealthComponent;
class UActionCast;
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
	
	APlayerController* AlanController;

	void TurnToMouse();

	void Move(float Value);

	void Die();

	//Used for harvesting and fighting
	void Attack();


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

	UPROPERTY(EditAnywhere, Category = "Stats")
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, Category="Action")
	UActionCast* ActionCast;
};
