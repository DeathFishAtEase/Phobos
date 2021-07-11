#pragma once

/*
* YR's FoggedObjectClass is broken
* I decided to implement ours object class to gain full control
* 
* - FoggedObject
*	- FoggedOverlay
*	- FoggedTerrain
*	- FoggedSmudge
*	- FoggedAnim
*	- FoggedBuilding
* 
* According to RA3, All the items below will be drawn as what they stored like
* But infantry and vehicles do not displays
* 
* Author - secsome
*/

#include <GeneralStructures.h>

#include <vector>
#include <set>

class ObjectClass;
class ObjectTypeClass;
class CellClass;
class PhobosStreamReader;
class PhobosStreamWriter;

class FoggedObject
{
public:

	/// The fives
	FoggedObject(ObjectClass* pObject);
	FoggedObject();

	virtual ~FoggedObject();
	
	// Neither copy nor move is allowed
	FoggedObject(const FoggedObject& lhs) = delete;
	FoggedObject(FoggedObject&& rhs) = delete;
	FoggedObject& operator= (const FoggedObject& lhs) = delete;
	FoggedObject& operator= (FoggedObject&& rhs) = delete;

	/// Virtual Methods (Notice that our destructor is in virtual table too)
	virtual bool IsValid() const;
	virtual bool DrawIt(RectangleStruct& Bounds) const;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange);
	virtual bool Save(PhobosStreamWriter& Stm) const;

	/// Properties

	ObjectTypeClass* Type;
	CellClass* AttachedCell;

	/// Static array
	static std::set<FoggedObject*> Instances;
};

class FoggedOverlay final : public FoggedObject
{
public:

	/// The fives
	FoggedOverlay(ObjectClass* pObject);
	FoggedOverlay(CellClass* pCell);

	virtual ~FoggedOverlay() override;

	// Neither copy nor move is allowed
	FoggedOverlay(const FoggedOverlay& lhs) = delete;
	FoggedOverlay(FoggedOverlay&& rhs) = delete;
	FoggedOverlay& operator= (const FoggedOverlay& lhs) = delete;
	FoggedOverlay& operator= (FoggedOverlay&& rhs) = delete;

	/// Virtual Methods (Notice that our destructor is in virtual table too)
	virtual bool DrawIt(RectangleStruct& Bounds) const override;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange) override;
	virtual bool Save(PhobosStreamWriter& Stm) const override;

	/// Properties

	unsigned char OverlayData;

	/// Static array
	static std::set<FoggedOverlay*> Instances;
};

class FoggedTerrain final : public FoggedObject
{
public:

	/// The fives
	FoggedTerrain(ObjectClass* pObject);

	virtual ~FoggedTerrain() override;

	// Neither copy nor move is allowed
	FoggedTerrain(const FoggedTerrain& lhs) = delete;
	FoggedTerrain(FoggedTerrain&& rhs) = delete;
	FoggedTerrain& operator= (const FoggedTerrain& lhs) = delete;
	FoggedTerrain& operator= (FoggedTerrain&& rhs) = delete;

	/// Virtual Methods (Notice that our destructor is in virtual table too)
	virtual bool DrawIt(RectangleStruct& Bounds) const override;

	/// Static array
	static std::set<FoggedTerrain*> Instances;
};

class FoggedSmudge final : public FoggedObject
{
public:

	/// The fives
	FoggedSmudge(ObjectClass* pObject);
	FoggedSmudge(CellClass* pCell);

	virtual ~FoggedSmudge() override;

	// Neither copy nor move is allowed
	FoggedSmudge(const FoggedSmudge& lhs) = delete;
	FoggedSmudge(FoggedSmudge&& rhs) = delete;
	FoggedSmudge& operator= (const FoggedSmudge& lhs) = delete;
	FoggedSmudge& operator= (FoggedSmudge&& rhs) = delete;

	/// Virtual Methods (Notice that our destructor is in virtual table too)
	virtual bool DrawIt(RectangleStruct& Bounds) const override;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange) override;
	virtual bool Save(PhobosStreamWriter& Stm) const override;

	/// Properties

	int CurrentFrame;

	/// Static array
	static std::set<FoggedSmudge*> Instances;
};

class FoggedAnim final : public FoggedObject
{
public:

	/// The fives
	FoggedAnim(ObjectClass* pObject);

	virtual ~FoggedAnim() override;

	// Neither copy nor move is allowed
	FoggedAnim(const FoggedAnim& lhs) = delete;
	FoggedAnim(FoggedAnim&& rhs) = delete;
	FoggedAnim& operator= (const FoggedAnim& lhs) = delete;
	FoggedAnim& operator= (FoggedAnim&& rhs) = delete;

	/// Virtual Methods (Notice that our destructor is in virtual table too)
	virtual bool DrawIt(RectangleStruct& Bounds) const override;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange) override;
	virtual bool Save(PhobosStreamWriter& Stm) const override;

	/// Properties

	int CurrentFrame;
	CoordStruct Location;

	/// Static array
	static std::set<FoggedAnim*> Instances;
};

class FoggedBuilding final : public FoggedObject
{
public:

	/// The fives
	FoggedBuilding(ObjectClass* pObject);

	virtual ~FoggedBuilding() override;

	// Neither copy nor move is allowed
	FoggedBuilding(const FoggedAnim& lhs) = delete;
	FoggedBuilding(FoggedAnim&& rhs) = delete;
	FoggedBuilding& operator= (const FoggedBuilding& lhs) = delete;
	FoggedBuilding& operator= (FoggedBuilding&& rhs) = delete;

	/// Virtual Methods (Notice that our destructor is in virtual table too)
	virtual bool DrawIt(RectangleStruct& Bounds) const override;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange) override;
	virtual bool Save(PhobosStreamWriter& Stm) const override;

	/// Properties
	RectangleStruct Bound;
	Point2D Position;
	std::vector<FoggedAnim*> Animations;

	/// Static array
	static std::set<FoggedBuilding*> Instances;
};