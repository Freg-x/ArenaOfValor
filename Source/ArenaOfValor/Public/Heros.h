// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArenaOfValorCharacter.h"
#include "Heros.generated.h"

#define HERO_MAX_LEVEL 15


UCLASS(Blueprintable)
class ARENAOFVALOR_API AHeros : public AArenaOfValorCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHeros();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom")
		class UDamageComponent* DamageComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom")
		class UReactionComponent* ReactionComp;

	UFUNCTION(BlueprintCallable, Category = "Custom")
		void BackHome();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// �Ƿ����
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		bool isAlive;
	// �Ƿ���Ѫ
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		bool HealthIsFull;
	// �Ƿ�����
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		bool MagicIsFull;
	// �����
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int Money;
	// �չ���͹���
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int MiniAttack;
	// �չ���󹥻�����������ʵ�ʹ����ڶ��߼��������
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int MaxAttack;
	// �����ֵ
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		float MaxMagic;
	// ��ǰ����ֵ
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, Category = "Custom")
		float CurMagic;
	// ��ǰ�ȼ�
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, Category = "Custom")
		int CurLevel;
	// �ȼ��µĵ�ǰ����ֵ(������֮ǰ�ȼ�������������)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, Category = "Custom")
		int CurExp;
	// �õȼ��µ��������辭��
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, Category = "Custom")
		int LevelUpCostExp;
	// ��ӡ������Ϣ������������
	UFUNCTION(BlueprintCallable)
		FText setMagicMessage();
	// ����ֵ�Ƿ�Ϸ�
	UFUNCTION(BlueprintCallable)
		bool HealthValid();
	// ����ֵ�Ƿ��ͷż���
	UFUNCTION(BlueprintCallable)
		bool MagicValid(float skillCost);
	// ��������ֵ��������������Ѫ��������Ϊ��Ѫ����������ʹ�ã�
	UFUNCTION(BlueprintCallable)
		void UpdateHealth(float delta);
	// ���·���ֵ������������������������Ϊ��������������ʹ�ã�
	UFUNCTION(BlueprintCallable)
		void UpdateMagic(float delta);
	// ��������
	UFUNCTION(BlueprintCallable)
		void setDeath();
	// ����
	UFUNCTION(BlueprintCallable)
		void reBorn();
	// ����
	UFUNCTION(BlueprintCallable)
		void LevelUp();
	// ����ʱ�������ֵ������ֵ�����ָ�
	UFUNCTION(BlueprintCallable)
		void Refill();
};
