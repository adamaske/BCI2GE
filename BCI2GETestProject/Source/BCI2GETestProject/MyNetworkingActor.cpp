// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNetworkingActor.h"

// Sets default values
AMyNetworkingActor::AMyNetworkingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyNetworkingActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetupReceiver("127.0.0.1", 5700);
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Cyan, TEXT("Begin Player"));
}

// Called every frame
void AMyNetworkingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyNetworkingActor::SetupReceiver(char* ip, int32 port) {
	mIP = ip;
	mPORT = port;
	//Create and addres
	FIPv4Address Address;
	//Converts string to ipv4, first the string, then what FIPv4Addrress to output into
	FIPv4Address::Parse(mIP, Address);
	//Container for Ipv4Adress and port
	FIPv4Endpoint Endpoint(Address, mPORT);
	//							//The socket listens to our endpoint, we want specified buffer size
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, TEXT("Trying to make socket!"));
	const FString& SocketName = "Name";
	mSocket = FUdpSocketBuilder(*SocketName).AsNonBlocking().AsReusable().
		BoundToEndpoint(Endpoint).WithReceiveBufferSize(2 * 1024 * 1024);
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, TEXT("Made socket!"));

	FTimespan time = FTimespan::FromMicroseconds(100);
	//The socket it receives from, delay from this until it is open, Its multithreaded, name for the thread, debug only
	mReceiver = new FUdpSocketReceiver(mSocket, time, TEXT("UDPReceiver"));
	//OnDataReceived is called each time it gets data over the network, bind this function to our own recv 
	mReceiver->OnDataReceived().BindUObject(this, &AMyNetworkingActor::Recv);
	mReceiver->Start();

}

void AMyNetworkingActor::Recv(const FArrayReaderPtr& ArrayReaderPtr, const FIPv4Endpoint& EndPt) {
	if (!&ArrayReaderPtr) {
		GEngine->AddOnScreenDebugMessage(6, 5, FColor::Cyan, TEXT("Got Message"), 0);
		UE_LOG(LogTemp, Warning, TEXT("Cannot read array, nullptr returned."));
		return;
	}

	GEngine->AddOnScreenDebugMessage(5, 5, FColor::Cyan, TEXT("Got Message"));
}

void AMyNetworkingActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	delete mReceiver;
	mReceiver = nullptr;

	//Clear all sockets
	if (mSocket)
	{
		mSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(mSocket);
	}
}
