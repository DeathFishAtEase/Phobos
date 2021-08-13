#include "Body.h"

#include <Ext/TechnoType/Body.h>

DEFINE_HOOK(0x4DA86E, FootClass_AI_UpdateAttachedLocomotion, 0x0)
{
	GET(FootClass*, pThis, ESI);

	if (!TechnoExt::AttachmentAI(pThis))
		pThis->Locomotor->Process();

	return 0x4DA87A;
}

DEFINE_HOOK(0x710460, TechnoClass_Destroy_HandleHostDestruction, 0x6)
{
	GET(TechnoClass*, pThis, ECX);

	TechnoExt::HandleHostDestruction(pThis);

	return 0;
}

DEFINE_HOOK(0x6F6F20, TechnoClass_Unlimbo_UnlimboAttachments, 0x6)
{
	GET(TechnoClass*, pThis, ESI);

	TechnoExt::UnlimboAttachments(pThis);

	return 0;
}

DEFINE_HOOK(0x6F6B1C, TechnoClass_Limbo_LimboAttachments, 0x6)
{
	GET(TechnoClass*, pThis, ESI);

	TechnoExt::LimboAttachments(pThis);

	return 0;
}