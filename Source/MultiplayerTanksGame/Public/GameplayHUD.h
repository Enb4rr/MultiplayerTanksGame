// 2026 Copyright VFS PG29

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameplayHUD.generated.h"

class UGameplayWidget;
class UGameOverWidget;

/**
 * 
 */
UCLASS()
class MULTIPLAYERTANKSGAME_API AGameplayHUD : public AHUD
{
	GENERATED_BODY()

public:

	// GUI
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UGameplayWidget> GameplayWidget;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UGameOverWidget> WinScreenWidget;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UGameOverWidget> LoseScreenWidget;

	// Win Lose Functions
	UFUNCTION(BlueprintCallable)
	void WinGame();

	UFUNCTION(BlueprintCallable)
	void LoseGame();
	
protected:

	virtual void BeginPlay() override;

};
