#include <iostream>
#include <vector>
#include <set>

int fibon(size_t n, std::vector<int>& vec)
{
	if (vec[n-1] == -1)
	{
		vec[n-1] = fibon(n - 1, vec) + fibon(n - 2, vec);
	}
	return vec[n-1];
}

std::pair<int, size_t> find_max(int x, size_t x_id, int y, size_t y_id)
{
	std::pair<int, size_t> answer;
	if (x > y)
	{
		answer.first = x;
		answer.second = x_id;
	}
	else
	{
		answer.first = y;
		answer.second = y_id;
	}
	return answer;
}

int main()
{
	// Task is to implement function to get n fibon number

	/* Fibonachi test 
	size_t n;
	std::cin >> n;
	std::vector<int> dinprog (n, -1);
	dinprog[0] = dinprog[1] = 1;
	std::cout << fibon(n, dinprog); */

	// Task is to calculate max profit from the movements by step. We can go to next step or over 1 step.
	// Each step has points wich can be negative.

	size_t n;
	std::cin >> n;
	std::vector<int> dinprog(n + 2);
	std::vector<int> input(n + 2);
	std::vector<size_t> prev(n + 2);
	std::pair<int, size_t> cur_prev;
	std::set<size_t> answer;
	for (size_t i = 2; i < n + 2; ++i)
	{
		std::cin >> input[i];
		cur_prev = find_max(dinprog[i - 1], i - 1, dinprog[i - 2], i - 2);
		dinprog[i] = input[i] + cur_prev.first;
		if (i == 2)
		{
			prev[i] = 0;
		}
		else
		{
			prev[i] = cur_prev.second - 1;
		}
	}
	std::cout << dinprog[n + 1] << std::endl;
	for (size_t i = 2; i < n + 2; ++i)
	{
		answer.insert(prev[i]);
	}
	answer.insert(n);
	for (auto& elem : answer)
	{
		std::cout << elem << " ";
	}
}