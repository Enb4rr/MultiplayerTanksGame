// 2026 Copyright VFS PG29


#include "GameplayHUD.h"
#include "../UI/GameplayWidget.h"

void AGameplayHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GameplayWidget)
	{
		GameplayWidget->AddToViewport();
	}
}
