#include <iostream>
#include <string>
#include <map>

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
	std::cout << "String: ";
	getline(std::cin, s);
	std::map <char, int> mp;
	for (const char elem: s)
	{
		if (!mp.count(elem))
		{
			mp[elem] = 0;
		}
		mp[elem] += 1;
	}
	std::map <char, int> :: iterator it;
	it = mp.begin();
	ans.letter = it->first;
	ans.number = it->second;
	for ( ; it != mp.end(); ++it)
	{
		//std::cout << "Key " << it->first << ", Value " << it->second << std::endl;
		if (it->second > ans.number)
		{
			ans.letter = it->first;
			ans.number = it->second;
		}
	}
	std::cout << ans.letter << " " << ans.number << std::endl;
	return 0;
}

