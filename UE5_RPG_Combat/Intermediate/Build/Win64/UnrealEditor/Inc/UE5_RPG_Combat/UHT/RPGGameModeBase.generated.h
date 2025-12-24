// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameMode/RPGGameModeBase.h"

#ifdef UE5_RPG_COMBAT_RPGGameModeBase_generated_h
#error "RPGGameModeBase.generated.h already included, missing '#pragma once' in RPGGameModeBase.h"
#endif
#define UE5_RPG_COMBAT_RPGGameModeBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ARPGGameModeBase *********************************************************
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGGameModeBase_NoRegister();

#define FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARPGGameModeBase(); \
	friend struct Z_Construct_UClass_ARPGGameModeBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGGameModeBase_NoRegister(); \
public: \
	DECLARE_CLASS2(ARPGGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UE5_RPG_Combat"), Z_Construct_UClass_ARPGGameModeBase_NoRegister) \
	DECLARE_SERIALIZER(ARPGGameModeBase)


#define FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARPGGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ARPGGameModeBase(ARPGGameModeBase&&) = delete; \
	ARPGGameModeBase(const ARPGGameModeBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARPGGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARPGGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARPGGameModeBase) \
	NO_API virtual ~ARPGGameModeBase();


#define FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h_7_PROLOG
#define FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h_10_INCLASS_NO_PURE_DECLS \
	FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ARPGGameModeBase;

// ********** End Class ARPGGameModeBase ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_GameMode_RPGGameModeBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
