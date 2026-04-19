// 2026 Copyright VFS PG29


#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"


void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Sets buttons
	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnQuitButtonClicked);
	}

	if (RestartGameButton)
	{
		RestartGameButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnRestartGameButtonClicked);
	}

	if (MainMenuButton)
	{
		MainMenuButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnMainMenuButtonClicked);
	}
}

void UGameOverWidget::OnQuitButtonClicked()
{
	// Quits player
	if (GetWorld())
	{
		UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayer(), EQuitPreference::Type::Quit, false);
	}
}

void UGameOverWidget::OnRestartGameButtonClicked()
{
	// Plays Game
	if (GetWorld())
	{
		GetWorld()->ServerTravel(TEXT("/Game/Content/Levels/MainLevel"));
	}
}

void UGameOverWidget::OnMainMenuButtonClicked()
{
	// Plays Game
	if (GetWorld())
	{
		GetWorld()->ServerTravel(TEXT("/Game/Content/Levels/MenuLevel"));
	}
}
