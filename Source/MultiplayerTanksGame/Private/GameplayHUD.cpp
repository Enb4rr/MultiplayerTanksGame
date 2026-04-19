// 2026 Copyright VFS PG29


#include "GameplayHUD.h"
#include "../Public/GameplayWidget.h"

void AGameplayHUD::BeginPlay()
{
	Super::BeginPlay();

	// Sets GUI at beginning of game
	if (GameplayWidget)
	{
		GameplayWidget->AddToViewport();
	}
}
