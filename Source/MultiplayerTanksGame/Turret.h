// 2026 Copyright VFS PG29

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Turret.generated.h"

UCLASS()
class MULTIPLAYERTANKSGAME_API ATurret : public ABasePawn
{
	GENERATED_BODY()

public:
	ATurret();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// Turret range
	UPROPERTY(EditAnywhere, Category = "Turret|Combat")
	float DetectionRange = 3000.f;

	// Cached reference to the current target
	UPROPERTY()
	ABasePawn* CurrentTarget = nullptr;

	// Scans for the nearest BasePawn within DetectionRange
	void FindTarget();

	// Returns true if the target is still valid and within range
	bool IsTargetValid() const;
	
	// Seconds between each shot
	UPROPERTY(EditAnywhere, Category = "Turret|Combat")
	float FireRate = 2.f;
	
	UPROPERTY(EditAnywhere, Category = "Turret|Combat")
	TSubclassOf<AActor> ProjectileClass;
	
	UPROPERTY(VisibleAnywhere, Category = "Turret|Combat")
	USceneComponent* ProjectileSpawnPoint;

	FTimerHandle FireTimerHandle;

	void StartFireTimer();
	void Fire();
};