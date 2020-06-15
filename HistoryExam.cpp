#include "pch.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> dates_of_professor(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> dates_of_professor[i];
	}
	int ans = 0;
	int M;
	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int num;
		std::cin >> num;
		if (std::binary_search(dates_of_professor.cbegin(), dates_of_professor.cend(), num))
			++ans;
	}
	
	std::cout << ans;
	
}