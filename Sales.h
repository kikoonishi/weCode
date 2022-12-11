//Author: weCode
//Sales.h

#ifndef SALES_H
#define SALES_H

//#include "OrderDB.h"
#include "User.h"
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
};

#endif
