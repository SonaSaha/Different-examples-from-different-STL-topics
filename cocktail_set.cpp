#include "pch.h"
#include <iostream>
#include <string>
#include <set>
#include <sstream>

int main()
{
	int N;
	std::cin >> N;
	std::set<std::string> s;
	for (int i = 0; i < N; ++i)
	{
		std::string drink;
		std::cin >> drink;
		s.insert(drink);
	}
	int M;
	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		std::string events;
		std::cout << M;
		std::getline(std::cin, events);
		std::cout << M;
		std::cout << events;
		std::istringstream check_event(events);
		check_event >> std::noskipws;
		std::string cur_event;
		check_event >> cur_event;
		char a;
		std::string drink_name;
		check_event >> a;
		if (cur_event == "RunOut")
		{
			check_event >> drink_name;
			s.erase(drink_name);
		}
		else if (cur_event == "Delivered")
		{
			check_event >> drink_name;
			s.insert(drink_name);
		}
		else if (cur_event == "CocktailRequest")
		{
			int number_of_ingredients;
			check_event >> number_of_ingredients;
			check_event >> a;
			for (int i = 0; i < number_of_ingredients; ++i)
			{
				std::string cur_ingredient;
				check_event >> cur_ingredient;
				if (s.find(cur_ingredient) == s.end())
				{
					std::cout << "Cocktail cannot be made";
					break;
				}
				check_event >> a;
				std::cout << "Cocktail can be made";
			}
		}
		else
		{
			throw std::invalid_argument("worng input");
		}

	}

}