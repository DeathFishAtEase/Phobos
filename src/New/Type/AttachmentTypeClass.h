#pragma once

#include <Utilities/Enumerable.h>
#include <Utilities/Template.h>

#include <TechnoTypeClass.h>

class AttachmentTypeClass final : public Enumerable<AttachmentTypeClass>
{
public:
	Valueable<bool> RestoreAtCreation; // whether to spawn the attachment initially
	// Inherit = propagate from host to attachment
	// Sync = propagate changes both ways
	Valueable<bool> InheritTilt;
	Valueable<bool> InheritCommands;
	Valueable<bool> InheritOwner; //aka mind control inheritance
	Valueable<bool> SyncStateEffects; // phasing out, stealth etc.
	Valueable<bool> SyncHealth;
	Valueable<bool> SyncHealth_IsRelative;
	Valueable<bool> SyncExperience;
	Valueable<bool> SyncExperience_IsRelative;
	// Explanation: 200 damage to 400 HP host with 200 HP part will...
	// - ...kill the part (200 - 200 = 0) if the mode is absolute
	// - ...leave the part alive (200 - 200*(200/400) = 100) if the mode is relative
	Valueable<bool> CanBeForceDetached;
	Nullable<int> RestoreAtHealth; // if host is healed to that health it's respawned
	Nullable<WeaponTypeClass*> ForceDetachWeapon_Child;
	Nullable<WeaponTypeClass*> ForceDetachWeapon_Parent;
	Nullable<WeaponTypeClass*> DestructionWeapon_Child;
	Nullable<WeaponTypeClass*> DestructionWeapon_Parent;

	// Targeting, verses, attachment health max/initial, immunities, possibility
	// to command are to be done on TechnoType itself


	AttachmentTypeClass(const char* pTitle = NONE_STR) : Enumerable<AttachmentTypeClass>(pTitle)
		, RestoreAtCreation(true)
		, InheritTilt(true)
		, InheritCommands(false)
		, InheritOwner(false)
		, SyncStateEffects(false)
		, SyncHealth(false)
		, SyncHealth_IsRelative(false)
		, SyncExperience(false)
		, SyncExperience_IsRelative(false)
		, CanBeForceDetached(false)
		, RestoreAtHealth()
		, ForceDetachWeapon_Child()
		, ForceDetachWeapon_Parent()
		, DestructionWeapon_Child()
		, DestructionWeapon_Parent()
	{ }

	virtual ~AttachmentTypeClass() override = default;

	virtual void LoadFromINI(CCINIClass* pINI) override;
	virtual void LoadFromStream(PhobosStreamReader& Stm);
	virtual void SaveToStream(PhobosStreamWriter& Stm);

private:
	template <typename T>
	void Serialize(T& Stm);
};