// 2026 Copyright VFS PG29


#include "GameplayHUD.h"
#include "../Public/GameplayWidget.h"
#include "../Public/GameOverWidget.h"

void AGameplayHUD::WinGame()
{
	if (GameplayWidget)
	{
		GameplayWidget->RemoveFromParent();
	}
	
	// Shows win game screen
	if (WinScreenWidget)
	{
		WinScreenWidget->AddToViewport();
	}
}

void AGameplayHUD::LoseGame()
{
	if (GameplayWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Lost! game widget"));
		GameplayWidget->RemoveFromParent();
	}
	// Shows lose screen
	if (LoseScreenWidget)
	{
		

		LoseScreenWidget->AddToViewport();
	}
}

void AGameplayHUD::BeginPlay()
{
	Super::BeginPlay();

	// Sets GUI at beginning of game
	if (GameplayWidget)
	{
		GameplayWidget->AddToViewport();
	}
}
