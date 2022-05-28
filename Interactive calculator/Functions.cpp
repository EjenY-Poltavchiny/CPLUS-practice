#include "Functions.h"

// суммирование
int sum(int a, int b)
{
	return a + b;
}
// вычитание
int diff(int a, int b)
{
	return a - b;
}
// умножение
int mult(int a, int b)
{
	return a * b;
}
// деление
int divis(int a, int b)
{
	return a / b;
}
// остаток от деления
int rem(int a, int b)
{
	return a % b;
}
// возведение в степень
int power(int a, int b)
{
	if (b == 1)
	{
		return a;
	}
	return a * power(a, b - 1);
}
// факториал
int fact(int a)
{
	if (a == 1) {
		return 1;
	}
	return a * fact(a - 1);
}