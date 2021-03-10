// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "tpsdemoGameModeBase.h"
#include "Engine/Engine.h"

void AtpsdemoGameModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	// 显示调试消息五秒。 
	// 参数中的-1"键"值类型参数能防止该消息被更新或刷新。
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Welcome TPS training grounds, this is TPSGameMode!"));

}