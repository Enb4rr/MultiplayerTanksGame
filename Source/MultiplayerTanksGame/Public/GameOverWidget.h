// 2026 Copyright VFS PG29

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UButton;
class UTextBlock;

/**
 * 
 */
UCLASS()
class MULTIPLAYERTANKSGAME_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual void NativeConstruct() override;

	// UI Objects
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> TitleTextBlock;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> RestartGameButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> MainMenuButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> QuitButton;

	// Button presses
	UFUNCTION()
	void OnQuitButtonClicked();

	UFUNCTION()
	void OnRestartGameButtonClicked();

	UFUNCTION()
	void OnMainMenuButtonClicked();

};
