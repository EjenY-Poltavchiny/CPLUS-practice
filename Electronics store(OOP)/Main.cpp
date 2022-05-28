#include <iostream>
#include "Electronics.h"

int main(int arac, char* argv) {
	system("chcp 1251");

	IElectronics* store[100]; // ����� �� 100 �������
	
	store[0] = new Player(15, 100, "samsung", "������");
	store[1] = new Tablet(400, 20, 10.5, "Ipad", "���");
	store[2] = new Fridge(30, 180, 100, "ATLANT", "������");
	store[3] = new Laptop(1700, 18, 16.6, "Mac Air", "M1", "������");
	store[4] = new Tablet(600, 24, 10, "Lenovo", "������");

	int pointer = 5;
	int button = 1;
	std::cout << "����� ���������� �� CaT �����" << std::endl;
	while (button)
	{
			std::cout << "�������� ��������:" << std::endl << "1. ������� ���������� ������" << std::endl <<
			"2. ������� ��� ������� ������ ����" << std::endl << "3. �������� ������ � �����" << std::endl << "0. �����" << std::endl;
		std::cin >> button;
		switch (button)
		{
		case 1:
		{
			for (int i = 0; i < pointer; ++i)
			{
				std::cout << i + 1 << "#####################" << std::endl;
				store[i]->Show();
				std::cout << std::endl;
			}
			break;
		}
		case 2:
		{
			std::string type;
			int counter = 0;
			std::cout << "������� ��� ������� {��� CaT ������ ���������� ������: player, fridge, tablet, laptop}" << std::endl;
			std::cin >> type;
			for (int i = 0; i < pointer; ++i)
			{
				if (store[i]->getType() == type)
				{
					std::cout << i + 1 << "#####################" << std::endl;
					store[i]->Show();
					std::cout << std::endl;
					++counter;
				}	
			}
			if (counter == 0)
			{
				std::cout << "�������� ������ ���� ��� �� ������" << std::endl;
			}
			break;
		}
		case 3:
		{
			int button2;
			std::cout << "����� ������ ����������� �� �����?" << std::endl << "1. �������" << std::endl <<
				"2. �������" << std::endl << "3. �����" << std::endl << "4. �����������" << std::endl;
			std::cin >> button2;
			switch (button2)
			{
			case 1:
			{
				Laptop* laptop = new Laptop();
				std::cin >> laptop;
				store[pointer] = laptop;
				++pointer;
				break;
			}
			case 2:
			{
				Tablet* tablet = new Tablet();
				std::cin >> tablet;
				store[pointer] = tablet;
				++pointer;
				break;
			}
			case 3:
			{
				Player* player = new Player();
				std::cin >> player;
				store[pointer] = player;
				++pointer;
				break;
			}
			case 4:
			{
				Fridge* fridge = new Fridge();
				std::cin >> fridge;
				store[pointer] = fridge;
				++pointer;
				break;
			}
			default:
			{
				std::cout << "� ����� ����������� ������ ����������������� ���� ��������!!!" << std::endl;
				break;
			}
			}
			break;
		}
		case 0:
		{
			std::cout << "����� �������!" << std::endl;
			break;
		}
		default:
			std::cout << "�������� ����������!!!" << std::endl;
			break;
		}
	}

	for (int i = 0; i < pointer; ++i)
	{
		delete store[i];
	}
	return 0;
}