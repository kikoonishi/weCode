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
    ~Database();
    int getSize() const;
    int findElement(T) const;
    T get(int) const;
    bool isEqual(T, T);

    void print();
    void addToData(T);  // adds a new element to the list; only for loading from files
    void add(T);    // adds a new element to the list and file
    bool remove(T);

    void loadFromFile(std::string); // load Database from text file
    void loadUserDB(std::ifstream);     // loads Database<User>
    void loadOrderDB(std::ifstream);    // loads Database<Order>
    void loadProductDB(std::ifstream);  // loads Database<Product>
    void loadServiceDB(std::ifstream);  // loads Database<Service>
    std::string toString();
};
