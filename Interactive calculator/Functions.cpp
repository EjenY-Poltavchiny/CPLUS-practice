#include "Functions.h"

// ������������
int sum(int a, int b)
{
	return a + b;
}
// ���������
int diff(int a, int b)
{
	return a - b;
}
// ���������
int mult(int a, int b)
{
	return a * b;
}
// �������
int divis(int a, int b)
{
	return a / b;
}
// ������� �� �������
int rem(int a, int b)
{
	return a % b;
}
// ���������� � �������
int power(int a, int b)
{
	if (b == 1)
	{
		return a;
	}
	return a * power(a, b - 1);
}
// ���������
int fact(int a)
{
	if (a == 1) {
		return 1;
	}
	return a * fact(a - 1);
}