#pragma once
#include <string>
#include <iostream>

class Service {
private:
	std::string serviceName;
	double hourlyRate;
	int hours;

public:
	Service();
	Service(std::string name, double hourlyRate,int hours);
	std::string getName();
	double getRate();
	double getHours();
	double getPrice();
	void setName(std::string name);
	void setRate(double cost);
	void setHours(int time);
	std::string toString();
	Service copy();

};
