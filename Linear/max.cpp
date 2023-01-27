#include <iostream>
#include "max.h"

//One maximum task  

int maximum(int* mass, int n)
{
	if (n == 0)
	{	
		std::cout << "There is no maximum in empty sequence" << std::endl;
		exit(1);
	}
	int ans = mass[0];
	for (int i = 0; i < n; ++i)
	{
		if (ans < mass[i])
		{
			ans = mass[i];
		}
	}
	return ans;
}

// Noneven-max

int noneven_max(int* mass, int n)
{
	bool flg = 0;
	if (n == 0)
        {
                std::cout << "There is no maximum in empty sequence" << std::endl;
                exit(1);
        }
        int ans = mass[0];
        for (int i = 0; i < n; ++i)
        {
                if ((mass[i] % 2 != 0) && (ans < mass[i] || flg == 0))
                {
                        ans = mass[i];
			flg = true;
                }
        }
	if (flg == 0)
	{	
		std::cout << "There is even numbers" << std::endl;
		exit(1);
	}
        return ans;
}


//Two maximum task

struct answer max_pseudomax(int* mass, int n)
{
	answer ans;
	if (n < 2)
        {
                std::cout << "Need sequence with length > 2" << std::endl;
                exit(1);
        }
	if (mass[0] > mass[1])
	{
		ans.first = mass[1];
		ans.second = mass[0];
	}
	else
	{
		ans.first = mass[0];
		ans.second = mass[1];
	}
	for (int i = 2; i < n; ++i)
	{
		if (mass[i] > ans.second)
		{
			ans.first = ans.second;
			ans.second = mass[i];
		}
		else if (mass[i] > ans.first)
		{
			ans.first = mass[i];
		}
	}
	return ans;
}

int main ()
{
	int a[9] {4, 1, 20000, 1, 0, 2, 4, 10, 12};
	std::cout << noneven_max(a, 9);
}
