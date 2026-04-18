// 2026 Copyright VFS PG29


#include "GameplayWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UGameplayWidget::OnHealthChanged(float NewHealth, float MaxHealth)
{
	float Percentage = NewHealth / MaxHealth;
	HealthProgressBar->SetPercent(Percentage);
}
