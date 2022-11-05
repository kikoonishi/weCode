#pragma once
#include <string>
#include <iostream>
#include "Product.h"
#include "Service.h"

class Order
{
	private:
		Product product;// order contains a product or service
		Service service;// can use this to make a package deal???? Or maybe create an arraylist 
		std::string orderName;// Might want to have a customer be attatched to the order

	public:
		Order();
		Order(Product p);
		Order(Service s);
		Product getProduct();
		Service getService();
		std::string getOrderName();
		void setProduct(Product p);
		void setService(Service s);
		void setOrderName(std::string Name);

		void sampleFunt();//delete later


};