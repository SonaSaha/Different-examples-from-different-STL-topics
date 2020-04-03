#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
bool Test(std::string s)
{
	if (std::count(s.begin(), s.end(), 'A') > 1)
		return false;
	auto it1 = std::find(s.begin(), s.end(), 'L');
	while (it1 != s.end() && it1 != s.end() - 1 && it1 != s.end() - 2)
	{

		if (*(it1 + 1) == 'L' && *(it1 + 2) == 'L')
			return false;
		
		it1 = std::find(it1+1, s.end(), 'L');
	}
	return true;
}
int main()
{
	std::string s;
	while (std::cin >> s)
	{
		if (Test(s))
		{
			std::cout << "yes";
		}
		else
		{
			std::cout << "no";
		}
	}
}