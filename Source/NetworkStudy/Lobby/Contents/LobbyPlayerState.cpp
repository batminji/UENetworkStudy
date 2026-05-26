// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/Contents/LobbyPlayerState.h"
#include "Net/UnrealNetwork.h"

void ALobbyPlayerState::OnRep_Nickname()
{
	UE_LOG(LogTemp, Log, TEXT("Nickname is changed : %s"), *NickName.ToString());
}

void ALobbyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyPlayerState, NickName);
}
