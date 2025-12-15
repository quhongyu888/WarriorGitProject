// 蓝图函数库

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorStructTypes/WarriorEnumTypes.h"
#include "WarriorFunctionLibrary.generated.h"

class UWarriorAbilitySystemComponent;
class UPawnCombatComponent;

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//提供actor获取其asc组件（c++）
	static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);

	//添加游戏标签给actor
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag ToTagAdd);
		
	//给actor移除游戏标签
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void RemoveGameplayFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	//返回是否有该游戏标签
	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);
		
	//提供给蓝图的函数功能，返回是否有该游戏标签，ExpandEnumAsExecs = "OutConfirmType"意义是作为蓝图节点是输出端的形式
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName = "Get PawnCombat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent*BP_GetPawnCombatComponentFromActor(AActor* InActor,EWarriorValidType& OutValidType);
};
