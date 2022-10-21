#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	bool isSwordEquiped = false;
	bool isBowEquiped = false;
	virtual void Equip(){};
};

