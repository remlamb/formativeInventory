#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "HealthPotion.h"
#include "Bow.h"
#include "Map.h"

int main()
{
    Inventory inventory;
    inventory.GiveItemOnStart();
    inventory.Menu();

}
