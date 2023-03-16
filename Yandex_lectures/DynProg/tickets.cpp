#include <iostream>
#include <vector>
#include <limits>
#include <set>

// We have queue, each member can by ticket for him, for him and second member, for him and to next members
// Our task is to calculate min amount of time wich needed fot all members to be with tickets

std::pair<int, int> find_min(int x, int x_id, int y, int y_id, int z, int z_id)
{
	if (x <= y && x <= z)
	{ 
		return { x, x_id };
	}
	else if (y <= x && y <= z)
	{
		{
			return { y, y_id };
		}
	}
	else
		return { z, z_id };
}

int main()
{
	size_t N;
	std::cin >> N;
	std::vector<std::vector<int>> queue(N + 3, std::vector<int>(3));
	std::vector<int> dinprog(N + 3);
	std::vector<int> prev(N + 3);
	std::set<int> positions;
	int answer = 0;
	std::pair<int, int> current;
	for (size_t i = 0; i < N + 3; ++i)
	{
		if (i < 3)
		{
			dinprog[i] = 0;
			queue[i][0] = queue[i][1] = queue[i][2] = std::numeric_limits<int>::max();
			continue;
		}
		for (size_t j = 0; j < 3; ++j)
		{
			std::cin >> queue[i][j];
		}
		current = find_min(dinprog[i - 3] + queue[i - 2][2], i - 2,
			dinprog[i - 2] + queue[i - 1][1], i - 1,
			dinprog[i - 1] + queue[i][0], i);
		dinprog[i] = current.first;
		prev[i] = current.second;
	}
	size_t cur_pos = prev.back();
	std::cout << "Total time: " << dinprog.back() << std::endl;
	std::cout << dinprog.back();
	{
		positions.insert(cur_pos - 2);
		cur_pos = prev[cur_pos - 1];
	}
	for (auto& elem : positions)
	{
		std::cout << elem << " ";
	}
}
