// 2026 Copyright VFS PG29


#include "MultiplayerTankGameMode.h"
#include "../Tank.h"
#include "Engine.h"
#include "Logging/StructuredLog.h"

DEFINE_LOG_CATEGORY(LogNetworkingGameMode);

AMultiplayerTankGameMode::AMultiplayerTankGameMode()
{
	DefaultPawnClass = ATank::StaticClass();
		
	bStartPlayersAsSpectators = true;
}

void AMultiplayerTankGameMode::PreLogin(const FString& Options, const FString& Address,
	const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	
	if (!ErrorMessage.IsEmpty())
	{
		UE_LOGFMT(LogNetworkingGameMode, Log, "PreLogin| Login Failed from Address = {Address} | Reason = {Reason} | CurrentPlayers = {NumPlayers}",
			("Address", Address),
			("Reason", ErrorMessage),
			("NumPlayers", GetNumPlayers()));
	}
}

void AMultiplayerTankGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	
	UE_LOGFMT(LogNetworkingGameMode, Log, "PostLogin| Player Joined : ID = {PlayerID} | TotalPlayers = {NumPlayers}",
		("PlayerID", NewPlayer ? NewPlayer->GetPlayerState<APlayerState>()->GetPlayerId() : -1),
		("NumPlayers", GetNumPlayers()));
}
