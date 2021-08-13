#include "AttachmentClass.h"

#include <BulletClass.h>
#include <BulletTypeClass.h>
#include <WarheadTypeClass.h>

#include <Ext/Techno/Body.h>

AttachmentTypeClass* AttachmentClass::GetType()
{
	return AttachmentTypeClass::Array[this->Data->Type].get();
}

TechnoTypeClass* AttachmentClass::GetChildType()
{
	return this->Data->TechnoType.isset()
		? TechnoTypeClass::Array()->GetItem(this->Data->TechnoType)
		: nullptr;
}

void AttachmentClass::Initialize()
{
	if (this->Child)
		return;

	if (this->GetType()->RestoreAtCreation)
		this->CreateChild();
}

void AttachmentClass::CreateChild()
{
	if (auto const pChildType = this->GetChildType())
	{
		if (this->Child = static_cast<TechnoClass*>(pChildType->CreateObject(this->Parent->Owner)))
		{
			auto const pChildExt = TechnoExt::ExtMap.Find(this->Child);
			pChildExt->ParentAttachment = this;
		}
		else
		{
			Debug::Log("[" __FUNCTION__ "] Failed to create child %s of parent %s!\n",
				pChildType->ID, this->Parent->GetTechnoType()->ID);
		}
	}
}

void AttachmentClass::AI()
{
	AttachmentTypeClass* pType = this->GetType();

	if (this->Child)
	{
		this->Child->SetLocation(TechnoExt::GetFLHAbsoluteCoords(
			this->Parent, this->Data->FLH, this->Data->IsOnTurret));

		DirStruct childDir = this->Data->IsOnTurret
			? this->Parent->SecondaryFacing.current() : this->Parent->PrimaryFacing.current();

		this->Child->PrimaryFacing.set(childDir);

		if (pType->InheritTilt)
		{
			this->Child->AngleRotatedForwards = this->Parent->AngleRotatedForwards;
			this->Child->AngleRotatedSideways = this->Parent->AngleRotatedSideways;
		}

		if (pType->InheritOwner)
			this->Child->SetOwningHouse(this->Parent->GetOwningHouse(), false);
	}
}

// Doesn't call destructor (to be managed by smart pointers)
void AttachmentClass::Uninitialize()
{
	if (this->Child)
	{
		if (this->GetType()->DestructionWeapon_Child.isset())
			TechnoExt::FireWeaponAtSelf(this->Child, this->GetType()->DestructionWeapon_Child);
	}

	auto pChildExt = TechnoExt::ExtMap.Find(this->Child);
	pChildExt->ParentAttachment = nullptr;
}

void AttachmentClass::ChildDestroyed()
{
	AttachmentTypeClass* pType = this->GetType();
	if (pType->DestructionWeapon_Parent.isset())
		TechnoExt::FireWeaponAtSelf(this->Parent, pType->DestructionWeapon_Parent);

	this->Child = nullptr;
}

void AttachmentClass::Unlimbo()
{
	if (this->Child)
	{
		CoordStruct childCoord = TechnoExt::GetFLHAbsoluteCoords(
			this->Parent, this->Data->FLH, this->Data->IsOnTurret);

		Direction::Value childDir = this->Data->IsOnTurret
			? this->Parent->SecondaryFacing.current().value256() : this->Parent->PrimaryFacing.current().value256();

		++Unsorted::IKnowWhatImDoing;
		this->Child->Unlimbo(childCoord, childDir);
		--Unsorted::IKnowWhatImDoing;
	}
}

void AttachmentClass::Limbo()
{
	if (this->Child)
		this->Child->Limbo();
}

bool AttachmentClass::AttachChild(TechnoClass* pChild)
{
	if (this->Child || this->Data->TechnoType.isset())
		return false;

	this->Child = pChild;

	auto pChildExt = TechnoExt::ExtMap.Find(this->Child);
	pChildExt->ParentAttachment = this;

	AttachmentTypeClass* pType = this->GetType();

	if (pType->InheritOwner)
	{
		if (auto pController = this->Child->MindControlledBy)
			pController->CaptureManager->FreeUnit(this->Child);
	}

	return true;
}

bool AttachmentClass::DetachChild(bool isForceDetachment)
{
	if (this->Child)
	{
		AttachmentTypeClass* pType = this->GetType();

		if (isForceDetachment)
		{
			if (pType->ForceDetachWeapon_Parent.isset())
				TechnoExt::FireWeaponAtSelf(this->Parent, pType->DestructionWeapon_Parent);

			if (pType->ForceDetachWeapon_Child.isset())
				TechnoExt::FireWeaponAtSelf(this->Child, pType->DestructionWeapon_Child);
		}

		if (pType->InheritOwner)
			this->Child->SetOwningHouse(this->Parent->GetOriginalOwner(), false);

		auto pChildExt = TechnoExt::ExtMap.Find(this->Child);
		pChildExt->ParentAttachment = nullptr;
		this->Child = nullptr;

		return true;
	}

	return false;
}

#pragma region Save/Load

template <typename T>
bool AttachmentClass::Serialize(T& stm)
{
	return stm
		.Process(this->Data)
		.Process(this->Parent)
		.Process(this->Child)
		.Success();
};

bool AttachmentClass::Load(PhobosStreamReader& stm, bool RegisterForChange)
{
	return Serialize(stm);
}

bool AttachmentClass::Save(PhobosStreamWriter& stm) const
{
	return const_cast<AttachmentClass*>(this)->Serialize(stm);
}

#pragma endregion