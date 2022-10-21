// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkingActor.h"

// Sets default values
ANetworkingActor::ANetworkingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANetworkingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANetworkingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

