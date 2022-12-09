#include <string>
#include <iostream>
#include "Product.h"

Product::Product()
{
	productName = "";
	type = "";
	price = 0;
}

Product::Product(std::string name, std::string t, double cost)
{
	productName = name;
	type = t;
	price = cost;
}

std::string Product::getName()
{
	return productName;
}

double Product::getPrice()
{
	return price;
}

void Product::setName(std::string name)
{
	productName = name;
}

void Product::setPrice(double cost)
{
	price = cost;
}

void Product::SetType(std::string t)
{
	type = t;	
}

std::string Product::toString()
{
	std::string output = productName + "/n" + "$" + std::to_string(price);
	return output;
}

Product Product::copy()
{
	Product copy = Product(productName,type, price);
	return copy;
}
