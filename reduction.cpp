#include "pch.h"
#include <iostream>
#include <string>
#include <map>

int main()
{
	int n;
	std::cin >> n;
	std::string encrypt;
	std::string decrypt;
	std::map<std::string, std::string> m;
	bool t = true;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> encrypt >> decrypt;
		auto it = m.insert(std::make_pair(encrypt, decrypt));
		if (!it.second)
		{
			std::cout << "error";
			t = false;
		}
	}
	if (t)
	{
		std::string word;
		std::string result;
		while (std::cin >> word)
		{
			auto it1 = m.find(word);
			if (it1 != m.end())
			{
				result.append(it1->second);
				result.append(" ");
			}
			else
			{
				result.append(word);
				result.append(" ");
			}
		}
		std::cout << result;
	}
}