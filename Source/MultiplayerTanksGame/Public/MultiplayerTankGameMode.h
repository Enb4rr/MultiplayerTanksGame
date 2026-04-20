// 2026 Copyright VFS PG29

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/GameMode.h"
#include "MultiplayerTankGameMode.generated.h"

/**
 * 
 */

class AMultiplayerTankPlayerStart;
DECLARE_LOG_CATEGORY_EXTERN(LogNetworkingGameMode, Log, All);


UCLASS()
class MULTIPLAYERTANKSGAME_API AMultiplayerTankGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AMultiplayerTankGameMode();
	
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void RestartPlayer(AController* NewPlayer) override;
};
