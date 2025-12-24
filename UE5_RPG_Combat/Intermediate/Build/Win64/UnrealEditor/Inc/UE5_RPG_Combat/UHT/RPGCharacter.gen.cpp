// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/RPGCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeRPGCharacter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGCharacter();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE5_RPG_Combat();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ARPGCharacter ************************************************************
void ARPGCharacter::StaticRegisterNativesARPGCharacter()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ARPGCharacter;
UClass* ARPGCharacter::GetPrivateStaticClass()
{
	using TClass = ARPGCharacter;
	if (!Z_Registration_Info_UClass_ARPGCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("RPGCharacter"),
			Z_Registration_Info_UClass_ARPGCharacter.InnerSingleton,
			StaticRegisterNativesARPGCharacter,
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
	return Z_Registration_Info_UClass_ARPGCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_ARPGCharacter_NoRegister()
{
	return ARPGCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ARPGCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/RPGCharacter.h" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARPGCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARPGCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_UE5_RPG_Combat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARPGCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARPGCharacter_Statics::ClassParams = {
	&ARPGCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARPGCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ARPGCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARPGCharacter()
{
	if (!Z_Registration_Info_UClass_ARPGCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARPGCharacter.OuterSingleton, Z_Construct_UClass_ARPGCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARPGCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARPGCharacter);
ARPGCharacter::~ARPGCharacter() {}
// ********** End Class ARPGCharacter **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARPGCharacter, ARPGCharacter::StaticClass, TEXT("ARPGCharacter"), &Z_Registration_Info_UClass_ARPGCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARPGCharacter), 1145169621U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_1761272073(TEXT("/Script/UE5_RPG_Combat"),
	Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
