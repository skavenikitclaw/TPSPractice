// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "tpsdemoGameModeBase.h"
#include "Engine/Engine.h"

void AtpsdemoGameModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	// ��ʾ������Ϣ���롣 
	// �����е�-1"��"ֵ���Ͳ����ܷ�ֹ����Ϣ�����»�ˢ�¡�
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Welcome TPS training grounds, this is TPSGameMode!"));

}