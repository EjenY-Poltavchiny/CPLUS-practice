#include <iostream>
#include "Snack.h"
#include "SnackSlot.h"
#include "VendingMachine.h"

int main() {
	// комментирую C++
	system("chcp 1251");
	Snack* bounty = new Snack("Bounty", 55);
	Snack* lays = new Snack("Lays_cheese", 65);
	Snack* snickers = new Snack("Snickers", 55);
	Snack* milka = new Snack("Milka", 85);		     // Проверка доп.возможностей
	SnackSlot* slot = new SnackSlot(10);
	SnackSlot* slot1 = new SnackSlot(4);		     // Проверка доп. возможностей
	
	slot->addSnack(bounty); 
	slot->addSnack(snickers);
	slot->setSnack(4, milka);
	slot->setSnack(3, bounty);
	slot->setSnack(6, bounty); 
	slot->addSnack(lays);
	VendingMachine* machine = new VendingMachine(6);   

	machine->addSlot(slot);      // Помещаем слот обратно в аппарат
	machine->addSlot(slot1);
	slot1->addSnack(snickers);
	machine->setSlot(6, slot);
							     // Проверка доп. возможностей
	std::cout << slot;
	std::cout << slot1;
	std::cout << machine;
	
	std::cout << machine->getEmptySlotsCount(); // Должно выводить количество пустых слотов для снеков
	delete machine;
	delete slot;
	delete snickers;
	delete bounty;
	
	return 0;
}
