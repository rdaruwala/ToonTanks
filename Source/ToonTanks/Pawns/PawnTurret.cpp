// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"

#include "RenderCore.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

APawnTurret::APawnTurret(){

}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
}

void APawnTurret::HandleDestruction() 
{
	Super::HandleDestruction();
	Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!PlayerPawn){
		return;
	}

	Super::RotateFunction(PlayerPawn->GetActorLocation());

}
void APawnTurret::CheckFireCondition() 
{
	// If Player is valid & within a certain range, then fire

	if(!PlayerPawn){
		return;
	}

	if(GetDistanceToPlayer() <= FireRange){
		Fire();
	}

	
}

float APawnTurret::GetDistanceToPlayer() 
{
	if(!PlayerPawn){
		return 0.0;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
