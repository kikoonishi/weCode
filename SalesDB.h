// SalesDB.h
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

class SalesDB {
private:
    Sales* data;
    int maxlength;
    int size;
    std::string filename;
    void resize();
    bool needtoresize();

public:
    SalesDB(int = 25, std::string = "sales.txt");
    ~SalesDB();
    int getSize() const;
    int findElement(std::string) const;
    Sales get(int) const;
    bool isEqual(Sales, Sales);

    void print();
    void addToData(Sales);  // adds a new element to the list; only for loading from files
    void add(Sales);    // adds a new element to the list and file
    bool remove(Sales);

    int findUsername(std::string) const;
    int findPassword(std::string) const;

    void loadFromFile(); // load Database from text file
    std::string toString();
};