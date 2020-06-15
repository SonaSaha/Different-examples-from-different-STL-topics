#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Passenger
{
	std::string name;
	int status;
};
bool compare(const Passenger& p1, const Passenger& p2)
{
		return p1.status < p2.status;
}
int main()
{
	int n;
	std::cin >> n;
	std::string name, status;
	std::vector<Passenger> Passengers(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> Passengers[i].name >> status;
		if (status == "rat")
		{
			Passengers[i].status = 1;
		}
		else if (status == "child" || status == "woman")
		{
			Passengers[i].status = 2;
		}
		else if (status == "man")
		{
			Passengers[i].status = 3;
		}
		else if (status == "captain")
		{
			Passengers[i].status = 4;
		}
	}
	std::stable_sort(Passengers.begin(), Passengers.end(), compare);
	for (auto& p : Passengers)
	{
		std::cout << p.name << "\n";
	}
}