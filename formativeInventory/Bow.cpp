#include "Bow.h"

void Bow::Equip() {
	isSwordEquiped = false;
	isBowEquiped = true;
	std::cout << "You equip a bow" << std::endl;
}

void Bow::Use() {
	if (isBowEquiped) {
		std::cout << "Boing, you shot an arrow" << std::endl;
	}
	else if (isSwordEquiped) {
		std::cout << "You equipped the wrong weapon" << std::endl;
	}
	else {
		std::cout << "Look like you have nothing in your hand" << std::endl;
	}
}