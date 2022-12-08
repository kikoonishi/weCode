//Author: weCode
//Manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "Sales.h"
#include "Product.h"
#include "Service.h"
#include "Database.h"

template <class T>
class Manager :public Sales {
    public:
        //default constructor?????
        Manager();
        Manager(): Sales();
        Manager(std::string, std::string, Account) : Sales(std::string, std::string, Account);//newID, type, userAccount

        //add,delete,edit product/service in database
        void addProduct(Database<T>, Product);        
        void addService(Database<T>, Service);
        void deleteProduct(Database<T>, Product);//delete product by Product
        void deleteService(Database<T>, Service);//delete product by Service
        void modifyProduct(Database<T>, Product, Product);//existring Product to new Product
        void modifyService(Database<T>, Service, Service);//existring Service to new Service

};

#endif
