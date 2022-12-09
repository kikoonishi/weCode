#include <string>
#include <iostream>
#include "Service.h"

Service::Service()
{
	serviceName = "";
	type = "";
	hourlyRate = 0;
	hours = 0;
}

Service::Service(std::string name, std::string t, double rate, int time)
{
	serviceName = name;
	type = t;
	hourlyRate = rate;
	hours = time;
}

std::string Service:: getName()
{
	return serviceName;
}

double Service:: getRate()
{
	return hourlyRate;
}

double Service:: getHours()
{
	return hours;
}

double Service:: getPrice()
{
	return (hourlyRate * hours);
}

void Service:: setName(std::string name)
{
	serviceName = name;
}

void Service:: setRate(double rate)
{
	hourlyRate = rate;
}

void Service:: setHours(int time)
{
	hours = time;
}

void Service:: setType(std::string t)
{
	type = t;
}

std::string Service:: toString()
{
	std::string output = serviceName + "/n" + "$" + std::to_string(hourlyRate) + " per hour";
	return output;
	

}

Service Service:: copy()
{
	Service copy = Service(serviceName,type, hourlyRate, hours);
	return copy;
}
