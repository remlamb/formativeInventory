#pragma once
#include "Item.h"

class Map : public Item
{
private:
	std::string _thePlace;
public:
	Map(const std::string& thePlace);
	void Use() override;
};

