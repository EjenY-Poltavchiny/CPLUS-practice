#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
	system("chcp 1251");
	int a, b, result;
	char oper;
	while (true)
	{
		cin >> oper;
		if (oper != 'q') 
		{
			switch (oper)
			{
			case '+':
				cin >> a >> b;
				cout << a << " + " << b << " = " << sum(a, b) << endl;
				break;
			case '-':
				cin >> a >> b;
				cout << a << " - " << b << " = " << diff(a, b) << endl;
				break;
			case '*':
				cin >> a >> b;
				cout << a << " * " << b << " = " << mult(a, b) << endl;
				break;
			case '%':
				cin >> a >> b;
				cout << a << " % " << b << " = " << rem(a, b) << endl;
				break;
			case '/':
				cin >> a >> b;
				if (b != 0)
				{
					cout << a << " / " << b << " = " << divis(a, b) << endl;
				}
				else
				{
					cout << "Делить на ноль нельзя" << endl;
				}
				break;
			case '^':
				cin >> a >> b;
				cout << a << " ^ " << b << " = " << power(a, b) << endl;
				break;
			case '!':
				cin >> a;
				cout << a << "! " << " = " << fact(a) << endl;
				break;
			default:
				cout << "Извините, такой операции нет в этом калькуляторе." << endl;
			}
			cout << "Введите новую операцию и числа, для выхода введите 'q': "<< endl;
		} 
		else 
		{
			break;
		}
	} 
	return 0;
}
