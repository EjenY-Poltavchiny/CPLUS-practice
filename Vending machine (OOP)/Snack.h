#pragma once
#include <string>

class Snack
{
private:
	std::string name;
	float price;
public:
	Snack(std::string, float);
	Snack(std::string);
	Snack();
	std::string getName();
	float getPrice();
	friend std::ostream& operator <<(std::ostream& out, const Snack& snak);
	Snack& operator = (const Snack& snak);
};

