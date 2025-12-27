// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/RPGCharacter.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeRPGCharacter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGCharacter();
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE5_RPG_Combat();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ARPGCharacter Function OnRightWeaponOverlap ******************************
struct Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics
{
	struct RPGCharacter_eventOnRightWeaponOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Right Weapon Overlap\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Right Weapon Overlap" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RPGCharacter_eventOnRightWeaponOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RPGCharacter_eventOnRightWeaponOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RPGCharacter_eventOnRightWeaponOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RPGCharacter_eventOnRightWeaponOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((RPGCharacter_eventOnRightWeaponOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(RPGCharacter_eventOnRightWeaponOverlap_Parms), &Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RPGCharacter_eventOnRightWeaponOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 267591329
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ARPGCharacter, nullptr, "OnRightWeaponOverlap", Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::RPGCharacter_eventOnRightWeaponOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::RPGCharacter_eventOnRightWeaponOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ARPGCharacter::execOnRightWeaponOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRightWeaponOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class ARPGCharacter Function OnRightWeaponOverlap ********************************

// ********** Begin Class ARPGCharacter ************************************************************
void ARPGCharacter::StaticRegisterNativesARPGCharacter()
{
	UClass* Class = ARPGCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnRightWeaponOverlap", &ARPGCharacter::execOnRightWeaponOverlap },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Montage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Montages\n" },
#endif
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Montages" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightWeaponCollision_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Combat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/RPGCharacter.h" },
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RightWeaponCollision;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ARPGCharacter_OnRightWeaponOverlap, "OnRightWeaponOverlap" }, // 3974639660
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_AttackMontage = { "AttackMontage", nullptr, (EPropertyFlags)0x0144000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, AttackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackMontage_MetaData), NewProp_AttackMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARPGCharacter_Statics::NewProp_RightWeaponCollision = { "RightWeaponCollision", nullptr, (EPropertyFlags)0x014400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARPGCharacter, RightWeaponCollision), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightWeaponCollision_MetaData), NewProp_RightWeaponCollision_MetaData) };
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
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_AttackMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARPGCharacter_Statics::NewProp_RightWeaponCollision,
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
	FuncInfo,
	Z_Construct_UClass_ARPGCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
		{ Z_Construct_UClass_ARPGCharacter, ARPGCharacter::StaticClass, TEXT("ARPGCharacter"), &Z_Registration_Info_UClass_ARPGCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARPGCharacter), 4231629213U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_4134683221(TEXT("/Script/UE5_RPG_Combat"),
	Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h__Script_UE5_RPG_Combat_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
