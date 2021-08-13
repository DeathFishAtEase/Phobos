#include "AttachmentTypeClass.h"

#include <Utilities/TemplateDef.h>

Enumerable<AttachmentTypeClass>::container_t Enumerable<AttachmentTypeClass>::Array;

const char* Enumerable<AttachmentTypeClass>::GetMainSection()
{
	return "AttachmentTypes";
}

void AttachmentTypeClass::LoadFromINI(CCINIClass* pINI)
{
	const char* section = this->Name;

	INI_EX exINI(pINI);

	this->RestoreAtCreation.Read(exINI, section, "RestoreAtCreation");
	this->InheritTilt.Read(exINI, section, "InheritTilt");
	this->InheritCommands.Read(exINI, section, "InheritCommands");
	this->InheritOwner.Read(exINI, section, "InheritOwner");
	this->SyncStateEffects.Read(exINI, section, "SyncStateEffects");

	this->SyncHealth.Read(exINI, section, "SyncHealth");
	this->SyncHealth_IsRelative.Read(exINI, section, "SyncHealth.IsRelative");
	this->SyncExperience.Read(exINI, section, "SyncExperience");
	this->SyncExperience_IsRelative.Read(exINI, section, "SyncExperience.IsRelative");

	this->CanBeForceDetached.Read(exINI, section, "CanBeForceDetached");
	this->RestoreAtHealth.Read(exINI, section, "RestoreAtHealth");

	this->ForceDetachWeapon_Child.Read(exINI, section, "ForceDetachWeapon.Child");
	this->ForceDetachWeapon_Parent.Read(exINI, section, "ForceDetachWeapon.Parent");
	this->DestructionWeapon_Child.Read(exINI, section, "DestructionWeapon.Child");
	this->DestructionWeapon_Parent.Read(exINI, section, "DestructionWeapon.Parent");
}

template <typename T>
void AttachmentTypeClass::Serialize(T& Stm)
{
	Stm
		.Process(this->RestoreAtCreation)
		.Process(this->InheritTilt)
		.Process(this->InheritCommands)
		.Process(this->InheritOwner)
		.Process(this->SyncStateEffects)
		.Process(this->SyncHealth)
		.Process(this->SyncHealth_IsRelative)
		.Process(this->SyncExperience)
		.Process(this->SyncExperience_IsRelative)
		.Process(this->CanBeForceDetached)
		.Process(this->RestoreAtHealth)
		.Process(this->ForceDetachWeapon_Child)
		.Process(this->ForceDetachWeapon_Parent)
		.Process(this->DestructionWeapon_Child)
		.Process(this->DestructionWeapon_Parent)
		;
}

void AttachmentTypeClass::LoadFromStream(PhobosStreamReader& Stm)
{
	this->Serialize(Stm);
}

void AttachmentTypeClass::SaveToStream(PhobosStreamWriter& Stm)
{
	this->Serialize(Stm);
}
