#pragma once
#include <iostream>
#include <string>

class  IElectronics 
{
public:
	IElectronics(std::string brand, std::string provider) : _brand(brand), _provider(provider) {}
	virtual void Show() = 0;
	virtual std::string getType() {return type;}
	IElectronics() : _brand("none") {}
	virtual ~IElectronics() = default;
protected:
	std::string _brand;
	std::string _provider;
	std::string type = "none";                    // при помощи этого поля, умный ввод/вывод в функции main 
};					              // будет понимать что нужно ввести/вывести

//####################################################

class Appliances : virtual public IElectronics
{
public:
	Appliances(int weight);
	void Show() override;
protected:
	int _weight;
};

//####################################################

class Device : virtual public IElectronics
{
public:
	Device(int batteryLife);
	virtual ~Device() = default;
	void Show() override;
protected:
	int _batteryLife;
};


//####################################################


class Player final: public Device
{
public:
	Player(int batteryLife,  int totalTracks, std::string brand, std::string provider);
	Player();
	void Show() override;
	friend std::istream& operator >> (std::istream& in, Player* player);
private:
	int _totalTracks;

};

//####################################################


class Tablet final: public Device, Appliances
{
public:
	Tablet(int weight, int batteryLife, float diag,  std::string brand, std::string provider);
	Tablet();
	void Show() override;
	friend std::istream& operator >> (std::istream& in, Tablet* tablet);
private:
	float _diag;
};

//####################################################

class Fridge final : public Appliances
{
public:
	Fridge(int weight, float a, float b, std::string brand, std::string provider);
	Fridge();
	void Show() override;
	friend std::istream& operator >> (std::istream& in, Fridge* fridge);
private:
	float _camsize[2];
};

//####################################################

class Laptop final : public Appliances, Device
{
public:
	Laptop(int weight, int batteryLife, float diag, std::string brand, std::string CPU_model, std::string provider);
	Laptop();
	void Show() override;
	friend std::istream& operator >> (std::istream& in, Laptop* laptop);
private:
	float _diag;
	std::string _CPU_model;

};
