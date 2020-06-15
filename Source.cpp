#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Date
{
	int day;
	int month;
	int year;

};
std::istream& operator>>(std::istream& in, Date& d)
{
	return in >> d.year >> d.month >> d.day;
}
bool operator!=(const Date& d1, const Date& d2)
{
	return d1.year != d2.year || d1.month != d2.month || d1.day != d2.day;
}
bool operator <(const Date& d1, const Date& d2)
{
	return d1.year < d2.year || d1.month < d2.month || d1.day < d2.day;
}
struct Person
{
	std::string name;
	std::string surname;
	Date date;
};
std::istream& operator>>(std::istream& in, Person& p)
{
	return in >> p.name >> p.surname >> p.date;
}
bool is_earlier(const Date& d1, const Date& d2)
{
	if (d1.year != d2.year)
		return d1.year < d2.year;
	else if (d1.month != d2.month)
		return d1.month < d2.month;
	else return d1.day < d2.day;
}
bool compare(const Person & p1, const Person & p2)
{
	if (p1.date != p2.date)
		return p1.date < p2.date;
	if (p1.surname != p2.surname)
		return p1.surname < p2.surname;
	else return p1.name < p2.name;

}
int main()
{
	std::vector<Person> people;
	Person p;
	while (std::cin >> p)
	{
		people.push_back(p);
	}
	std::sort(people.begin(), people.end(), compare);
	for (auto& p : people)
	{
		std::cout << p.name << " " << p.surname << "\n";
	}
}