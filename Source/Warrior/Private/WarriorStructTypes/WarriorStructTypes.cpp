// Fill out your copyright notice in the Description page of Project Settings.

#include "WarriorStructTypes/WarriorStructTypes.h"
#include "AbilitySystem/Ability/WarriorHeroGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
