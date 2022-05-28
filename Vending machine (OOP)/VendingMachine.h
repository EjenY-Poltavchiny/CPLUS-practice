#pragma once
#include "SnackSlot.h"
#include "Snack.h"

class VendingMachine
{
private:
	SnackSlot* slot = new SnackSlot;
	int position;
	int slots_num;
public:
	VendingMachine(int);
	~VendingMachine();
	void addSlot(SnackSlot*);
	int getEmptySlotsCount();
	friend std::ostream& operator << (std::ostream&, const VendingMachine*);
	void setSlot(int, SnackSlot*);
};