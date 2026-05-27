// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "Blueprint/UserWidget.h"
#include "SessionItemWidget.generated.h"

class UTextBlock;
class UButton;

UCLASS()
class NETWORKSTUDY_API USessionItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetInfo(FBlueprintSessionResult InSessionResult);

	UFUNCTION(BlueprintCallable)
	void RefreshUI();

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Txt_SessionName;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Txt_PlayerCount;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Txt_MapName;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Btn_Join;

protected:
	UPROPERTY(BlueprintReadOnly)
	FBlueprintSessionResult SessionResult;
};
