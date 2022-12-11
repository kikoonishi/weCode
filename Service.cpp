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

std::string Service::getName() const
{
	return serviceName;
}

double Service::getRate() const
{
	return hourlyRate;
}

double Service::getHours() const
{
	return hours;
}

double Service::getPrice() const
{
	return (hourlyRate * hours);
}

void Service::setName(std::string name)
{
	serviceName = name;
}

void Service::setRate(double rate)
{
	hourlyRate = rate;
}

void Service::setHours(int time)
{
	hours = time;
}

void Service::setType(std::string t)
{
	type = t;
}

std::string Service::toString()
{
	std::string output = serviceName + "/n" + "$" + std::to_string(hourlyRate) + " per hour";
	return output;


}

void Service::copy(Service toCopy)
{
	this->serviceName = toCopy.getName();
	this->type = toCopy.getType();
	this->hourlyRate = toCopy.getRate();
	this->hours = toCopy.getHours();
}
