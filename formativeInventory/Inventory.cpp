#include "Inventory.h"



void Inventory::Add() {
	int currentChoice;
	std::cout << "1 to create a Map "<< std::endl << "2 to create an Health Potion" << std::endl << "3 to create a Force Potion" << std::endl << "4 to create a Sword" << std::endl << "5 to create a Bow" << std::endl;
	std::cin >> currentChoice;
	ClearConsole();

	if (currentChoice == 1) {
		std::string mapDescription;
		std::cout << "Enter the map description" << std::endl;
		std::cin >> mapDescription;
		AddMap(mapDescription);
	}

	else if (currentChoice == 2) {
		AddHealthPotion();
	}

	else if (currentChoice == 3) {
		AddForcePotion();
	}

	else if(currentChoice == 4){
		AddSword();
	}

	else if (currentChoice == 5) {
		AddBow();
	}

	std::cout << "Successfully Added" << std::endl << std::endl;
	Menu();

}

void Inventory::AddHealthPotion() {
	items.emplace_back(new HealthPotion());
}

void Inventory::AddForcePotion() {
	items.emplace_back(new ForcePotion());
}

void Inventory::AddSword() {
	items.emplace_back(new Sword());
}

void Inventory::AddBow() {
	items.emplace_back(new Bow());
}

void Inventory::AddMap(std::string mapDescription) {

	items.emplace_back(new Map(mapDescription));
}

void Inventory::UseHealthPotion() {
	int i = 0;
	for(const auto& item : items){ 
		if(IsAHealthPotion(item)){
			UseItem(item);
			//delete item after use
			items.erase(items.begin() + i);
			return;
		}
		i++;
	}
	NothingFound();
}
 
void Inventory::UseForcePotion() {
	int i = 0;
	for (const auto& item : items) {
		if (IsAForcePotion(item)) {
			UseItem(item);
			//delete item after use
			items.erase(items.begin() + i);
			return;
		}
		i++;
	}
	NothingFound();
}

void Inventory::UseSword() {
	for (const auto& item : items) {
		if (IsASword(item)) {
			UseItem(item);
			return;
		}
	}
	NothingFound();
}

void Inventory::UseBow() {	
	
	for (const auto& item : items) {
		if (IsABow(item)) {
			
			UseItem(item);
			return;
		}
	}
	NothingFound();
}

void Inventory::UseMap() {
	for (const auto& item : items) {
		if (IsAMap(item)) {
			UseItem(item);
			return;
		}
	}
	NothingFound();
}

void Inventory::UseItem(Item* item) {
	std::cout << "Use an item" << std::endl;
	item->Use();
}

void Inventory::SelectItemToUse() {
	int currentChoice;
	std::cout << "1 to use a Map " << std::endl << "2 to use an Health Potion " << std::endl << "3 to use a Force Potion " << std::endl << "4 to use a Sword " << std::endl << "5 to use a Bow " << std::endl;
	std::cin >> currentChoice;
	ClearConsole();

	if (currentChoice == 1) {
		UseMap();
	}

	else if (currentChoice == 2) {
		UseHealthPotion();
	}
	else if (currentChoice == 3) {
		UseForcePotion();
	}

	else if (currentChoice == 4) {
		UseSword();
	}

	else if (currentChoice == 5) {
		UseBow();
	}

	std::cout << std::endl;
	Menu();
}

void Inventory::SelectItemToEquip() {
	int currentChoice;
	std::cout << "1 to equip a Sword " << std::endl << "2 to equip a Bow" << std::endl;
	std::cin >> currentChoice;
	ClearConsole();

	if (currentChoice == 1) {
		EquipASword();
	}
	else if (currentChoice == 2) {
		EquipABow();
	}

	std::cout << std::endl;
	Menu();
}

void Inventory::EquipASword() {
	for (const auto& item : items) {
		Sword* sword = dynamic_cast<Sword*>(item);
		if (sword != nullptr) {
			isSwordEquiped = true;
			isBowEquiped = false;
			WeaponBoolManagement();
			sword->Equip();

			return;
		}
	}
	NothingFound();
}

void Inventory::EquipABow() {
	for (const auto& item : items) {
		Bow* bow = dynamic_cast<Bow*>(item);
		if (bow != nullptr) {
			isSwordEquiped = false;
			isBowEquiped = true;
			WeaponBoolManagement();
			bow->Equip();

			return;
		}
	}
	NothingFound();
}

void Inventory::WeaponBoolManagement() {
	for (const auto& item : items) {
		Weapon* w = dynamic_cast<Weapon*>(item);
		if (w != nullptr) {
			w->isSwordEquiped = isSwordEquiped;
			w->isBowEquiped = isBowEquiped;
		}
	}
}

void Inventory::Menu() {
	int currentChoice; 
	std::cout << "---  INVENTORY  ---" << std::endl;

	std::cout << "Actual Inventory : " << std::endl;
	PrintInventory();
	std::cout << "1 to use an item " << std::endl << "2 to add an item " << std::endl << "3 to equip a weapon" << std::endl << "4 to exit game" << std::endl;
	std::cin >> currentChoice;

	ClearConsole();
	if (currentChoice == 1) {
		SelectItemToUse();
	}

	else if (currentChoice == 2) {
		Add();
	}

	else if (currentChoice == 3) {
		SelectItemToEquip();
	}

	else if (currentChoice == 4) {
		ClearConsole();
	}
}

bool Inventory::IsAHealthPotion(Item* item) {
	HealthPotion* p = dynamic_cast<HealthPotion*>(item);
	if (p != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool Inventory::IsAForcePotion(Item* item) {
	ForcePotion* p = dynamic_cast<ForcePotion*>(item);
	if (p != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool Inventory::IsASword(Item* item) {
	Sword* s = dynamic_cast<Sword*>(item);
	if (s != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool Inventory::IsABow(Item* item) {
	Bow* b = dynamic_cast<Bow*>(item);
	if (b != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool Inventory::IsAMap(Item* item) {
	Map* m = dynamic_cast<Map*>(item);
	if (m != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void Inventory::ClearConsole() {
	std::cout << "\x1B[2J\x1B[H";
}

void Inventory::NothingFound() {
	std::cout << "You don't have that item";
}

void Inventory::GiveItemOnStart() {
	AddHealthPotion();
	AddHealthPotion();
	AddForcePotion();
	AddSword();
	AddMap("Your Home");
}

void Inventory::PrintInventory() {
	for (auto& item : items) {
		std::cout << " " << item->name << " |" ;
	}
	std::cout << std::endl << std::endl;
}