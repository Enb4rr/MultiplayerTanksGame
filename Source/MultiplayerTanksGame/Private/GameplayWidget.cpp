// 2026 Copyright VFS PG29


#include "GameplayWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UGameplayWidget::OnHealthChanged(float NewHealth, float MaxHealth)
{
	float Percentage = NewHealth / MaxHealth;

	// Set bar and text
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percentage);
	}

	if (HealthTextBlock)
	{
		HealthTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d%%"), static_cast<int32>(Percentage * 100))));
	}
}

void UGameplayWidget::OnAbilityChange(FText AbilityText)
{
	if (AbilityTextBlock)
	{
		AbilityTextBlock->SetText(AbilityText);
	}
}


