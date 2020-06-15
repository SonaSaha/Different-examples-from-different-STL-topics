#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
int main()
{
	std::vector<int> v;
	std::vector<int> v0;
	int n1;
	std::cin >> n1;
	std::vector<int> v1(n1);
	for (int i = 0; i < n1; ++i)
	{
		std::cin >> v1[i];
	}
	int n2;
	std::cin >> n2;
	std::vector<int> v2(n2);
	for (int i = 0; i < n2; ++i)
	{
		std::cin >> v2[i];
	}
	int n3;
	std::cin >> n3;
	std::vector<int> v3(n3);
	for (int i = 0; i < n3; ++i)
	{
		std::cin >> v3[i];
	}
	std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v));
	std::set_intersection(v3.begin(), v3.end(), v.begin(), v.end(), std::back_inserter(v0));
	std::cout << v0.size();

}