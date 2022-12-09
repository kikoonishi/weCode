#pragma once
#include <string>
#include <iostream>

class Product
{
	private:
		std::string productName;
		std::string type;
		double price;
	
	public:
		Product();
		Product(std::string name, std::string type, double cost);
		std::string getName();
		double getPrice();
		void setName(std::string name);
		void setPrice(double cost);
		void setType(std::string type);
		std::string toString();
		Product copy();
};
