// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameMode/RPGGameModeBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeRPGGameModeBase() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGGameModeBase();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGGameModeBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE5_RPG_Combat();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ARPGGameModeBase *********************************************************
void ARPGGameModeBase::StaticRegisterNativesARPGGameModeBase()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ARPGGameModeBase;
UClass* ARPGGameModeBase::GetPrivateStaticClass()
{
	using TClass = ARPGGameModeBase;
	if (!Z_Registration_Info_UClass_ARPGGameModeBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("RPGGameModeBase"),
			Z_Registration_Info_UClass_ARPGGameModeBase.InnerSingleton,
			StaticRegisterNativesARPGGameModeBase,
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
	return Z_Registration_Info_UClass_ARPGGameModeBase.InnerSingleton;
}
UClass* Z_Construct_UClass_ARPGGameModeBase_NoRegister()
{
	return ARPGGameModeBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ARPGGameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameMode/RPGGameModeBase.h" },
		{ "ModuleRelativePath", "Public/GameMode/RPGGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARPGGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARPGGameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_UE5_RPG_Combat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARPGGameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARPGGameModeBase_Statics::ClassParams = {
	&ARPGGameModeBase::StaticClass,
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
	0x009003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARPGGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ARPGGameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARPGGameModeBase()
{
	if (!Z_Registration_Info_UClass_ARPGGameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARPGGameModeBase.OuterSingleton, Z_Construct_UClass_ARPGGameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARPGGameModeBase.OuterSingleton;
}
ARPGGameModeBase::ARPGGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARPGGameModeBase);
ARPGGameModeBase::~ARPGGameModeBase() {}
// ********** End Class ARPGGameModeBase ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h__Script_UE5_RPG_Combat_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARPGGameModeBase, ARPGGameModeBase::StaticClass, TEXT("ARPGGameModeBase"), &Z_Registration_Info_UClass_ARPGGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARPGGameModeBase), 602930259U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h__Script_UE5_RPG_Combat_3279369528(TEXT("/Script/UE5_RPG_Combat"),
	Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h__Script_UE5_RPG_Combat_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h__Script_UE5_RPG_Combat_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
