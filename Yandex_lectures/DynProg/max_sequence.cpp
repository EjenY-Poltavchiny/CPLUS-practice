#include <iostream>
#include <vector>
#include <set>

// Task is to implement function to calculate max increasing subsequnece  

int main()
{
	int cur_length = 1;
	size_t cur_pos = -1;
	int N;
	std::cin >> N;
	std::vector<int> input(N);
	std::vector<int> dinprog(N);
	std::vector<int> prev(N);
	std::set<int> subsequence;
	std::pair<int, size_t> answer;
	for (size_t i = 0; i < N; ++i)
	{
		std::cin >> input[i];
		for (size_t j = 0; j < i; ++j)
		{
			if (input[j] < input[i])
			{
				if (cur_length < dinprog[j] + 1)
				{
					cur_pos = j;
				}
				cur_length = cur_length > dinprog[j] + 1 ? cur_length : dinprog[j] + 1;
			}		
		}
		prev[i] = cur_pos;
		dinprog[i] = cur_length;
		cur_pos = -1;
		cur_length = 1;
	}
	answer.first = dinprog[0];
	for (size_t i = 0; i < dinprog.size(); ++i)
	{
		if (dinprog[i] > answer.first)
		{
			answer.first = dinprog[i];
			answer.second = i;
		}
	}
	subsequence.insert(answer.second);
	int element = answer.second;
	while (prev[element] != -1)
	{
		subsequence.insert(prev[element]);
		element = prev[element];
	}
	std::cout << subsequence.size() << std::endl;
	for (auto& elem : subsequence)
	{
		std::cout << elem << " ";
	}
	
}