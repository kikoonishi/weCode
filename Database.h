// Author: weCode
// Database.h
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

template <typename T>
class Database {
private:
    T* data;
    int maxlength;
    int size;
    std::string filename;
    void resize();
    bool needtoresize();

public:
    Database(int = 25, std::string = "database.txt");
    int getSize() const;
    int findElement(T) const;
    T get(int) const;
    bool isEqual(T, T);

    void print();
    void add(T);
    void remove(T);
    void loadFromFile(std::string); // load Database from text file
    void loadUserDB();
    void loadOrderDB();
    void loadProductDB();
    void loadServiceDB();
    std::string toString() const;
};
