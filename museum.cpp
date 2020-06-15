#include "pch.h"
#include <iostream>
#include <set>
#include <numeric>
#include <string>

int main()
{
	
	int n;
	int k;
	std::cin >> n;
	std::cin >> k;
	std::set<int> s;
	for (int i = 0; i < k; ++i) 
	{
		std::string gift;
		std::cin >> gift;
		int value;
		std::cin >> value;
	
		if (s.size() >= n)
		{
			s.erase(s.begin());
		}
		s.insert(value);
		
	}
	std::cout << std::accumulate(s.begin(), s.end(), 0LL);
}