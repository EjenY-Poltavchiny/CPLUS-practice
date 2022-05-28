#include <iostream>
#include "Electronics.h"

Device::Device(int batteryLife) : _batteryLife(batteryLife) {}

void Device::Show()
{
	std::cout << "Продукт компании " << _brand << std::endl
	 << "Время работы аккумулятора: " << _batteryLife << " часов" << std::endl;
}


//####################################################################################

Appliances::Appliances(int weight) : _weight(weight) {}

void Appliances::Show()
{
	std::cout << " Продукт компании " << _brand << std::endl
		<< "Масса: " << _weight << " грамм" << std::endl;
}

//####################################################################################



Player::Player(int battery, int totalTracks, std::string brand, std::string provider) : Device(battery),
IElectronics(brand, provider), _totalTracks(totalTracks) {type = "player";}

Player::Player() : Device(0), IElectronics("none ", "none "), _totalTracks(0) {}

void Player::Show()
{
	std::cout << "Музыкальный плеер компании " << _brand << std::endl
		<< "Время работы аккумулятора: " << _batteryLife << " часов" << std::endl
		<< "Треков можно записать: " << _totalTracks << std::endl
		<< "Поставщик: " << _provider << std::endl;
}

std::istream& operator >> (std::istream& in, Player* player)
{
	player->type = "player";
	std::cout << "Производитель: " << std::endl;
	in >> player->_brand;
	std::cout << "Время жизни аккумулятора без питания (часов): " << std::endl;
	in >> player->_batteryLife;
	std::cout << "Вместимость (количество композиций): " << std::endl;
	in >> player->_totalTracks;
	std::cout << "Поставщик:" << std::endl;
	in >> player->_provider;
	return in;
}

//####################################################################################

Tablet::Tablet(int weight, int batteryLife, float diag, std::string brand, std::string provider) : Appliances(weight),
Device(batteryLife), _diag(diag), IElectronics(brand, provider) {type = "tablet";}

Tablet::Tablet() : Appliances(0), Device(0), _diag(0), IElectronics("none", "none") { type = "tablet";}

void Tablet::Show() 
{
	std::cout << "Планшет компании " << _brand << std::endl
		<< "Масса: " << _weight << " грамм" << std::endl
		<< "Время работы аккумулятора: " << _batteryLife << " часов" << std::endl
		<< "Диагональ: " << _diag << " дюйм" << std::endl
		<< "Поставщик: " << _provider << std::endl;
}

std::istream& operator >> (std::istream& in, Tablet* tablet)
{
	tablet->type = "tablet";
	std::cout << "Производитель: " << std::endl;
	in >> tablet->_brand;
	std::cout << "Масса (грамм): " << std::endl;
	in >> tablet->_weight;
	std::cout << "Время жизни аккумулятора без питания (часов): " << std::endl;
	in >> tablet->_batteryLife;
	std::cout << "Диагональ (дюйм): " << std::endl;
	in >> tablet->_diag;
	std::cout << "Поставщик:" << std::endl;
	in >> tablet->_provider;
	return in;
}

//####################################################################################

Fridge::Fridge(int weight, float a, float b, std::string brand, std::string provider) :Appliances(weight), IElectronics(brand, provider) 
{
	type = "fridge"; 
	_camsize[0] = a;
	_camsize[1] = b;
}

Fridge::Fridge() :Appliances(0),
IElectronics("none" , "none")
{
	type = "fridge";
	_camsize[0] = 0;
	_camsize[1] = 0;
}

void Fridge::Show()
{
	std::cout << "Холодильник компании " << _brand << std::endl
		<< "Масса: " << _weight << " килограмм" << std::endl
		<< "Размер холодильной камеры: " << _camsize[0] << "x" << _camsize[1] << " сантиметров" << std::endl
		<< "Поставщик: " << _provider << std::endl;
}

std::istream& operator >> (std::istream& in, Fridge* fridge)
{
	fridge->type = "fridge";
	std::cout << "Производитель: " << std::endl;
	in >> fridge->_brand;
	std::cout << "Масса (килограмм): " << std::endl;
	in >> fridge->_weight;
	std::cout << "Высота (см): " << std::endl;
	in >> fridge->_camsize[0];
	std::cout << "Ширина (см): " << std::endl;
	in >> fridge->_camsize[1];
	std::cout << "Поставщик:" << std::endl;
	in >> fridge->_provider;
	return in;
}

//####################################################################################

Laptop::Laptop(int weight, int batteryLife, float diag, std::string brand, std::string CPU_model, std::string provider) : Appliances(weight),
Device(batteryLife), _diag(diag), _CPU_model(CPU_model), IElectronics(brand, provider) {type = "laptop";}

Laptop::Laptop() : Appliances(0),
Device(0), _diag(0), _CPU_model("none"), IElectronics("none", "none") {
	type = "laptop";
}

void Laptop::Show()
{
	std::cout << "Ноутбук компании " << _brand << std::endl
		<< "Масса: " << _weight << " грамм" << std::endl
		<< "Время работы аккумулятора: " << _batteryLife << " часов" << std::endl
		<< "Диагональ: " << _diag << " см" << std::endl
		<< "Модель процессора: " << _CPU_model << std::endl 
		<< "Поставщик: " << _provider << std::endl;
}

std::istream& operator >> (std::istream& in, Laptop* laptop)
{
	laptop->type = "laptop";
	std::cout << "Производитель: " << std::endl;
	in >> laptop->_brand;
	std::cout << "Масса (грамм): " << std::endl;
	in >> laptop->_weight;
	std::cout << "Диагональ (см): " << std::endl;
	in >> laptop->_diag;
	std::cout << "Время жизни аккумулятора без питания (часов): " << std::endl;
	in >> laptop->_batteryLife;
	std::cout << "Модель процессора: " << std::endl;
	in >> laptop->_CPU_model;
	std::cout << "Поставщик:" << std::endl;
	in >> laptop->_provider;
	return in;
}


