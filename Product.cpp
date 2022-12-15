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

std::string Product::getName() const
{
	return productName;
}

double Product::getPrice() const
{
	return price;
}

std::string Product::getType() const {
	return type;
}

void Product::setName(std::string name)
{
	productName = name;
}

void Product::setPrice(double cost)
{
	price = cost;
}

void Product::setType(std::string t)	// fixed; Logan had SetType
{
	type = t;
}

std::string Product::toString()
{
	std::string output = productName + "/n" + "$" + std::to_string(price);
	return output;
}

void Product::copy(Product toCopy)
{
	this->productName = toCopy.getName();
	this->type = toCopy.getType();
	this->price = toCopy.getPrice();
}