//Author: weCode
//Sales.h

#include <iostream>
#include <string>
#include<Customer.h>
#include <Order.h>

class Sales :private Customer{
    public:
        using Customer::Customer; //inherits constructor

        void placeOrder(std::string, std::string, int);//add order to database (ordername, product/service, quantity)
        void deleteOrder(std::string); //deleter order by ordername
        void modifyOrder(std::string, int); //modify by ordername and quantity
        void modifyOrder(std::string, std::string); ////modify by ordername and productname
        void viewOrder(std::string); //serch order by ordername

};