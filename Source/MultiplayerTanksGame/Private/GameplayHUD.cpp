// 2026 Copyright VFS PG29


#include "GameplayHUD.h"
#include "../Public/GameplayWidget.h"
#include "../Public/GameOverWidget.h"

void AGameplayHUD::WinGame()
{
	// Shows win game screen
	if (WinScreenWidget)
	{
		WinScreenWidget->AddToViewport();
	}
}

void AGameplayHUD::LoseGame()
{
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
