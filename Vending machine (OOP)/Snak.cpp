#include <string>
#include "Snack.h"
#include "SnackSlot.h"
#include <iostream>



Snack::Snack(std::string name, float price)
{
	this->name = name;
	this->price = price;
}
Snack::Snack(std::string name)
{
	this->name = name;
}

Snack::Snack()
{
	name = "empty";
	price = 0.0;
}

std::string Snack::getName()
{
	return name;
}

float Snack::getPrice()
{
	return price;
}


Snack& Snack::operator=(const Snack& snack)
{
	this->name = snack.name;
	this->price = snack.price;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Snack& snack)
{
	out << "Продукт: " << snack.name << std::endl
		<< "Цена: " << snack.price << std::endl;
	return out;
}


