#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>

std::string chipher(std::string word)
{
	std::string output;
	std::map<char, int> symb_count;
	for (auto& symb : word)
	{
		symb_count[symb]++;
	}
	for (auto& [symbol, counter] : symb_count)
	{
		output.push_back(symbol);
		output += std::to_string(counter);
	}
	return output;
}

std::string sorted(std::string word)
{
	std::string output = word;
	std::sort(output.begin(), output.end());
	return output;
}

int main()
{
	std::string input;
	std::unordered_map<std::string, std::vector<std::string>> dictionary;
	while (std::cin >> input)
	{
		dictionary[sorted(input)].push_back(input);
	}
	for (auto& [key, words] : dictionary)
	{
		std::cout << "[";
		for (auto& word : words)
		{
			std::cout << " " << word;
		}
		std::cout << "] ";
	}
}