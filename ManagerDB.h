// ManagerDB.h
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

class ManagerDB {
private:
    Manager* data;
    int maxlength;
    int size;
    std::string filename;
    void resize();
    bool needtoresize();

public:
    ManagerDB(int = 25, std::string = "managers.txt");
    ~ManagerDB();
    int getSize() const;
    int findElement(std::string) const;
    Manager get(int) const;
    bool isEqual(Manager, Manager);

    void print();
    void addToData(Manager);  // adds a new element to the list; only for loading from files
    void add(Manager);    // adds a new element to the list and file
    bool remove(Manager);

    int findUsername(std::string) const;
    int findPassword(std::string) const;

    void loadFromFile(); // load Database from text file
    std::string toString();
};