// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawnCamera.generated.h"

UCLASS()
class MYPROJECTSNAKE_API AMyPawnCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawnCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//корневой блок для модели камеры
	UPROPERTY(EditAnywhere) class UBoxComponent* MyRootComponent;

	//штатив для камеры
	UPROPERTY(EditAnywhere) class USpringArmComponent* CameraSpring;

	//Камера персонажа
	UPROPERTY(EditAnywhere) class UCameraComponent* MyCamera;
	
};
