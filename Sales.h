//Author: weCode
//Sales.h

#ifndef SALES_H
#define SALES_H

#include <string>
//include headers
#include "Database.h"
#include "User.h"
#include "Account.h"
#include "Order.h"


class Sales :public User{
    private:
        std::string sales_id;
    public:
        Sales();//default constructor
        Sales(std::string, std::string, std::string);//username, password, sales_id
        
        void setSalesID(std::string);
        std::string getSalesID() const;
        std::string Sales::toString();
        
        template <class T>
        void placeOrder(Database<T>, Order);
        template <class T>
        void deleteOrder(Database<T>, Order); //deleter order by order
        template <class T>
        void deleteOrder(Database<T>, std::string); //delete order by ordername
        template <class T>
        void modifyOrder(Database<T>, Order, Order); //existed Order and new Order
        template <class T>
        void viewOrder(Database<T>); //print database
};

#endif
