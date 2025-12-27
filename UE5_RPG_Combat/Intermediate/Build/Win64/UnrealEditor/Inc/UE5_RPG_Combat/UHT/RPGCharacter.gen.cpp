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
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMapping_MetaData[] = {
		{ "Category", "Enhanced Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Input Actions\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Actions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Enhanced Input" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Enhanced Input" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Enhanced Input" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunAction_MetaData[] = {
		{ "Category", "Enhanced Input" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BasicAttackAction_MetaData[] = {
		{ "Category", "Enhanced Input" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeavyAttackAction_MetaData[] = {
		{ "Category", "Enhanced Input" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpinAttackAction_MetaData[] = {
		{ "Category", "Enhanced Input" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAttackAction_MetaData[] = {
		{ "Category", "Enhanced Input" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Walk Speed\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Walk Speed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunSpeed_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Run Speed\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Run Speed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArmComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Spring Arm Component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring Arm Component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Camera Component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera Component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMapping;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RunAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BasicAttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeavyAttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpinAttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAttackAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArmComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCameraComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARPGCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_InputMapping = { "InputMapping", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, InputMapping), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMapping_MetaData), NewProp_InputMapping_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_RunAction = { "RunAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, RunAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunAction_MetaData), NewProp_RunAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_BasicAttackAction = { "BasicAttackAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, BasicAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BasicAttackAction_MetaData), NewProp_BasicAttackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_HeavyAttackAction = { "HeavyAttackAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, HeavyAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeavyAttackAction_MetaData), NewProp_HeavyAttackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_SpinAttackAction = { "SpinAttackAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, SpinAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpinAttackAction_MetaData), NewProp_SpinAttackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_JumpAttackAction = { "JumpAttackAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, JumpAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAttackAction_MetaData), NewProp_JumpAttackAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0020080000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_RunSpeed = { "RunSpeed", nullptr, (EPropertyFlags)0x0020080000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, RunSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunSpeed_MetaData), NewProp_RunSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_SpringArmComponent = { "SpringArmComponent", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, SpringArmComponent), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArmComponent_MetaData), NewProp_SpringArmComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_FollowCameraComponent = { "FollowCameraComponent", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, FollowCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCameraComponent_MetaData), NewProp_FollowCameraComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARPGCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_InputMapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_RunAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_BasicAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_HeavyAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_SpinAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_JumpAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_RunSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_SpringArmComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_FollowCameraComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARPGCharacter_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_ARPGCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ARPGCharacter_Statics::PropPointers),
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
		{ Z_Construct_UClass_ARPGCharacter, ARPGCharacter::StaticClass, TEXT("ARPGCharacter"), &Z_Registration_Info_UClass_ARPGCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARPGCharacter), 1773885861U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_2683251368(TEXT("/Script/UE5_RPG_Combat"),
	Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
