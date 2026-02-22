// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCar.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"

// Sets default values
APlayerCar::APlayerCar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarMesh"));
	RootComponent = CarMesh;

	CurrentSpeed = 0.f;

}

// Called when the game starts or when spawned
void APlayerCar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(CurrentSpeed))
	{
		FVector ForwardMove = GetActorForwardVector() * CurrentSpeed * DeltaTime;
		AddActorWorldOffset(ForwardMove, true);

	}
}
void APlayerCar::MoveForward(float Value)
{
	if (Value != 0.f)
	{
		CurrentSpeed = FMath::Clamp(
			CurrentSpeed + Value * Acceleration * GetWorld()->GetDeltaSeconds(),
			-MaxSpeed,
			MaxSpeed
		);
	}
	else {
		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, 0.f, GetWorld()->GetDeltaSeconds(), 3.f);
	}

}
void APlayerCar::Turn(float Value)
{
	if (Value != 0.f)
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += Value * TurnSpeed * GetWorld()->GetDeltaSeconds();
		SetActorRotation(NewRotation);
	}
}

// Called to bind functionality to input
void APlayerCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCar::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCar::Turn);

}

