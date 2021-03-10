// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSProjectile.h"
#include "TPSCharacter.generated.h"

class UCameraComponent;
class USkeletalMeshComponent;

UCLASS()
class tpsdemo_API ATPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Ҫ���ɵķ�������
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ATPSProjectile> ProjectileClass;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ��������ǰ���ƶ�������
	UFUNCTION()
		void MoveForward(float Value);

	// �������������ƶ�������
	UFUNCTION()
		void MoveRight(float Value);

	// ���¼�ʱ��������Ծ���
	UFUNCTION()
		void StartJump();

	// �ͷż�ʱ�������Ծ���
	UFUNCTION()
		void StopJump();

	// ������������ĺ���
	UFUNCTION()
		void Fire();

	//�����
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* TPSCameraComponent;

	// ǹ������������λ�õ�ƫ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;
};
