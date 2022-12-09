#pragma once
#include <string>
#include <iostream>
#include "Product.h"
#include "Service.h"
#include "Customer.h"


class Order
{
	private:
		Product product;// order contains a product or service
		Service service;// can use this to make a package deal???? Or maybe create an arraylist 
		std::string orderName;// Might want to have a customer be attatched to the order
		Customer customer;

	public:
		Order();
		Order(Product p, std::string name, Customer c);
		Order(Service s, std::string name, Customer c);
		Order(Product p, Service s, std::string name, Customer c);
		Product getProduct();
		Service getService();
		std::string getOrderName();
		void setProduct(Product p);
		void setService(Service s);
		void setOrderName(std::string name);
		void setCustomer(customer);
		std::string toString();
		Order copy();




};
