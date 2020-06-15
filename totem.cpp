#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>
#include <string>
#include <variant>
int main()
{
	int totem_count;
	std::cin >> totem_count;
	std::set<int> s;
	for (int i = 1; i <= totem_count; ++i)
	{
		s.insert(i);
	}
	int years;
	std::cin >> years;
	std::set<int> s1;
	for (int i = 0; i < years; ++i)
	{
		std::string ss;
		std::cin >> ss;
		std::set<int>& who_gives = ss == "Mbongo" ? s : s1;
		std::set<int>& who_accepts = ss == "Mbongo" ? s1 : s;
		who_accepts.insert(*who_gives.begin());
		who_gives.erase(who_gives.begin());

	}
	long long sum1 = 0;
	for (auto elem : s)
		sum1 += elem;
	long long sum2 = 0;
	for (auto elem : s)
		sum2 += elem;
	std::cout << sum1 << " " << sum2;
	
	
}