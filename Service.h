#pragma once
#include <string>
#include <iostream>

class Service {
private:
	std::string serviceName;
	std::string type;
	double hourlyRate;
	int hours;

public:
	Service();
	Service(std::string name, std::string type, double rate,int time);
	std::string getName();
	double getRate();
	double getHours();
	double getPrice();
	void setName(std::string name);
	void setRate(double rate);
	void setHours(int time);
	void setType(std::string type);
	std::string toString();
	Service copy();

};
