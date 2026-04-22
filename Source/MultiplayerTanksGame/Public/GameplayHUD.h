// 2026 Copyright VFS PG29

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameplayHUD.generated.h"

class UGameplayWidget;
class UGameOverWidget;
class UUserWidget;

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
	TSubclassOf<UUserWidget> GameplayWidget;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UGameOverWidget> WinScreenWidget;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UGameOverWidget> LoseScreenWidget;
	
	UPROPERTY(BlueprintReadOnly)
	UGameplayWidget* CurrentGameplayWidget;
	
	// Win Lose Functions
	UFUNCTION(BlueprintCallable)
	void WinGame();

	UFUNCTION(BlueprintCallable)
	void LoseGame();
	
	UFUNCTION(BlueprintCallable)
	void DestroyHealthBar();
	
protected:

	virtual void BeginPlay() override;

};
