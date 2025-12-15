// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"
//预声明类
class UInputAction;
class UInputMappingContext;
//声明该数据其中的一项结构体内部
USTRUCT(BlueprintType)
struct FWarriorInputActionConfig 
{
	GENERATED_USTRUCT_BODY()
public:
	//声明原生游戏标签类别为已定义的InputTag,只搜索该类别下的子标签
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
	//声明原生游戏标签类别下的操作映射
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;
	
	bool IsValid() const
	{
		return InputTag.IsValid() && InputAction;
	}
};
/**
 * 
 */
//构建该数据的内容
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	//声明一个默认仅可更改的默认操作映射
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;
	//声明一个以上面定义的结构体FWarriorInputActionConfig数组NativeInputActions
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta=(TitleProperty="InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;
	//在配置表（DataAsset 里的数组）根据标签FGameplayTag&从中找到匹配的输入动作（UInputAction）然后把那个动作对象返回
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
	//声明一个管理游戏能力输入操作的数组
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FWarriorInputActionConfig> AbilityInputActions;
};
