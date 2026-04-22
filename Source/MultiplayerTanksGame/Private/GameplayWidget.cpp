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

void UGameplayWidget::DestroyHealthBarWidget()
{
	UE_LOG(LogTemp, Warning, TEXT("Destroying Health Bar Widget"));
	
	if (HealthProgressBar)
	{
		UE_LOG(LogTemp, Warning, TEXT("Destroying HealthProgressBar Bar Widget"));
		HealthProgressBar->RemoveFromParent();
	}
	
	if (HealthTextBlock)
	{
		UE_LOG(LogTemp, Warning, TEXT("Destroying HealthTextBlock Bar Widget"));
		HealthTextBlock->RemoveFromParent();
	}
}

void UGameplayWidget::OnAbilityChange(FText AbilityText)
{
	if (AbilityTextBlock)
	{
		AbilityTextBlock->SetText(AbilityText);
	}
}


