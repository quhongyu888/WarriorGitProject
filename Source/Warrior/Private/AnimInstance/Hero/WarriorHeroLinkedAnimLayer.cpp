// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/Hero/WarriorHeroLinkedAnimLayer.h"
#include "AnimInstance/WarriorCharacterAnimInstance.h"

UWarriorCharacterAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorCharacterAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
