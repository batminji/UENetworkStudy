// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "Blueprint/UserWidget.h"
#include "SessionListWidget.generated.h"

class UWrapBox;
class UButton;
class USessionItemWidget;

UCLASS()
class NETWORKSTUDY_API USessionListWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void SetInfo();

	UFUNCTION(BlueprintCallable)
	void RefreshUI();
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWrapBox> SessionList;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Btn_Refresh;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Btn_CreateSession;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Btn_Close;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<USessionItemWidget> SessionItemWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	TArray<TObjectPtr<USessionItemWidget>> SessionItemWidgets;

	UPROPERTY(BlueprintReadWrite)
	TArray<FBlueprintSessionResult> SessionResults;
};
