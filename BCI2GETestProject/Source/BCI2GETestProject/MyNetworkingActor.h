// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Networking.h"
#include "Serialization/Archive.h"
#include "MyNetworkingActor.generated.h"

class OSCPacket {
public:
	const FString mMentalCommand = "/com";
	const FString mMC_Neutral = "/com/neutral";
	const FString mMC_Push = "/com/push";
	const FString mMC_Pull = "/com/pull";
	const FString mMC_Left = "/com/left";
	const FString mMC_Right = "/com/right";
	const FString mMC_Lift = "/com/lift";
	const FString mMC_Drop = "/com/drop";

	OSCPacket() {

	};
	OSCPacket(uint8* data, int32 count) {
		mData	= data;
		mCount	= count;
	};
	uint8* mData;
	int32 mCount;
};

USTRUCT(BlueprintType)
struct FOSCData {
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OSCPacket")
	FString name = " NAme ";
};

FORCEINLINE FArchive& operator<<(FArchive& ar, FOSCData TheStruct) {
	ar << TheStruct.name;
	return ar;
};

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
	//Function to create string from 
	FString UDPBytesToString(const uint8* In, int32 Count);
	//Called at end of play to make sure the socket dont persist
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
