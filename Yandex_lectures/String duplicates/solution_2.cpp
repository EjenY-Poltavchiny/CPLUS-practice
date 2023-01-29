#include <iostream>
#include <string>
#include <set>

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
	std::set <char> ses;
        answer ans;
        std::string s;
        int cnt = 0;
        getline(std::cin, s);
	for (int i = 0; i < s.size(); ++i)
	{
		ses.insert(s[i]);
	}
	for (auto& elem: ses)
	{
		cnt = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (elem == s[i])
			{
				cnt += 1;
			}
		}
                if (cnt > ans.number)
                {
                        ans.number = cnt;
                        ans.letter = elem;
                }
	}
        std::cout << ans.letter << " " << ans.number << std::endl;
        return 0;
}

