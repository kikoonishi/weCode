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
	Service(std::string name, std::string type, double rate, int time);
	std::string getName() const;
	double getRate() const;
	double getHours() const;
	double getPrice() const;
	std::string getType() const;
	void setName(std::string name);
	void setRate(double rate);
	void setHours(int time);
	void setType(std::string type);
	std::string toString();
	void copy(Service);

};
