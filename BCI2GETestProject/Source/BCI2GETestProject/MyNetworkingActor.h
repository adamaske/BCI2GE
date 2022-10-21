// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Networking.h"
#include "MyNetworkingActor.generated.h"

UCLASS()
class BCI2GETESTPROJECT_API AMyNetworkingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyNetworkingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//First setup regualr udp receiving 
	//A class for receving
	//The reciever needs an ip and a port to listen to
	char* mIP = "127.0.0.1";
	int32 mPORT = 5002;
	//Unreal class for async receiving upd socket data
	FUdpSocketReceiver* mReceiver;
	FSocket* mSocket;
	//Get port and ip
	void SetupReceiver(char* ip, int32 port);
	//Standard naming convetion for the function which Receives the data
	//What is a FArrayReaderPtr ??					The endpoint which the data is coming from
	void Recv(const FArrayReaderPtr& ArrayReaderPtr, const FIPv4Endpoint& EndPt);
};
