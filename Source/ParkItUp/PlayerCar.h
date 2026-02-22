// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCar.generated.h"

UCLASS()
class PARKITUP_API APlayerCar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private: 
	void MoveForward(float Value);
	void Turn(float Value);
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CarMesh;

	float CurrentSpeed;
	float MaxSpeed = 800.f;
	float Acceleration = 2000.f;
	float TurnSpeed = 120.f;

};
