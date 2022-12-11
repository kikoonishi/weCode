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
	setProduct(p);
	service = Service();
	orderName = name;
	setCustomer(c);
}

Order::Order(Service s, std::string name, Customer c)
{
	product = Product();
	setService(s);
	orderName = name;
	setCustomer(c);
}

Order::Order(Product p, Service s, std::string name, Customer c)
{
	setProduct(p);
	setService(s);
	orderName = name;
	setCustomer(c);
}

Product Order::getProduct() const
{
	return product;
}

Service Order::getService() const
{
	return service;
}

std::string Order::getOrderName() const
{
	return orderName;
}

Customer Order::getCustomer() const {
	return customer;
}

void Order::setProduct(Product p)
{
	product.copy(p);
}

void Order::setService(Service s)
{
	service.copy(s);
}

void Order::setOrderName(std::string name)
{
	orderName = name;
}

void Order::setCustomer(Customer c)
{
	customer.copy(c);
}

std::string Order::toString()
{
	std::string output = orderName + "-" + product.getName(); +"-" + service.getName();
	return output;
}

void Order::copy(Order toCopy)
{
	this->orderName = toCopy.getOrderName();
	this->product.copy(toCopy.getProduct());
	this->service.copy(toCopy.getService());
	this->customer.copy(toCopy.getCustomer());
}

