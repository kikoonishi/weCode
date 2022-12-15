//Author weCode
//Sales.cpp

#include "Sales.h" // include definition of class Sales from Sales.h


Sales::Sales() : User() {
    //Sales field
    setSalesID("1");
}

Sales::Sales(std::string username, std::string password, Account user_account, std::string new_sales_id) : User(username, password, user_account) {
    setSalesID(new_sales_id);
}

void Sales::setSalesID(std::string new_sales_id) {
    sales_id = new_sales_id;
}

std::string Sales::getSalesID() const { return sales_id; }

//return fields as string
std::string Sales::toString() {
    std::string toString = "";
    toString += "Manager ID: " + sales_id;
    return toString;
}