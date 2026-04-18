#pragma once

#include "CoreMinimal.h"
#include "../Tank.h"
#include "ShootingTank.generated.h"

class UInputAction;
class AShootingProjectile;

UCLASS()
class MULTIPLAYERTANKSGAME_API AShootingTank : public ATank
{
	GENERATED_BODY()

public:
	AShootingTank();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void Shoot();

	UFUNCTION(Server, Reliable)
	void Server_Shoot();

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ShootAction;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<AShootingProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float ProjectileSpawnOffset = 120.0f;
};
