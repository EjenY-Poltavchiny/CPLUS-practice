#include <iostream>
#include "max.h"


int main()
{
	int n;
	std::cout << "Amount of heights: ";
	std::cin >> n;
	int* hg = new int[n];
	std::cout << "Type heights for island: ";
	for (int i = 0; i < n; ++i)
	{
		std::cin >> hg[i];
	}
	int max_hg = maximum(hg, n).first;
	int max_hg_id = maximum(hg, n).second;
	while (max_hg)
	{
		for (int j = 0; j < n; ++j)
		{
			if (max_hg - hg[j] > 0)
			{
				std::cout << "  ";
			}
			else 
			{
				std::cout << "||";
			}
		}
		std::cout << std::endl;
		--max_hg;
	}
	int loc_max = hg[0];
	int answer = 0;
	for (int i = 0; i < max_hg_id + 1; ++i)
	{
		if (loc_max >= hg[i])
		{
			answer += loc_max - hg[i];
		}
		else
		{
			loc_max = hg[i];
		}
	}
	loc_max = hg[n-1];
	for (int i = n-1; i > max_hg_id - 1; --i)
        {
                if (loc_max >= hg[i])
                {
                        answer += loc_max - hg[i];
                }
                else
                {
                        loc_max = hg[i];
                }
        }
	std::cout << answer << std::endl;
	delete [] hg;
}
