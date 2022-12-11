// ServiceDB.h
#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "User.h"
#include "Order.h"
#include "Product.h"
#include "Service.h"
#include "Customer.h"
#include "Sales.h"
#include "Manager.h"

class ServiceDB {
private:
    Service* data;
    int maxlength;
    int size;
    std::string filename;
    void resize();
    bool needtoresize();

public:
    ServiceDB(int = 25, std::string = "services.txt");
    ~ServiceDB();
    int getSize() const;
    int findElement(std::string) const;
    Service get(int) const;
    bool isEqual(Service, Service);

    void print();
    void addToData(Service);  // adds a new element to the list; only for loading from files
    void add(Service);    // adds a new element to the list and file
    bool remove(Service);

    void loadFromFile(); // load Database from text file
    std::string toString();
};