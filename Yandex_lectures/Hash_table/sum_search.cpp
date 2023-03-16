#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
	int sum = 8;
	int numb;
	bool helper = 1;
	std::unordered_set<int> table;
	while (std::cin >> numb)
	{
		if (numb != sum - numb)
			table.insert(numb);
	}
	for (auto& elem : table)
	{
		if (table.contains(sum - elem))
		{
			std::cout << elem << " + " << sum - elem << " = " << sum << std::endl;
			helper = 0;
			break;
		}
	}
	if (helper)
	{
		std::cout << "There is no such pair! " << std::endl;
	}
}