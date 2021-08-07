#include <InfantryClass.h>

#include "Body.h"

#include <Ext/TechnoType/Body.h>

DEFINE_HOOK(0x6F9E50, TechnoClass_AI, 0x5)
{
	GET(TechnoClass*, pThis, ECX);
	auto pExt = TechnoExt::ExtMap.Find(pThis);

	TechnoExt::ApplyMindControlRangeLimit(pThis);
	TechnoExt::ApplyInterceptor(pThis);
	TechnoExt::ApplyPowered_KillSpawns(pThis);
	TechnoExt::ApplySpawn_LimitRange(pThis);
	TechnoExt::ApplyCloak_Undeployed(pThis);

	// LaserTrails update routine is in TechnoClass::AI hook because TechnoClass::Draw
	// doesn't run when the object is off-screen which leads to visual bugs - Kerbiter
	for (auto const& trail: pExt->LaserTrails)
		trail->Update(TechnoExt::GetFLHAbsoluteCoords(pThis, trail->FLH, trail->IsOnTurret));

	return 0;
}


DEFINE_HOOK(0x6F42F7, TechnoClass_Init, 0x2)
{
	GET(TechnoClass*, pThis, ESI);
	auto const pTypeExt = TechnoTypeExt::ExtMap.Find(pThis->GetTechnoType());

	TechnoExt::InitializeLaserTrails(pThis);

	if (pTypeExt && pTypeExt->ChildTechno.isset())
	{
		auto pChildType = TechnoTypeClass::Array()->GetItem(pTypeExt->ChildTechno);
		if (TechnoClass* pChild = static_cast<TechnoClass*>(pChildType->CreateObject(pThis->Owner)))
		{
			CoordStruct childCoord = TechnoExt::GetFLHAbsoluteCoords(
				pThis, pTypeExt->ChildTechno_FLH, pTypeExt->ChildTechno_IsOnTurret);

			Direction::Value childDir = pTypeExt->ChildTechno_IsOnTurret
				? pThis->SecondaryFacing.current().value256() : pThis->PrimaryFacing.current().value256();

			auto const pChildExt = TechnoExt::ExtMap.Find(pChild);
			pChildExt->ParentTechno = pThis;
			pChildExt->ParentFLH = pTypeExt->ChildTechno_FLH;
			pChildExt->ParentIsOnTurret = pTypeExt->ChildTechno_IsOnTurret;

			++Unsorted::IKnowWhatImDoing;
			pChild->Unlimbo(childCoord, childDir);
			--Unsorted::IKnowWhatImDoing;
		}
	}

	return 0;
}

DEFINE_HOOK_AGAIN(0x7355C0, TechnoClass_Init_InitialStrength, 0x6) // UnitClass_Init
DEFINE_HOOK_AGAIN(0x517D69, TechnoClass_Init_InitialStrength, 0x6) // InfantryClass_Init
DEFINE_HOOK_AGAIN(0x442C7B, TechnoClass_Init_InitialStrength, 0x6) // BuildingClass_Init
DEFINE_HOOK(0x414057, TechnoClass_Init_InitialStrength, 0x6)       // AircraftClass_Init
{
	GET(TechnoClass*, pThis, ESI);

	if (R->Origin() != 0x517D69)
	{
		if (auto pTypeExt = TechnoTypeExt::ExtMap.Find(pThis->GetTechnoType()))
		{
			if (R->Origin() != 0x442C7B)
				R->EAX(pTypeExt->InitialStrength.Get(R->EAX<int>()));
			else
				R->ECX(pTypeExt->InitialStrength.Get(R->ECX<int>()));
		}
	}
	else if (auto pTypeExt = TechnoTypeExt::ExtMap.Find(pThis->GetTechnoType()))
	{
		auto strength = pTypeExt->InitialStrength.Get(R->EDX<int>());
		pThis->Health = strength;
		pThis->EstimatedHealth = strength;
	}

	return 0;
}