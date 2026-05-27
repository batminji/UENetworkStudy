// Fill out your copyright notice in the Description page of Project Settings.


#include "Session/SessionItemWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void USessionItemWidget::SetInfo(FBlueprintSessionResult InSessionResult)
{
	SessionResult = InSessionResult;
	RefreshUI();
}

void USessionItemWidget::RefreshUI()
{
	const int32 CurrentPlayerCount = SessionResult.OnlineResult.Session.NumOpenPublicConnections - SessionResult.OnlineResult.Session.NumOpenPrivateConnections;
	const int32 MaxPlayers = SessionResult.OnlineResult.Session.NumOpenPublicConnections;
	FString PlayerCountString = FString::Printf(TEXT("(%d / %d)"), CurrentPlayerCount, MaxPlayers);

	Txt_SessionName->SetText(FText());
	Txt_PlayerCount->SetText(FText::FromString(PlayerCountString));

	UE_LOG(LogTemp, Warning, TEXT("%s"), *PlayerCountString);
	Txt_MapName->SetText(FText());
}