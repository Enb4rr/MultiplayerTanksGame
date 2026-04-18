#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootingProjectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class MULTIPLAYERTANKSGAME_API AShootingProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	AShootingProjectile();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* ProjectileMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UProjectileMovementComponent* ProjectileMovementComponent;
};
