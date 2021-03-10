// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSProjectile.h"

// Sets default values
ATPSProjectile::ATPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}
	if (!CollisionComponent)
	{
		// ��������м򵥵���ײչʾ��
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		// ���������ײ�����ļ���������Ϊ"Projectile"��
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
		// �����������ײ�뾶��
		CollisionComponent->InitSphereRadius(15.0f);
		// �����������Ϊ��ײ�����
		RootComponent = CollisionComponent;
	}

	if (!ProjectileMovementComponent)
	{
		// ʹ�ô����������������ƶ���
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 8000.0f;
		ProjectileMovementComponent->MaxSpeed = 10000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/something/Sphere.Sphere'"));
		if (Mesh.Succeeded())
		{
			ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
		}

		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("Material'/Game/something/SphereMaterial.SphereMaterial'"));
		if (Material.Succeeded())
		{
			ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
		}
		ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
		ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
		ProjectileMeshComponent->SetupAttachment(RootComponent);
	}

	// 3 ���ɾ�������
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void ATPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ��ʼ����������Ϸ������ٶȵĺ�����
void ATPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}