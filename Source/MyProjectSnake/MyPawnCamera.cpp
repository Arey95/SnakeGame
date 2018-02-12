// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawnCamera.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"

// Sets default values
AMyPawnCamera::AMyPawnCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// создаем корневой компонент для камеры
	MyRootComponent = CreateDefaultSubobject<UBoxComponent>("RootModel");
	//Добавляем блок к пешке
	RootComponent = MyRootComponent;

	//Создадим штатив для камеры
	CameraSpring = CreateDefaultSubobject<USpringArmComponent>("Spring");
	//Устанавливаем позицию штатива
	CameraSpring->SetRelativeLocation(FVector(0, 0, 0));
	//Прикручиваем его к камере
	CameraSpring->AttachTo(MyRootComponent);

	//создаем камеру
	MyCamera = CreateDefaultSubobject<UCameraComponent>("Camera");
	//Прикрепляем камеру к штативу
	MyCamera->AttachTo(CameraSpring, USpringArmComponent::SocketName);
	//Устанавливаем поворот штатива
	CameraSpring->SetRelativeRotation(FRotator(-90.f, 0, 0));
	//Уставливаем Длинну штатива
	CameraSpring->TargetArmLength = 1700.f;
	//Отключаем проверку на столкновение с камерой
	CameraSpring->bDoCollisionTest = false;
}

// Called when the game starts or when spawned
void AMyPawnCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawnCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawnCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

