#include <iostream>
#include <string>

struct answer
{
	int number;
	char letter;
	answer()
	{
		number = 0;
		letter = ' ';
	}
};

int main()
{
	answer ans;
        std::string s;
	int cnt = 0;
	getline(std::cin, s);
	for (int i = 0; i < s.size(); ++i)
        {
		cnt = 0;
		for (int j = 0; j < s.size(); ++j)
		{
			if (s[i] == s[j])
			{
				cnt += 1;
			}
		}
		if (cnt > ans.number)
		{
			ans.number = cnt;
			ans.letter = s[i];
        	}
	}	
	std::cout << ans.letter << " " << ans.number << std::endl;
	return 0;
}

