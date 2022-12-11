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


class Sales :public User {
private:
    std::string sales_id;
public:
    Sales();//default constructor
    Sales(std::string, std::string, Account, std::string);//username, password, sales_id

    void setSalesID(std::string);
    std::string getSalesID() const;
    std::string toString();

    void placeOrder(Database<Order>, Order);
    void deleteOrder(Database<Order>, Order); //deleter order by order
    void deleteOrder(Database<Order>, std::string); //delete order by ordername
    void modifyOrder(Database<Order>, Order, Order); //existed Order and new Order
    void viewOrder(Database<Order>); //print database
};

#endif
