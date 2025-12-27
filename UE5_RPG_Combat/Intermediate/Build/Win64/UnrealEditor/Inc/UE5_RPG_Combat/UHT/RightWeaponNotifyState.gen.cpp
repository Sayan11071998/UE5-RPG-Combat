// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/RightWeaponNotifyState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeRightWeaponNotifyState() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UAnimNotifyState();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGCharacter_NoRegister();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_URightWeaponNotifyState();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_URightWeaponNotifyState_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE5_RPG_Combat();
// ********** End Cross Module References **********************************************************

// ********** Begin Class URightWeaponNotifyState **************************************************
void URightWeaponNotifyState::StaticRegisterNativesURightWeaponNotifyState()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_URightWeaponNotifyState;
UClass* URightWeaponNotifyState::GetPrivateStaticClass()
{
	using TClass = URightWeaponNotifyState;
	if (!Z_Registration_Info_UClass_URightWeaponNotifyState.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("RightWeaponNotifyState"),
			Z_Registration_Info_UClass_URightWeaponNotifyState.InnerSingleton,
			StaticRegisterNativesURightWeaponNotifyState,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_URightWeaponNotifyState.InnerSingleton;
}
UClass* Z_Construct_UClass_URightWeaponNotifyState_NoRegister()
{
	return URightWeaponNotifyState::GetPrivateStaticClass();
}
struct Z_Construct_UClass_URightWeaponNotifyState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "Character/RightWeaponNotifyState.h" },
		{ "ModuleRelativePath", "Public/Character/RightWeaponNotifyState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RPGCharacter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ~ End UAnimNotifyState interface\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/RightWeaponNotifyState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "~ End UAnimNotifyState interface" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RPGCharacter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URightWeaponNotifyState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URightWeaponNotifyState_Statics::NewProp_RPGCharacter = { "RPGCharacter", nullptr, (EPropertyFlags)0x0114000000000010, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URightWeaponNotifyState, RPGCharacter), Z_Construct_UClass_ARPGCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RPGCharacter_MetaData), NewProp_RPGCharacter_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URightWeaponNotifyState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URightWeaponNotifyState_Statics::NewProp_RPGCharacter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URightWeaponNotifyState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_URightWeaponNotifyState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimNotifyState,
	(UObject* (*)())Z_Construct_UPackage__Script_UE5_RPG_Combat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URightWeaponNotifyState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URightWeaponNotifyState_Statics::ClassParams = {
	&URightWeaponNotifyState::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_URightWeaponNotifyState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_URightWeaponNotifyState_Statics::PropPointers),
	0,
	0x001130A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URightWeaponNotifyState_Statics::Class_MetaDataParams), Z_Construct_UClass_URightWeaponNotifyState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URightWeaponNotifyState()
{
	if (!Z_Registration_Info_UClass_URightWeaponNotifyState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URightWeaponNotifyState.OuterSingleton, Z_Construct_UClass_URightWeaponNotifyState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URightWeaponNotifyState.OuterSingleton;
}
URightWeaponNotifyState::URightWeaponNotifyState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(URightWeaponNotifyState);
URightWeaponNotifyState::~URightWeaponNotifyState() {}
// ********** End Class URightWeaponNotifyState ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RightWeaponNotifyState_h__Script_UE5_RPG_Combat_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URightWeaponNotifyState, URightWeaponNotifyState::StaticClass, TEXT("URightWeaponNotifyState"), &Z_Registration_Info_UClass_URightWeaponNotifyState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URightWeaponNotifyState), 2344243256U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RightWeaponNotifyState_h__Script_UE5_RPG_Combat_573410813(TEXT("/Script/UE5_RPG_Combat"),
	Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RightWeaponNotifyState_h__Script_UE5_RPG_Combat_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RightWeaponNotifyState_h__Script_UE5_RPG_Combat_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
