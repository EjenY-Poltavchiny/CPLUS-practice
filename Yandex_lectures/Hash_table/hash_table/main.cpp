#include <iostream>
#include <vector>
#include "hash.h"

int main()
{
	std::vector <std::vector<int>> test(10);
	add(6, test);
	std::cout << test.size() << std::endl;
	add(16, test);
	std::cout << test.size() << std::endl;
	add(36, test);
	std::cout << test.size() << std::endl;
	add(46, test);
	std::cout << test.size() << std::endl;
	add(9, test);
	std::cout << test.size() << std::endl;
	add(19, test);
	std::cout << test.size() << std::endl;
	add(29, test);
	std::cout << test.size() << std::endl;
	add(39, test);
	std::cout << test.size() << std::endl;
	add(59, test);
	std::cout << test.size() << std::endl;
	add(99, test);
	std::cout << test.size() << std::endl;
	del(99, test);
	if (find(99, test))
	{
		std::cout << "hello" << std::endl;
	}
	if (find(19, test))
	{
		std::cout << "hello" << std::endl;
	}
	del(100, test);
	del(89, test);
	return 0;
}
