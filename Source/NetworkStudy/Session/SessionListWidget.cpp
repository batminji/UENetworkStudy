// Fill out your copyright notice in the Description page of Project Settings.


#include "Session/SessionListWidget.h"
#include "Components/WrapBox.h"
#include "Components/Button.h"
#include "Session/SessionItemWidget.h"

bool USessionListWidget::Initialize()
{
	if(!Super::Initialize())
	{
		return false;
	}
	
	SetInfo();

	return true;
}

void USessionListWidget::SetInfo()
{
	if (!SessionItemWidgetClass)
	{
		return;
	}

	SessionItemWidgets.Empty();

	for (int i = 0; i < 10; ++i)
	{
		USessionItemWidget* ChildWidget = CreateWidget<USessionItemWidget>(GetWorld(), SessionItemWidgetClass);
		if (ChildWidget)
		{
			SessionList->AddChildToWrapBox(ChildWidget);
			SessionItemWidgets.Add(ChildWidget);
		}
	}

	RefreshUI();
}

void USessionListWidget::RefreshUI()
{
	const int32 SessionLength = SessionResults.Num();

	for (int32 i = 0; i < SessionItemWidgets.Num(); ++i)
	{
		const int32 Index = i;

		if (Index < SessionLength)
		{
			SessionItemWidgets[Index]->SetVisibility(ESlateVisibility::Visible);
			FBlueprintSessionResult Result = SessionResults[Index];
			SessionItemWidgets[Index]->SetInfo(Result);
		}
		else
		{
			SessionItemWidgets[Index]->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}