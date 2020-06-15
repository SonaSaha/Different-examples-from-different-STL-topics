#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

struct DateTime
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
};
std::istream& operator>>(std::istream& in,DateTime& dateTime)
{
	in >> dateTime.year >> dateTime.month >> dateTime.day >> dateTime.hour >> dateTime.minute;
	return in;
}
void verifyDateTime(const DateTime& dateTime)
{
	if (dateTime.month < 1 || dateTime.month>12 || dateTime.day < 1 || dateTime.day>31 || dateTime.hour < 0 || dateTime.hour>24 || dateTime.minute < 0 || dateTime.minute>60)
		throw std::invalid_argument("incorrect date or time");
}
std::ostream& operator<<(std::ostream& out, const DateTime& dateTime)
{
	verifyDateTime(dateTime);
	out << dateTime.year << '/';
	if (dateTime.month < 10)
		out << '0';
	out << dateTime.month << '/' << dateTime.day << " ";
	if (dateTime.hour < 10)
		out << '0';
	out << dateTime.hour << ':' << dateTime.minute;
	return out;
}
struct Flight
{
	std::string number;
	std::string departureSity;
	std::string sityOfArrival;
	std::string aircraftModel;
	int passCount;
	DateTime dateTime;
};
std::istream& operator>>(std::istream& in, Flight& flight)
{
	std::cin >> flight.number >> flight.departureSity >> flight.sityOfArrival >> flight.aircraftModel >> flight.passCount >> flight.dateTime;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Flight& flight)
{
	out << flight.number << "\n" << flight.departureSity << " " << flight.sityOfArrival << "\n" << flight.aircraftModel << "\n" << flight.passCount << " " << "passengers" << "\n" << flight.dateTime << "\n\n";
	return out;
}
int main()
{
	time_t time;
	std::time(&time);
	struct tm * timeinfo;
	timeinfo = localtime(&time);
	char buffer[80];
    strftime(buffer, 80, "%Y/%m/%d %R", timeinfo);
    puts(buffer);
	int flightCount = 4;
	//std::cin >> flightCount;
	std::cout << flightCount << "\n\n";
	std::vector<Flight> Flights(flightCount);
	//std::copy_n(std::istream_iterator<Flight>(std::cin), flightCount, Flights.begin());
	Flights[0] = { "AF-711","Yerevan","Paris","Boeing-777",155,{2020,4,10,18,54} };
	Flights[1] = { "AE-012","Yerevan","London","Airbus-A320",110,{2020,4,15,15,54} };
	Flights[2] = { "AE-501","Uagadugu","Kinshasa","Fokker-45",58,{2021,3,27,19,54} };
	Flights[3] = { "FG-151","Paris","Berlin","Boeing-747",405,{2020,4,10,20,54} };
	std::cout << "****4.1****\n";
	std::copy_n(Flights.begin(), flightCount, std::ostream_iterator<Flight>(std::cout));
    //4.2
	std::cout << "****4.2****\n";
	std::vector<Flight> todayFlights;
	std::copy_if(Flights.begin(), Flights.end(), std::back_inserter(todayFlights), [&](const Flight& flight)
	{
		return ((flight.dateTime.day == timeinfo->tm_mday) && ((flight.dateTime.hour > timeinfo->tm_hour) || ((flight.dateTime.hour == timeinfo->tm_hour) && (flight.dateTime.minute > timeinfo->tm_min))));
	});
	for (size_t i = 0; i < todayFlights.size(); ++i)
	{
		std::cout << todayFlights[i].number << "\n";
	}
	//4.3
	std::cout << "\n****4.3****\n";
	std::vector<Flight> f;
	Flights.erase(std::remove_copy_if(Flights.begin(), Flights.end(), Flights.begin(), [](const Flight& flight)
	{
		std::string boeing = "Boeing";
		return std::search(flight.aircraftModel.begin(), flight.aircraftModel.end(),boeing.begin(),boeing.end()) != flight.aircraftModel.end();
	}),Flights.end());
	std::copy_n(Flights.begin(), Flights.size(), std::ostream_iterator<Flight>(std::cout));
	//4.4
	std::cout << "****4.4****\n";
	auto it = std::min_element(Flights.begin(), Flights.end(), [](const Flight& f1, const Flight& f2)
	{
		return f1.passCount < f2.passCount;
	});
	std::cout << it->departureSity << " " << it->sityOfArrival << "\n";
}