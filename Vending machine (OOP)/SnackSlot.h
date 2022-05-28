#pragma once
#include "Snack.h"

class SnackSlot
{
private:
	int SlotSize;
	int position;
	Snack* snack;
public:
	SnackSlot(int, Snack*);
	SnackSlot(int);
	SnackSlot();
	~SnackSlot();
	friend std::ostream& operator <<(std::ostream& out, const SnackSlot* slot);
	SnackSlot& operator = (const SnackSlot& slot);
	void addSnack(Snack*);
	int getSlotSize();
	Snack& getSnack(int) const;
	void setSnack(int, Snack*);
};
