// ProductDB.h
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

class ProductDB {
private:
    Product* data;
    int maxlength;
    int size;
    std::string filename;
    void resize();
    bool needtoresize();

public:
    ProductDB(int = 25, std::string = "products.txt");
    ~ProductDB();
    int getSize() const;
    int findElement(std::string) const;
    Product get(int) const;
    bool isEqual(Product, Product);

    void print();
    void addToData(Product);  // adds a new element to the list; only for loading from files
    void add(Product);    // adds a new element to the list and file
    bool remove(Product);

    void loadFromFile(); // load Database from text file
    std::string toString();
};
