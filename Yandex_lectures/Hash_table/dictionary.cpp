#include <iostream>
#include <unordered_set>
#include <string>

int main()
{
	std::string word;
	// words in dictionary
	std::unordered_set<std::string> words;
	int N;
	std::cin >> N;
	// our input
	std::vector <std::string> input;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> word;
		words.insert(word);
		for (size_t i = 0; i < word.size(); ++i)
		{
			words.insert(word.substr(0, i) + word.substr(i + 1));
		}
	}
	while (std::cin >> word) //u can break it with Ctrl+Z
	{
		input.push_back(word);
	}
	for (const std::string& elem : input)
	{
		if (words.contains(elem))
		{
			std::cout << elem << " contains at dictionary!" << std::endl;
		}
	}
}