#include "Sword.h"

void Sword::Equip() {
	 std::cout << "You equip a sword" << std::endl;
}

void Sword::Use() {

	if (isSwordEquiped) {
		std::cout << "Tsing, your sword hit something" << std::endl;
	}
	else if (isBowEquiped) {
		std::cout << "You equipped the wrong weapon" << std::endl;
	}
	else {
		std::cout << "Look like you have nothing in your hand" << std::endl;
	}
}