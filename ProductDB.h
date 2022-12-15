// ProductDB.h
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Product.h"

class ProductDB {
private:
    std::vector<Product> data = std::vector<Product>(10);
    int maxlength;
    std::string filename;

public:
    ProductDB(int = 25, std::string = "products.txt");
    int getSize() const;
    int findElement(std::string) const;
    Product get(int) const;
    bool isEqual(Product, Product);

    void print();
    void writeToFile(int);  // 0 = std::out mode, anything else = std::app mode
    void addToData(Product);  // adds a new element to the list; only for loading from files
    void add(Product);    // adds a new element to the list and file
    bool remove(int);

    void loadFromFile(); // load Database from text file
    std::string toString();
};