// Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Container With Most Water
//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
//n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).Find two lines,
//which together with x - axis forms a container, such that the container contains the most water.
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

int MaxArea(std::vector<int>& height)
{
	int size = height.size();
	auto first = height.begin();
	auto last = height.end();
	--last;
	int min;
	if (size == 0 || size == 1)
	{
		return 0;
	}
	int courrentArea;
	int maxArea = 0;
	while (first != last)
	{
		min = std::min(*first, *last);
		courrentArea = min * (last - first);
		if (maxArea < courrentArea)
		{
			maxArea = courrentArea;
		}
		if (*first < *last)
		{
			++first;
		}
		else
		{
			--last;
		}
	}
	return maxArea;
}
int main()
{
	for (int i = 0; i < 3; ++i)
	{
		std::vector<int> height;
		int n;
		std::cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int ai;
			std::cin >> ai;
			height.push_back(ai);
		}

		std::cout << MaxArea(height);
	}
}

