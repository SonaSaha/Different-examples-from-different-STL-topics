#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>

int main()
{
	std::map<std::string, int> m1;
	std::map<std::string, int> m2;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::string s1;
		std::string s2;
		std::cin >> s1;
		std::cin >> s2;
		m1.emplace(s1, 100);
		m1.emplace(s2, 100);
		int x;
		std::cin >> x;
		auto it = m1.find(s1);
		it->second += x;
		if (it->second > 100)
		{
			it->second = 100;
		}
		auto it1 = m1.find(s2);
		it1->second -= x;
		
	}
	for (auto elem : m1)
	{
		std::cout << elem.first << " " << elem.second << "\n";
	}
}