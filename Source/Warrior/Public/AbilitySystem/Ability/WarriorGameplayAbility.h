// 声明游戏能力的头文件

#pragma once

#include "CoreMinimal.h"
//引用ASC，GAS核心组件
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "WarriorGameplayAbility.generated.h"
class UPawnCombatComponent;
//定义一个枚举用于判断该能力是否是授予时自动触发或手动触发
class UWarriorAbilitySystemComponent;
UENUM(BlueprintType)
enum class EWarriorAbilityActivationPolicy :uint8
{
	OnTriggered,//手动
	OnGiven     //自动
};

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
protected:
	//~ Begin GameplayAbility Interface.
	
	//重写能力被授予时的函数
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	//重写能力结束的函数
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	
	//~ End GameplayAbility Interface

	//声明此能力的授予触发方式
	UPROPERTY(EditDefaultsOnly,Category="WarriorAbility")
	EWarriorAbilityActivationPolicy AbilityActivationPolicy = EWarriorAbilityActivationPolicy::OnTriggered;
	//声明获取战斗组件的纯函数
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo()const;
	//声明获取ASC组件的纯函数
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponentFromActorInfo() const;
};
