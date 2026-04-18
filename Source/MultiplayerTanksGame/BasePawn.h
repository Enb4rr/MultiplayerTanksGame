// 2026 Copyright VFS PG29

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "BasePawn.generated.h"

UCLASS()
class MULTIPLAYERTANKSGAME_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* TurretMesh;
	
	// Sets default values for this pawn's properties
	ABasePawn();

	void RotateTurret(FVector LookAtTarget);
};
