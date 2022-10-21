#pragma once
#include "Potion.h"
class HealthPotion : public Potion
{
public:
	HealthPotion() { name = "HealthPotion"; };
	void Use() override;
};

