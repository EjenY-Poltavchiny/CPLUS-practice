#include <iostream>
#include "SnackSlot.h"
#include "Snack.h"
#include "VendingMachine.h"

VendingMachine::VendingMachine(int slots_num)
{
	this->slots_num = slots_num;
	position = 0;
	SnackSlot* slot = new SnackSlot[slots_num];
	this->slot = slot;
}

VendingMachine::~VendingMachine()
{
	delete[] slot;
}


void VendingMachine::addSlot(SnackSlot* slot)
{
	this->slot[position] = *slot;
	++position;
}

void VendingMachine::setSlot(int position, SnackSlot* slot)
{
	this->slot[position - 1] = *slot;
}

int VendingMachine::getEmptySlotsCount()
{
	int counter = 0;
	for (int i = 0; i < slots_num; ++i)
	{
		if (this->slot[i].getSlotSize() == 0)
		{
			counter++;
		}
	}
	std::cout << "Количество свбодных слотов: ";
	return counter;
}

std::ostream& operator << (std::ostream& out, const VendingMachine* machine)
{
	for (int i = 0; i < machine->slots_num; ++i)
	{
		out << "Слот № "<< i+1 << " Размер слота: " << machine->slot[i].getSlotSize() << std::endl;
	}
	std::cout << std::endl;
	return out;
}

