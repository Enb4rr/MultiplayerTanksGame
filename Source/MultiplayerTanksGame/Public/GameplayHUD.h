// 2026 Copyright VFS PG29

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameplayHUD.generated.h"

class UGameplayWidget;

/**
 * 
 */
UCLASS()
class MULTIPLAYERTANKSGAME_API AGameplayHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UGameplayWidget> GameplayWidget;
	
protected:

	virtual void BeginPlay() override;

};
