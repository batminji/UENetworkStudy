// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/UI/LobbyWidget.h"
#include "Lobby/UI/LobbyUserWidget.h"
#include "Lobby/Contents/LobbyPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameStateBase.h"

TArray<ALobbyPlayerState*> ULobbyWidget::GetLobbyPlayerStates()
{
	TArray<ALobbyPlayerState*> PlayerStates;

	AGameStateBase* GateStateBase = UGameplayStatics::GetGameState(this);
	if (GateStateBase)
	{
		for (APlayerState* PlayerState : GateStateBase->PlayerArray)
		{
			ALobbyPlayerState* LobbyPlayerState = Cast<ALobbyPlayerState>(PlayerState);
			if (IsValid(LobbyPlayerState))
			{
				PlayerStates.Add(LobbyPlayerState);
			}
		}
	}

	return PlayerStates;
}

ALobbyPlayerState* ULobbyWidget::GetLobbyPlayerStateAtIndex(int32 InIndex)
{
	TArray<ALobbyPlayerState*> PlayerStates = GetLobbyPlayerStates();
	if (PlayerStates.IsValidIndex(InIndex))
	{
		return PlayerStates[InIndex];
	}
	return nullptr;
}
