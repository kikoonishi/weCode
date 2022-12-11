// CustomerDB.h
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

class CustomerDB {
private:
    Customer* data;
    int maxlength;
    int size;
    std::string filename;
    void resize();
    bool needtoresize();

public:
    CustomerDB(int = 25, std::string = "customers.txt");
    ~CustomerDB();
    int getSize() const;
    int findElement(std::string) const;
    Customer get(int) const;
    bool isEqual(Customer, Customer);

    void print();
    void addToData(Customer);  // adds a new element to the list; only for loading from files
    void add(Customer);    // adds a new element to the list and file
    bool remove(Customer);

    int findUsername(std::string) const;
    int findPassword(std::string) const;

    void loadFromFile(); // load Database from text file
    std::string toString();
};