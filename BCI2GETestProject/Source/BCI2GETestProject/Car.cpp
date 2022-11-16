// Fill out your copyright notice in the Description page of Project Settings.

#include "Car.h"
#include "Components/CapsuleComponent.h"
#include "Components/MeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACar::ACar()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	SetRootComponent(CapsuleComp);

	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ACar::BeginPlay()
{
	Super::BeginPlay();
	//InitLocation = CapsuleComp->GetComponentLocation();
}

// Called every frame
void ACar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RootComponent->AddRelativeLocation(FVector{ ForwardValue + 0.2f, RightValue * 0.5f, 0.f } *MoveSpeed);
	//AddActorLocalOffset(FVector{ ForwardValue + 0.2f, RightValue * 0.5f, 0.f } *MoveSpeed);
}

// Called to bind functionality to input
void ACar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent != nullptr);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Forward", this, &ACar::MoveForward);
	InputComponent->BindAxis("Right", this, &ACar::MoveRight);
}

void ACar::MoveForward(float Value)
{
	ForwardValue = Value;
	UE_LOG(LogTemp,Warning, TEXT("forward"));
}

void ACar::MoveRight(float Value)
{
	RightValue = Value;
}