// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h" 
#include "TPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class tpsdemo_API ATPSHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	// HUD���Ƶ���Ҫ����
	virtual void DrawHUD() override;

protected:
	// ������������Ļ����
	UPROPERTY(EditDefaultsOnly)
		UTexture2D* CrosshairTexture;
};
