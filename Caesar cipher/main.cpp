#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	char dir_shift, exitor = 0;
	int x = 0;
	int real_x = 0;                                        
	while (exitor != 'q')
	{
		int n;
		cout << "Введите количество символов в вашей строке: " << endl;
		cin >> n;
		char* stroka = new char[n+1];
		cout << "Введите строку: " << endl;
		for (int i = 0; i < n; ++i)
		{
			cin >> stroka[i];
		}
		cout << "Введите направление шифра: " << endl << " -- > если шифр 'вправо'" << endl
			<< " -- < если шифр 'влево'" << endl;
		cin >> dir_shift;                                         
		if (dir_shift == '>')
		{
			cout << "Введите сдвиг шифра: ";
			cin >> x;
			x %= 26;
			for (int i = 0; i < n; ++i)
			{
				if (stroka[i] > 64 && stroka[i] < 91)        // на случай, если меняем заглавные буквы
				{
					if (stroka[i] + x > 90)
					{
						real_x = stroka[i] + x - 26;
						stroka[i] = real_x;
					}
					else {
						stroka[i] += x;
					}
				}
				else if (stroka[i] > 96 && stroka[i] < 123)  // на случай, если меняем обычные буквы (убран else if т.к. ввод 
				{                                            // не предусматривает ничего кроме заглавных и прописных букв)
					if (stroka[i] + x > 122)
					{
						real_x = stroka[i] + x - 26;
						stroka[i] = real_x;
					}
					else {
						stroka[i] += x;
					}
				}
				cout << stroka[i];
			}
		}
		else if (dir_shift == '<')
		{
			cout << "Введите сдвиг шифра: ";
			cin >> x;
			x %= 26;
			for (int j = 0; j < n; ++j)
			{
				if (stroka[j] > 64 && stroka[j] < 91)           // не понятно почему выделяется зелёным ...
				{
					if (stroka[j] - x < 65)
					{
						real_x = stroka[j] + 26 - x;
						stroka[j] = real_x;
					}
					else {
						stroka[j] -= x;
					}
				}
				else if (stroka[j] > 96 && stroka[j] < 123)
				{
					if (stroka[j] - x < 97)
					{
						real_x = stroka[j] + 26 - x;
						stroka[j] = real_x;
					}
					else {
						stroka[j] -= x;
					}
				}
				cout << stroka[j];
			}
		}
		else
		{
			cout << "Выберите направление сдвига согласно инструкции!" << endl;
		}
		cout << endl << "Желаете выйти ?" << endl << " -- 'q' если да" << endl
			<< " -- любой другой символ иначе" << endl;
		delete[] stroka;
		cin >> exitor;
	}
	return 0;
}
