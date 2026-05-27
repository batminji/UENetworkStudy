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
	if (!Txt_SessionName || !Txt_PlayerCount || !Txt_MapName)
	{
		return;
	}
	Txt_SessionName->SetText(FText());
	Txt_PlayerCount->SetText(FText());
	Txt_MapName->SetText(FText());
}