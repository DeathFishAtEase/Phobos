#include "Body.h"

#include <Ext/TechnoType/Body.h>

DEFINE_HOOK(0x4DA86E, FootClass_AI_UpdateAttachedLocomotion, 0x0)
{
	GET(FootClass*, pThis, ESI);
	auto const pExt = TechnoExt::ExtMap.Find(pThis);
	auto const pTypeExt = TechnoTypeExt::ExtMap.Find(pThis->GetTechnoType());

	if (pExt && pExt->ParentTechno)
	{
		// bool oldOnMap = pThis->IsOnMap;
		// pThis->IsOnMap = false;

		pThis->SetLocation(TechnoExt::GetFLHAbsoluteCoords(
			pExt->ParentTechno, pExt->ParentFLH, pExt->ParentIsOnTurret));

		// pThis->IsOnMap = oldOnMap;

		DirStruct childDir = pExt->ParentIsOnTurret
			? pExt->ParentTechno->SecondaryFacing.current() : pExt->ParentTechno->PrimaryFacing.current();

		pThis->PrimaryFacing.set(childDir);
	}
	else
	{
		pThis->Locomotor->Process();
	}

	return 0x4DA87A;
}