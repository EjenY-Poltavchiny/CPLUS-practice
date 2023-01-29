#include <iostream>
#include <string>

int main()
{
	std::string in_str, answer;
	int counter = 0;
	getline(std::cin, in_str);
	char local_symb = in_str[0];
	char loc_amount;
	for (int i = 0; i < in_str.size(); ++i)
	{
		if (in_str[i] < 65 || in_str[i] > 90)
		{
			std::cout << "You need to enter correct format string!" << std::endl;
			exit(1);
		}
		if (in_str[i] != local_symb)
		{
			answer.push_back(in_str[i-1]);
			if (counter != 1)
			{
				answer += std::to_string(counter);
			}
			local_symb = in_str[i];
			counter = 0;
		}
		counter++;
	}
	answer.push_back(in_str[in_str.size() - 1]);
	if (in_str.size() > 1 && counter > 1)
	{
		answer += std::to_string(counter);
	}
	std::cout << answer << std::endl;
}

