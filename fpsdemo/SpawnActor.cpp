// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActor.h"
#include "FloatingActor.h"
#include "Engine/World.h"

// Sets default values
ASpawnActor::ASpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float IntervalTime = 2.0f;
	BaseTime -= DeltaTime;

	if (BaseTime <= 0.0f)
	{
		BaseTime += IntervalTime;
		
		UWorld *const World = GetWorld();
		if (World)
		{
			FVector SpawnActorLocation = GetActorLocation();
			FRotator SpawnActorRotator = GetActorRotation();
			FActorSpawnParameters ActorParmas;
			ActorParmas.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;


			World->SpawnActor<AFloatingActor>(ProjectileActor, SpawnActorLocation, SpawnActorRotator, ActorParmas);
		}
	}
}

