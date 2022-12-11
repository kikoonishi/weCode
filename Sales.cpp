//Author weCode
//Sales.cpp


#include <iostream>
#include <string>
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

void Sales::placeOrder(Database<Order> database, Order order) {
    //add order to database (ordername, product/service, quantity)
    database.add(order);
}

//return fields as string
std::string Sales::toString() {
    std::string toString = "";
    toString += "Manager ID: " + sales_id;
    return toString;
}

void Sales::deleteOrder(Database<Order> database, Order order) {
    //delete order from database
    database.remove(order);
}

void Sales::modifyOrder(Database<Order> database, Order existingOrder, Order newOrder) {
    //delete existing order
    database.remove(existingOrder);
    //add new order
    database.add(newOrder);

}

void Sales::viewOrder(Database<Order> database) {
    //get database as string and print
    database.print();
}
