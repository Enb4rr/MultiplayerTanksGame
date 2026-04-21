// 2026 Copyright VFS PG29

#include "Turret.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ATurret::ATurret()
{
    PrimaryActorTick.bCanEverTick = true;
    
    ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
    ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void ATurret::BeginPlay()
{
    Super::BeginPlay();
    
    if (HasAuthority())
    {
        StartFireTimer();
    }
}

void ATurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!HasAuthority()) return;

    FindTarget();

    if (IsTargetValid())
    {
        Server_RotateTurret(CurrentTarget->GetActorLocation());
    }
}

void ATurret::FindTarget()
{
    // Grab all actors in the world of type BasePawn
    TArray<AActor*> AllPawns;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABasePawn::StaticClass(), AllPawns);

    ABasePawn* BestTarget = nullptr;
    float BestDistance = DetectionRange;

    for (AActor* Actor : AllPawns)
    {
        // Don't target ourselves
        if (Actor == this) continue;

        float Distance = FVector::Dist(GetActorLocation(), Actor->GetActorLocation());

        if (Distance <= BestDistance)
        {
            BestDistance = Distance;
            BestTarget = Cast<ABasePawn>(Actor);
        }
    }

    CurrentTarget = BestTarget;
}

bool ATurret::IsTargetValid() const
{
    return CurrentTarget != nullptr
        && IsValid(CurrentTarget)
        && FVector::Dist(GetActorLocation(), CurrentTarget->GetActorLocation()) <= DetectionRange;
}

void ATurret::StartFireTimer()
{
    // This calls Fire() repeatedly every FireRate seconds
    GetWorldTimerManager().SetTimer(
        FireTimerHandle,
        this,
        &ATurret::Fire,
        FireRate,
        true  // looping
    );
}

void ATurret::Fire()
{
    // Double-check authority and that we have everything we need
    if (!HasAuthority()) return;
    if (!IsTargetValid()) return;
    if (!ProjectileClass) return;

    FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
    FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = GetInstigator();

    GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
}