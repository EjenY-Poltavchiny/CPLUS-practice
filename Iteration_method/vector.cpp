#include "vector.h"
#include "matrix.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

vect::vect()
{
	size = 0;
	data = nullptr;
}

vect::vect(int a)
{
	size = a;
	data = new double[a];
	for (int i = 0; i < a; ++i)
	{
		data[i] = 0;
	}
}

vect::vect(int a, double* new_data)
{
	size = a;
	data = new double[a];
	for (int i = 0; i < a; ++i)
	{
		data[i] = new_data[i];
	}
}

vect::~vect()
{
	if (this->data != nullptr)
	{
		delete[] data;
	}
}

void vect::print_vect()
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

double* vect::get_vect()
{
	return data;
}

int vect::get_size()
{
	return size;
}

void vect::set_vect(int new_size, double* new_data)
{
	size = new_size;
	delete[] data;
	data = new double[new_size];
	for (int i = 0; i < new_size; ++i)
	{
		data[i] = new_data[i];
	}
}

vect& vect::operator=(const vect& a)
{
	if (this != &a)
	{
		data = new double[a.size];
		for (int i = 0; i < a.size; ++i)
		{
			this->data[i] = a.data[i];
		}
		this->size = a.size;
	}
	this->size = a.size;
	return *this;
}

void vect::mult_double(double a)
{
	for (int i = 0; i < size; ++i)
	{
		data[i] *= a;
	}
}

void vect::create_vector()
{
	int a;
	std::cout << "Dimension: ";
	std::cin >> a;
	size = a;
//=================== delete old data ==================
	delete[] data;
//=================== create new data ==================
	double* new_data = new double[size];
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Give me " << i+1 << " coordinate: ";
		std::cin >> new_data[i];
	}
	std::cout << std::endl;
	data = new_data;
}


vect operator+(const vect& a, const vect& b) {

	if (a.size != b.size) {
		std::cout << "Vectors should be the same dimension";
		exit(0);
	}
	double* data_result = new double[a.size];

	for (int i = 0; i < a.size; ++i) {
		data_result[i] = a.data[i] + b.data[i];
	}

	return vect(a.size, data_result);
}

vect operator-(const vect& a, const vect& b) {

	if (a.size != b.size) {
		std::cout << "Vectors should be the same dimension";
		exit(0);
	}
	double* data_result = new double[a.size];

	for (int i = 0; i < a.size; ++i) {
		data_result[i] = a.data[i] - b.data[i];
	}

	return vect(a.size, data_result);
}

vect mult(matr& a, vect& b)
{
	if (a.get_columns() != b.size)
	{
		std::cout << "Cannot multiply this matrix and vector! ";
		exit(0);
	}

	double* answer = new double[a.get_rows()];
	for (int i = 0; i < a.get_rows(); ++i) 
	{
		double res = 0;
		for (int j = 0; j < a.get_columns(); ++j) 
		{
			res += a.get_matr()[i][j] * b.get_vect()[j];
		}
		answer[i] = res;
	}

	return vect(a.get_rows(), answer);
}

double vect::vector_norm()
{
	double n = 0;
	for (int i = 0; i < size; ++i) {
		n += data[i] * data[i];
	}
	return sqrt(n);
}
