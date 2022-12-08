#include <string>
#include <iostream>
#include "Product.h"
#include "Service.h"
#include "Order.h"
#include "Customer.h"


Order::Order()
{
	product = Product();
	service = Service();
	customer = Customer();
	orderName = "";
}

Order::Order(Product p, std::string name, Customer c)
{
	product = p;
	service = Service();
	orderName = name;
}

Order::Order(Service s, std::string name, Customer c)
{
	product = Product();
	service = s;
	orderName = name;
}

Order:: Order(Product p, Service s, std::string name, Customer c)
{
	product = p;
	service = s;
	orderName = name;
}

Product Order::getProduct()
{
	return product;
}

Service Order::getService()
{
	return service;
}

std::string Order::getOrderName()
{
	return orderName;
}

void Order::setProduct(Product p)
{
	product = p;
}

void Order::setService(Service s)
{
	service = s;
}

void Order::setOrderName(std::string name)
{
	orderName = name;
}

std::string Order:: toString()
{
	std::string output = orderName + "-" + product.getName(); + "-"+ service.getName();
	return output;
}

Order Order:: copy()
{
	Order copy = Order(product, service, orderName);
	return copy;
}


