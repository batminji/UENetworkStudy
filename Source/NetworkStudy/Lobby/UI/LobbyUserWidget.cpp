// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/UI/LobbyUserWidget.h"
#include "Lobby/Contents/LobbyPlayerState.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetSystemLibrary.h"

void ULobbyUserWidget::SetInfo(ALobbyPlayerState* InPlayerState)
{
	PlayerState = InPlayerState;

	RefreshUI();
}

void ULobbyUserWidget::RefreshUI()
{
	if (!IsValid(PlayerState))
	{
		return;
	}

	bool bIsLocalPlayer = false;
	APlayerController* PlayerController = PlayerState->GetPlayerController();
	if (IsValid(PlayerController))
	{
		bIsLocalPlayer = PlayerController->IsLocalController();
	}

	bool bIsReady = PlayerState->bIsReady;

	bool bIsServer = UKismetSystemLibrary::IsServer(this);

	Btn_Ready->SetVisibility(ESlateVisibility::Hidden);
	Btn_KickPlayer->SetVisibility(ESlateVisibility::Hidden);
	Txt_Ready->SetVisibility(ESlateVisibility::Hidden);
	Editable_PlayerName->SetVisibility(ESlateVisibility::Hidden);

	if (bIsReady)
	{
		Txt_Ready->SetVisibility(ESlateVisibility::Visible);
	}

	if (bIsLocalPlayer && bIsReady)
	{
		Btn_Ready->SetVisibility(ESlateVisibility::Visible);
	}

	if (bIsServer && bIsLocalPlayer)
	{
		Btn_KickPlayer->SetVisibility(ESlateVisibility::Visible);
	}

	Editable_PlayerName->SetText(PlayerState->NickName);
	Editable_PlayerName->SetVisibility(ESlateVisibility::Visible);

	if (bIsReady)
	{
		Editable_PlayerName->SetIsReadOnly(true);
	}
	else
	{
		Editable_PlayerName->SetIsReadOnly(!bIsLocalPlayer);
	}
}