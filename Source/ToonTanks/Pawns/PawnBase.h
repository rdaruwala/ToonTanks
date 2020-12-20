// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="DEMO")
	int VisibleAnywhere;

	UPROPERTY(VisibleDefaultsOnly, Category="DEMO")
	int VisibleDefaultsOnly;

	UPROPERTY(VisibleInstanceOnly, Category="DEMO")
	int VisibleInstanceOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DEMO")
	int EditAnywhere;

	UPROPERTY(EditDefaultsOnly, Category="DEMO")
	int EditDefaultsOnly;

	UPROPERTY(EditInstanceOnly, Category="DEMO")
	int EditInstanceOnly;


private:
	// Components
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))	
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))	
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))	
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category="Components", meta=(AllowPrivateAccess = "true"))	
	USceneComponent* ProjectileSpawnPoint;

	// Variables
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Projectile Type", meta=(AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;

protected:
	void RotateFunction(FVector LookAtTarget);
	void Fire();

	virtual void HandleDestruction();


};
