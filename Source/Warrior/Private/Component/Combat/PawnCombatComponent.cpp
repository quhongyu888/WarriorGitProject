// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combat/PawnCombatComponent.h"
#include "Items/Weapons/WarriorWeaponBase.h"
#include "Components/BoxComponent.h"
#include "WarriorDebugHelper.h"

//定义注册生成的武器函数
void UPawnCombatComponent::RegisterSpawnWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegistedAsEquippedWeapon)
{
	//安全崩溃检查,判断InWeaponTagToRegister注册的武器标签是否已存在于CharacterCarriedWeaponMap中,如存在中断代码报错输出语句,把标签转换为TChar类型提供给%s
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A Tag named %s has already been added as carried weapon"),*InWeaponTagToRegister.ToString());
	//安全崩溃检查,所需注册的武器是否有效
	check(InWeaponToRegister);
	//将该武器标签和武器类注册到TMap
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	InWeaponToRegister->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
	InWeaponToRegister->OnWeaponPulledFromTarget.BindUObject(this, &ThisClass::OnWeaponPulledFromTargetActor);
	//武器如果已经装备，将该武器状态标签设置为已经装备
	if (bRegistedAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}
}
//定义根据标签获取角色所携带的武器指针
AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
		//将找到的指向value的指针返回,find返回的是指向value类型的指针（非副本，便于直接修改），需解引用*
	    //此处是指向指针的指针的知识点
		if (AWarriorWeaponBase* const * FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
		return nullptr;
}
//定义获取角色所装备的武器
AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UPawnCombatComponent::ToggleWeaponCllision(bool bShouldEnable, EToggleDamageType ToggleDamegeType)
{
	if (ToggleDamegeType==EToggleDamageType::CurrentEquippedWeapon)
	{
		AWarriorWeaponBase* WeaponToToggle = GetCharacterCurrentEquippedWeapon();

		check(WeaponToToggle);

		if (bShouldEnable)
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		}
		else 
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			OverlappedActors.Empty();
		}
	}

	//TODO:Handle body 
}

void UPawnCombatComponent::OnHitTargetActor(AActor* HitActor)
{

}

void UPawnCombatComponent::OnWeaponPulledFromTargetActor(AActor* InreractedActor)
{

}
