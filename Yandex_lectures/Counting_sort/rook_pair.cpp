#include <iostream>
#include <unordered_map>

void fill_map(std::unordered_map<int, int>& dict, std::vector<int> vec)
{
	for (auto& elem : vec)
	{
		if (dict.find(elem) != dict.end())
		{
			dict[elem]++;
		}
		else
		{
			dict[elem] = 1;
		}
	}
}


// We have some chess field N x N and M rooks. Our task is to output amount of rook pairs wich can beat each other.

int main()
{
	int answer = 0;
	std::unordered_map<int, int> rook_pair_x;
	std::vector<int> rook_x;
	std::unordered_map<int, int> rook_pair_y;
	std::vector<int> rook_y;
	int x, y;
	int N, M;
	std::cin >> N >> M;
	rook_pair_x.reserve(N);
	//rook_pair_y.reserve(N);
	for (int i = 0; i < M; ++i)
	{
		std::cin >> x >> y;
		rook_x.push_back(x);
		rook_y.push_back(y);
	}
	fill_map(rook_pair_x, rook_x);
	fill_map(rook_pair_y, rook_y);
	for (auto& [key, value] : rook_pair_x)
	{
		answer += value - 1;
	}
	for (auto& [key, value] : rook_pair_y)
	{
		answer += value - 1;
	}
	std::cout << answer << std::endl;
}