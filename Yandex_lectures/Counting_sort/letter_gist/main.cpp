#include <iostream>
#include <map>
#include <fstream>
#include <string>

int main()
{
	std::string input;
	int cur_max = 0;
	std::map<char, int> let_count;
	std::ifstream in("input.txt");
	while (getline(in, input))
	{
		for (auto& let : input)
		{
			if (let == ' ')
				continue;
			if (let_count.find(let) != let_count.end())
			{
				let_count[let] += 1;
			}
			else
			{
				let_count[let] = 1;
			}
		}
	}
	for (auto& [letter, counter] : let_count)
	{
		if (counter > cur_max)
		{
			cur_max = counter;
		}
	}
	for (size_t i = 0; i < cur_max; ++i)
	{
		for (auto& [letter, counter] : let_count)
		{
			if (counter >= cur_max - i)
			{

				std::cout << "#";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	for (auto& [letter, counter] : let_count)
	{
		std::cout << letter;
	}
}
