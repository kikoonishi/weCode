//Author: weCode
//Manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "User.h"
#include "Account.h"
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
        Manager(std::string, std::string, std::string);//Manager fields + username, password

        void setManagerID(std::string);
        std::string getManagerID();

        //add,delete,edit product/service in database
        template <class T>
        void addProduct(Database<T>, Product);
        template <class T>        
        void addService(Database<T>, Service);
        template <class T>
        void deleteProduct(Database<T>, Product);//delete product by Product
        template <class T>
        void deleteService(Database<T>, Service);//delete product by Service
        template <class T>
        void modifyProduct(Database<T>, Product, Product);//existring Product to new Product
        template <class T>
        void modifyService(Database<T>, Service, Service);//existring Service to new Service


        //Order
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
