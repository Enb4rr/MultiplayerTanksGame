#include "ShootingTank.h"

#include "EnhancedInputComponent.h"
#include "ShootingProjectile.h"

AShootingTank::AShootingTank()
{
	ShootAction = nullptr;
}

void AShootingTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind the Shoot action to the Shoot function
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ShootAction)
		{
			EIC->BindAction(ShootAction, ETriggerEvent::Started, this, &AShootingTank::Shoot);
		}
	}
}

// This function is called when the player presses the shoot button. It spawns a projectile at the turret's location and rotation.
void AShootingTank::Shoot()
{
	if (!ProjectileClass || !TurretMesh || !GetWorld())
	{
		return;
	}

	if (HasAuthority())
	{
		// Calculate the spawn location and rotation for the projectile based on the turret's position and orientation
		const FVector SpawnLocation = TurretMesh->GetComponentLocation() + (TurretMesh->GetForwardVector() * ProjectileSpawnOffset);
		const FRotator SpawnRotation = TurretMesh->GetComponentRotation();

		// Set up spawn parameters for the projectile
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = GetInstigator();
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		GetWorld()->SpawnActor<AShootingProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParameters);
	}
	else
	{
		Server_Shoot();
	}
}

void AShootingTank::Server_Shoot_Implementation()
{
	Shoot();
}
