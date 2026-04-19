// 2026 Copyright VFS PG29


#include "MenuHUD.h"
#include "../Public/MenuWidget.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	// Sets GUI at beginning of game
	if (MenuWidget)
	{
		MenuWidget->AddToViewport();
	}
}
