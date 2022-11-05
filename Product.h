#pragma once
#include <string>
#include <iostream>

class Product
{
	private:
		std::string productName;
		double price;
	
	public:
		Product();
		Product(std::string name, double cost);
		std::string getName();
		double getPrice();
		void setName(std::string name);
		void setPrice(double cost);
};
