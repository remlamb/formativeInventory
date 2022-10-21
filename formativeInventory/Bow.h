#pragma once
#include "Weapon.h"
class Bow : public Weapon
{
public:
	Bow() { name = "Bow"; };
	void Equip() override;
	void Use() override;
};

