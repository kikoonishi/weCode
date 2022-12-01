//Author: weCode
//Sales.h

#include <string>
#include "Customer.h"
#include "Order.h"
#include "Database.h"//need to be fixed

template <class T>
class Sales :public Customer{
    protected:
        static Database<T> orderData;
        Order order;//will be deleted?

    public:
        Sales():Customer();//default constructor
        Sales(std::string):Customer(std::string);//
        
        
        void placeOrder(std::string, std::string, int);//get product/service name, customer name, quantity as a parameter and add to database
        void placeOrder(std::string);
        void deleteOrder(std::string); //deleter order
        void modifyOrder(std::string, int); //modify 
        void modifyOrder(std::string, std::string);
        void viewOrder(std::string); //serch order by ordername
        void viewOrder(); //view all order in DB
        void toString();
        void deleteOrder(std::string);
};
