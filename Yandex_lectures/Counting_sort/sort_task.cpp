#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> num_to_vec(int number)
{
	std::vector<int> result;
	while (number != 0)
	{
		result.push_back(number % 10);
		number = number / 10;
	}
	return result;
}

std::vector<int> unsigned_count_sort(std::vector<int>& vec)
{
	size_t max = *max_element(vec.begin(), vec.end());
	size_t min = *min_element(vec.begin(), vec.end());
	int size = max - min + 1;
	std::vector<int> sorted(size);
	for (auto& elem : vec)
	{
		sorted[elem - min] += 1;
	}
	return sorted;
}


// The task is to implemetn count sort and use it to check can we get one number from another by reshuffling digits
int main()
{
	int number;
	int input;
	std::cin >> number >> input;
	std::vector<int> num = num_to_vec(number);
	std::vector<int> inp = num_to_vec(input);
	std::vector<int> num_comp = unsigned_count_sort(num);
	std::vector<int> inp_comp = unsigned_count_sort(inp);
	if (num_comp == inp_comp)
	{
		std::cout << "YES, you can!" << std::endl;
	}
	else
	{
		std::cout << "NO, you can't!" << std::endl;
	}
	/*std::vector<int> answer_num = unsigned_count_sort(test);
	for (int i = 0; i < answer.size(); ++i)
	{
		for (int j = 0; j < answer[i]; ++j)
		{
			std::cout << i << " ";
		}

	}*/
	return 0;
}