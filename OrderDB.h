// OrderDB.h
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "User.h"
#include "Order.h"
#include "Product.h"
#include "Service.h"
#include "Customer.h"

class OrderDB {
private:
    std::vector<Order> data = std::vector<Order>(10);
    int maxlength;
    std::string filename;

public:
    OrderDB(int = 25, std::string = "orders.txt");
    int getSize() const;
    int findElement(std::string) const;
    Order get(int) const;
    bool isEqual(Order, Order);

    void print();
    void writeToFile(int);  // 0 = std::out mode, anything else = std::app mode
    void addToData(Order);  // adds a new element to the list; only for loading from files
    void add(Order);    // adds a new element to the list and file
    bool remove(int);

    void loadFromFile(); // load Database from text file
    std::string toString();
};