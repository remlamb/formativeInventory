#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	Sword() { name = "Sword"; };
	void Use() override;
	void Equip() override;
};

