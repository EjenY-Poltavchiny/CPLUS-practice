#include <iostream>
#include "Electronics.h"

Device::Device(int batteryLife) : _batteryLife(batteryLife) {}

void Device::Show()
{
	std::cout << "������� �������� " << _brand << std::endl
	 << "����� ������ ������������: " << _batteryLife << " �����" << std::endl;
}


//####################################################################################

Appliances::Appliances(int weight) : _weight(weight) {}

void Appliances::Show()
{
	std::cout << " ������� �������� " << _brand << std::endl
		<< "�����: " << _weight << " �����" << std::endl;
}

//####################################################################################



Player::Player(int battery, int totalTracks, std::string brand, std::string provider) : Device(battery),
IElectronics(brand, provider), _totalTracks(totalTracks) {type = "player";}

Player::Player() : Device(0), IElectronics("none ", "none "), _totalTracks(0) {}

void Player::Show()
{
	std::cout << "����������� ����� �������� " << _brand << std::endl
		<< "����� ������ ������������: " << _batteryLife << " �����" << std::endl
		<< "������ ����� ��������: " << _totalTracks << std::endl
		<< "���������: " << _provider << std::endl;
}

std::istream& operator >> (std::istream& in, Player* player)
{
	player->type = "player";
	std::cout << "�������������: " << std::endl;
	in >> player->_brand;
	std::cout << "����� ����� ������������ ��� ������� (�����): " << std::endl;
	in >> player->_batteryLife;
	std::cout << "����������� (���������� ����������): " << std::endl;
	in >> player->_totalTracks;
	std::cout << "���������:" << std::endl;
	in >> player->_provider;
	return in;
}

//####################################################################################

Tablet::Tablet(int weight, int batteryLife, float diag, std::string brand, std::string provider) : Appliances(weight),
Device(batteryLife), _diag(diag), IElectronics(brand, provider) {type = "tablet";}

Tablet::Tablet() : Appliances(0), Device(0), _diag(0), IElectronics("none", "none") { type = "tablet";}

void Tablet::Show() 
{
	std::cout << "������� �������� " << _brand << std::endl
		<< "�����: " << _weight << " �����" << std::endl
		<< "����� ������ ������������: " << _batteryLife << " �����" << std::endl
		<< "���������: " << _diag << " ����" << std::endl
		<< "���������: " << _provider << std::endl;
}

std::istream& operator >> (std::istream& in, Tablet* tablet)
{
	tablet->type = "tablet";
	std::cout << "�������������: " << std::endl;
	in >> tablet->_brand;
	std::cout << "����� (�����): " << std::endl;
	in >> tablet->_weight;
	std::cout << "����� ����� ������������ ��� ������� (�����): " << std::endl;
	in >> tablet->_batteryLife;
	std::cout << "��������� (����): " << std::endl;
	in >> tablet->_diag;
	std::cout << "���������:" << std::endl;
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
	std::cout << "����������� �������� " << _brand << std::endl
		<< "�����: " << _weight << " ���������" << std::endl
		<< "������ ����������� ������: " << _camsize[0] << "x" << _camsize[1] << " �����������" << std::endl
		<< "���������: " << _provider << std::endl;
}

std::istream& operator >> (std::istream& in, Fridge* fridge)
{
	fridge->type = "fridge";
	std::cout << "�������������: " << std::endl;
	in >> fridge->_brand;
	std::cout << "����� (���������): " << std::endl;
	in >> fridge->_weight;
	std::cout << "������ (��): " << std::endl;
	in >> fridge->_camsize[0];
	std::cout << "������ (��): " << std::endl;
	in >> fridge->_camsize[1];
	std::cout << "���������:" << std::endl;
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
	std::cout << "������� �������� " << _brand << std::endl
		<< "�����: " << _weight << " �����" << std::endl
		<< "����� ������ ������������: " << _batteryLife << " �����" << std::endl
		<< "���������: " << _diag << " ��" << std::endl
		<< "������ ����������: " << _CPU_model << std::endl 
		<< "���������: " << _provider << std::endl;
}

std::istream& operator >> (std::istream& in, Laptop* laptop)
{
	laptop->type = "laptop";
	std::cout << "�������������: " << std::endl;
	in >> laptop->_brand;
	std::cout << "����� (�����): " << std::endl;
	in >> laptop->_weight;
	std::cout << "��������� (��): " << std::endl;
	in >> laptop->_diag;
	std::cout << "����� ����� ������������ ��� ������� (�����): " << std::endl;
	in >> laptop->_batteryLife;
	std::cout << "������ ����������: " << std::endl;
	in >> laptop->_CPU_model;
	std::cout << "���������:" << std::endl;
	in >> laptop->_provider;
	return in;
}


