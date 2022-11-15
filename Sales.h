//Author: weCode
//Sales.h

#include <iostream>
#include <string>
#include "Customer.h"
#include "Order.h"
#include "Database.h"

template <class T>
class Sales :public Customer{
    private:
        static Database<T> data;
        Order order;

    public:
        Sales():Customer();//default constructor
        
        void placeOrder(std::string, std::string, int);//get product/service name, customer name, quantity as a parameter and add to database
        void deleteOrder(Order); //deleter order
        void modifyOrder(Order); //modify 
        void viewOrder(Order); //serch order by ordername
        void viewOrder(); //view all order in DB
        void toString();
};
