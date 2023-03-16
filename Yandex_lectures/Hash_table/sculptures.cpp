#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main()
{
	size_t N;
	int X;
	long long int T;
	std::cin >> N >> X >> T;
	std::vector<int> operations(N+1);
	std::map<int, std::vector<long int>> sculptures;
	std::vector<int> answer;
	int input;
	for (size_t i = 1; i < N + 1; ++i)
	{
		std::cin >> input;
		operations[i] = abs(input - X);
	}
	for (size_t i = 1; i < N + 1; ++i)
	{
		sculptures[operations[i]].push_back(i);
	}

	for (auto& operation : sculptures)
	{
		if (T - operation.first >= 0)
		{
			for (auto& elem : operation.second)
			{
				if (T - operation.first >= 0)
				{
					T -= operation.first;
					answer.push_back(elem);
				}
				else
					break;
			}

		}
		else
			break;
	}
	std::sort(answer.begin(), answer.end());
	if (answer.size())
	{
		std::cout << answer.size() << std::endl;
		for (size_t i = 0; i < answer.size(); ++i)
		{
			std::cout << answer[i] << " ";
		}
	}
	else
		std::cout << 0;
}