// 2026 Copyright VFS PG29

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

class UMenuWidget;

/**
 * 
 */
UCLASS()
class MULTIPLAYERTANKSGAME_API AMenuHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	// MainMenu
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMenuWidget> MenuWidget;

protected:

	virtual void BeginPlay() override;

};
