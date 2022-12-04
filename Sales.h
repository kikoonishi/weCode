//Author: weCode
//Sales.h

#include <string>
//include headers
#include "Customer.h"
#include "Order.h"
#include "Database.h"

template <class T>
class Sales :public Customer{
    public:
        Sales();
        Sales():Customer();//default constructor
        Sales(std::string, std::string, Account):Customer(std::string, std::string, Account);//newID, type, userAccount
        
        
        void placeOrder(Database<T>, Order);
        void deleteOrder(Database<T>, Order); //deleter order by order
        void deleteOrder(Database<T>, std::string); //delete order by ordername
        void deleteOrder(Database<T>, Customer); //delete order by Customer
        void modifyOrder(Database<T>, Order, Order); //existed Order and new Order
        void viewOrder(Database<T>); //print database
        std::string toString(Database<T>); //get database as string
};
