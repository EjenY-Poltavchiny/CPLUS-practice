#include <iostream>
#include <vector>
#include <string>

// Task is to decompose number into operations with numbers < K (only + and *)
// Minimize amount of symblos. Consider the only symbols we can use is 
// ")", "(", "+", "*", "i" (where i from 1 to K)

int symb_amount(int x)
{
	int counter = 0;
	while (x != 0)
	{
		counter++;
		x = x / 10;
	}
	return counter;
}

int find_min(int x, int y, bool& flg)
{
	if (x < y)
	{
		flg = 1;
		return x;
	}
	flg = 0;
	return y;
}

std::pair<int, std::string> find_sum_min(size_t index, std::vector<int> sums, std::vector<std::string> sum_str, 
	std::vector<int> mults, std::vector<std::string> mult_str)
{
	bool sum_flg = 0;
	int temp = 0;
	int min = 0;
	std::string first;
	std::string second;
	std::string answer;
	for (size_t j = 1; j < index/2 + 1; ++j)
	{
		temp = find_min(sums[j], mults[j], sum_flg);
		first = sum_flg ? sum_str[j] : mult_str[j];
		
		temp+= find_min(sums[index - j], mults[index - j], sum_flg) + 1;
		second = sum_flg ? sum_str[index - j] : mult_str[index - j];
		
		if (j == 1)
		{
			min = temp;
			answer = first + "+" + second;
			continue;
		}
		if (temp < min)
		{
			min = temp;
			answer = first + "+" + second;
		}
	}
	return { min, answer };
}

std::pair<int, std::string> find_mult_min(size_t index, std::vector<int> sums, std::vector<std::string> sum_str,
	std::vector<int> mults, std::vector<std::string> mult_str)
{
	bool sum_flg = 0;
	int temp = 0;
	int min = 0;
	std::string first;
	std::string second;
	std::string answer;
	for (size_t j = 2; j < index; ++j)
	{
		if (index % j == 0)
		{
			temp = find_min(sums[j] + 2, mults[j], sum_flg);
			first = sum_flg ? "(" + sum_str[j] + ")" : mult_str[j];
			
			temp += find_min(sums[index / j] + 2, mults[index / j], sum_flg) + 1;
			second = sum_flg ? "(" + sum_str[index / j] + ")" : mult_str[index / j];

			if (j == 2)
			{
				min = temp;
				answer = first + "*" + second;
				continue;
			}
			if (temp < min)
			{
				min = temp;
				answer = first + "*" + second;
			}
		}
		else
		{
			temp = sums[index] + 2;
			if (j == 2)
			{
				min = temp;
				answer = "(" + sum_str[index] + ")";
				continue;
			}
			if (temp < min)
			{
				min = temp;
				answer = "(" + sum_str[index] + ")";
			}
		}
	}
	return { min, answer };
}

int main()
{
	bool flag = 0;
	size_t N, K;
	std::cin >> N >> K;
	std::vector<int> sums(N+1);
	std::vector<std::string> sum_str(N + 1);
	std::vector<int> mults(N+1);
	std::vector<std::string> mult_str(N + 1);
	for (size_t i = 1; i < K + 1; ++i)
	{
		sums[i] = symb_amount(i);
		sum_str[i] = std::to_string(i);
		mults[i] = symb_amount(i);
		mult_str[i] = std::to_string(i);
	}
	std::pair<int, std::string> curr_pair;
	for (size_t i = K + 1; i < N + 1; ++i)
	{
		curr_pair = find_sum_min(i, sums, sum_str, mults, mult_str);
		sums[i] = curr_pair.first;
		sum_str[i] = curr_pair.second;
		curr_pair = find_mult_min(i, sums, sum_str, mults, mult_str);
		mults[i] = curr_pair.first;
		mult_str[i] = curr_pair.second;
	}
	std::cout << "We need only " << find_min(sums.back(), mults.back(), flag) << " symbols!" << std::endl;
	if (flag)
	{
		std::cout << sum_str.back();
	}
	else
	{
		std::cout << mult_str.back();
	}
	return 0;
}