#pragma once
#include "Potion.h"
class ForcePotion : public Potion
{
public:
	ForcePotion() { name = "ForcePotion"; };
	void Use() override;
};

