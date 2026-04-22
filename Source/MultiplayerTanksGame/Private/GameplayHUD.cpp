// 2026 Copyright VFS PG29


#include "GameplayHUD.h"
#include "../Public/GameplayWidget.h"
#include "../Public/GameOverWidget.h"

void AGameplayHUD::WinGame()
{
	if (CurrentGameplayWidget)
	{
		CurrentGameplayWidget->AddToViewport();
	}
	
	// Shows win game screen
	if (WinScreenWidget)
	{
		WinScreenWidget->AddToViewport();
	}
}

void AGameplayHUD::LoseGame()
{
	if (CurrentGameplayWidget)
	{
		CurrentGameplayWidget->AddToViewport();
	}
	
	// Shows lose screen
	if (LoseScreenWidget)
	{
		LoseScreenWidget->AddToViewport();
	}
}

void AGameplayHUD::DestroyHealthBar()
{
	if (CurrentGameplayWidget)
	{
		CurrentGameplayWidget->DestroyHealthBarWidget();
	}
}

void AGameplayHUD::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentGameplayWidget = CreateWidget<UGameplayWidget>(GetWorld(), GameplayWidget);
	
	// Sets GUI at beginning of game
	if (CurrentGameplayWidget)
	{
		CurrentGameplayWidget->AddToViewport();
	}
}
