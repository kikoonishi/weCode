// OrderDB.h
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

class OrderDB {
private:
    Order* data;
    int maxlength;
    int size;
    std::string filename;
    void resize();
    bool needtoresize();

public:
    OrderDB(int = 25, std::string = "orders.txt");
    ~OrderDB();
    int getSize() const;
    int findElement(std::string) const;
    Order get(int) const;
    bool isEqual(Order, Order);

    void print();
    void addToData(Order);  // adds a new element to the list; only for loading from files
    void add(Order);    // adds a new element to the list and file
    bool remove(Order);

    void loadFromFile(); // load Database from text file
    std::string toString();
};