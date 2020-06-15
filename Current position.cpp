#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::string first;
	std::string second;
	double f;
	double s;
	std::string cur;
	std::map<std::string, int> m;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> cur;
		std::istringstream iss(cur);
		std::getline(iss, first, '-');
		std::getline(iss, second, ':');
		iss >> f;
		char a;
		iss >> a;
		iss >> s;
		auto it1 = m.emplace(first, f);
		if (!it1.second)
		{
			it1.first->second += f;
		}
		auto it2 = m.emplace(second, s);
		if (!it2.second)
		{
			it2.first->second += s;
		}
	}

	std::map<int, std::vector<std::string>> res;
	for (auto elem : m)
	{
		std::vector <std::string> vec({ elem.first });
		auto el = std::make_pair(elem.second, vec);
		auto iter = res.insert(el);
		if (!iter.second)
		{
			iter.first->second.push_back(elem.first);
		}
	}
	int i = 1;
	for (auto el : res)
	{
		if (el.second.size() == 1)
		{
			std::cout << i << ". " << *el.second.begin() << " " << "- " << el.first << "\n";
			++i;
		}
		else
		{
			std::cout << i << " - " << el.second.size() << ". ";
			for (int j = 0; j < el.second.size(); ++j)
			{
				std::cout << el.second[j];
				if (j != el.second.size() - 1)
				{
					std::cout << ", ";
				}
				else
				{
					std::cout << "-" << el.first << "\n";
				}
				++i;
			}
		}
	}
}