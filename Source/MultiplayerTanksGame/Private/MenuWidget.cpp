// 2026 Copyright VFS PG29


#include "MenuWidget.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Sets buttons
	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UMenuWidget::OnQuitButtonClicked);
	}

	if (PlayButton)
	{
		PlayButton->OnClicked.AddDynamic(this, &UMenuWidget::OnPlayButtonClicked);
	}
}

void UMenuWidget::OnQuitButtonClicked()
{
	// Quits player
	if (GetWorld())
	{
		UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayer(), EQuitPreference::Type::Quit, false);
	}
}

void UMenuWidget::OnPlayButtonClicked()
{
	// Plays Game
	if (GetWorld())
	{
		GetWorld()->ServerTravel(TEXT("/Game/Content/Levels/MainLevel"));
	}
}
