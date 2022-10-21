#pragma once
#include "Item.h"
#include "HealthPotion.h"
#include "ForcePotion.h"
#include "Sword.h"
#include "Bow.h"
#include "Map.h"
#include <vector>

class Inventory
{
public:
	std::vector<Item*> items;

	bool isSwordEquiped = false;
	bool isBowEquiped = false;

	void Add();	//function that print the choice of item addable, input a number and will use the function to create it

	void AddHealthPotion();	//function to create HealthPotion
	void AddForcePotion();	// to create Force Potion
	void AddSword();	// to create Sword
	void AddBow();	// to create a Bow
	void AddMap(std::string);	// to create a Map, need a string as description 

	void UseHealthPotion();	//Verified if we got an health potion in the inventory, use it with the UseItem fonction and then erased it from inventory or use NothingFound function 
	void UseForcePotion();	//Verified if we got an force potion in the inventory, use it with the UseItem fonction and then erased it from inventory or use NothingFound function
	void UseSword();	//Verified if we got a Sword in the inventory, use it with the UseItem fonction or use NothingFound function, Equip verification are done in the use() from sword class
	void UseBow();	//Verified if we got a Bow in the inventory, use it with the UseItem fonction or use NothingFound function, Equip verification are done in the use() from bow class
	void UseMap();	//Verified if we got a Bow in the inventory, use it with the UseItem fonction or use NothingFound function

	void UseItem(Item*);	//Print that you use an item in console then use the use() fonction from item class

	void SelectItemToUse();	//function that print the choice of item Usable, input a number and it will use it
	void SelectItemToEquip();	//function that print the choice of item Equipable, input a number and it will equip it

	void EquipASword();	//Equip the first Sword find in the inventory or print nothing found, set isSwordEquiped to true and isBowEquiped to false
	void EquipABow();	//Equip the first Bow find in the inventory or print nothing found, set isSwordEquiped to false and isBowEquiped to true
	void WeaponBoolManagement();	//put all the weapon bool equal to inventory bool 

	void Menu();

	//return true if item is from this child class
	bool IsAHealthPotion(Item* item);
	bool IsAForcePotion(Item* item);
	bool IsASword(Item* item);
	bool IsABow(Item* item);
	bool IsAMap(Item* item);

	void NothingFound();
	void ClearConsole();

	void GiveItemOnStart();
	void PrintInventory();

};

