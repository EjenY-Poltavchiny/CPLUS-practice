#include <iostream>
#include "SnackSlot.h"
#include "Snack.h"

SnackSlot::SnackSlot(int SlotSize, Snack* snacks)
{
	snack = snacks;
	this->SlotSize = SlotSize;
	position = 0;

}

SnackSlot::SnackSlot(int SlotSize)
{
	this->SlotSize = SlotSize;
	position = 0;
	Snack* snack = new Snack[SlotSize];
	this->snack = snack;
}

SnackSlot::SnackSlot()
{
	this->SlotSize = 0;
	this->position = 0;
	Snack* snack = new Snack[1];
	this->snack = snack;
}

SnackSlot::~SnackSlot()
{
	delete[] snack;
}

void SnackSlot::addSnack(Snack* snack)
{
	while (this->snack[position].getName() != "empty")
	{
		++position;
	}
	this->snack[position] = *snack;
	++position;
}

int SnackSlot::getSlotSize()
{
	return this->SlotSize;
}


Snack& SnackSlot::getSnack(int position) const
{
	return this->snack[position - 1];
}


void SnackSlot::setSnack(int position, Snack* snack)
{
	this->snack[position - 1] = *snack;
}

std::ostream& operator <<(std::ostream& out, const SnackSlot* slot)
{
	out << "Размер слота: " << slot->SlotSize << std::endl << "=======================" << std::endl;
	for (int i = 0; i < slot->SlotSize; ++i)
	{
		out << slot->getSnack(i + 1) << std::endl;
	}
	return out;
}

SnackSlot& SnackSlot::operator = (const SnackSlot& slot)
{
	this->position = slot.position;
	this->SlotSize = slot.SlotSize;
	*snack = *slot.snack;
	return *this;
}


