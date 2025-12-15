// Fill out your copyright notice in the Description page of Project Settings.
//Pawn类扩展父组件类
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	//c++原生模板函数
	template<class T>
	T* GetOwningPawn() const//定义获取拥有此组件的Pawn类
	{
		//静态断言，限制传入的模板类型T必须是APawn类或子类
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template Parameter to GetPawn must be derived from APawn");
		//安全强制类型转换返回APawn类型的指针
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	template<class T>
	T* GetOwningController() const //定义获取拥有此组件的对象的控制器
	{
		//静态断言，限制传入的模板类型T必须是AController类或子类
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Parameter to GetController must be derived from AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
