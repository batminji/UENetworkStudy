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
	FString SessionName;
	SessionResult.OnlineResult.Session.SessionSettings.Get("SESSION_NAME", OUT SessionName);

	FString MapName;
	SessionResult.OnlineResult.Session.SessionSettings.Get("MAP_NAME", OUT MapName);

	const int32 CurrentPlayerCount = SessionResult.OnlineResult.Session.SessionSettings.NumPublicConnections - SessionResult.OnlineResult.Session.NumOpenPublicConnections;
	const int32 MaxPlayers = SessionResult.OnlineResult.Session.SessionSettings.NumPublicConnections;
	FString PlayerCountString = FString::Printf(TEXT("(%d / %d)"), CurrentPlayerCount, MaxPlayers);

	Txt_SessionName->SetText(FText::FromString(SessionName));
	Txt_PlayerCount->SetText(FText::FromString(PlayerCountString));
	Txt_MapName->SetText(FText::FromString(MapName));
}