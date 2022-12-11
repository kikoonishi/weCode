//Author: weCode
//Manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"
#include "Order.h"
#include "Product.h"
#include "Service.h"
#include "Database.h"

//template <class T>
class Manager :public User {
private:
    std::string manager_id;

public:
    Manager(); // default constructor
    Manager(std::string, std::string, Account, std::string);//Manager fields + username, password

    void setManagerID(std::string);
    std::string getManagerID() const;
    std::string toString();

    //add,delete,edit product/service in database
    void addProduct(Database<Product>, Product);
    void addService(Database<Service>, Service);
    void deleteProduct(Database<Product>, Product);//delete product by Product
    void deleteService(Database<Service>, Service);//delete product by Service
    void modifyProduct(Database<Product>, Product, Product);//existring Product to new Product
    void modifyService(Database<Service>, Service, Service);//existring Service to new Service
    void viewProduct(Database<Product>);//view database
    void viewService(Database<Service>);

    //Order
    void placeOrder(Database<Order>, Order);
    void deleteOrder(Database<Order>, Order); //deleter order by order
    void deleteOrder(Database<Order>, std::string); //delete order by ordername
    void modifyOrder(Database<Order>, Order, Order); //existed Order and new Order
    void viewOrder(Database<Order>); //print database
};

#endif
