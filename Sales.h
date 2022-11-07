//Author: weCode
//Sales.h

#include <iostream>
#include <string>
#include<Customer.h>
#include <Order.h>

class Sales :private Customer{
    private:
        Order order; //order: product, service, ordername

    public:
        Sales(); //default constructor
        Sales(Order);//constructor

        //setter
        void setOrder(Order);

        //getter
        Order getOrder();      
};