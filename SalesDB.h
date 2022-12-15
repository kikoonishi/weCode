// SalesDB.h
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "User.h"
#include "Sales.h"

class SalesDB {
private:
    std::vector<Sales> data = std::vector<Sales>(10);
    int maxlength;
    std::string filename;

public:
    SalesDB(int = 25, std::string = "sales.txt");
    int getSize() const;
    int findElement(std::string) const;
    Sales get(int) const;
    bool isEqual(Sales, Sales);

    void print();
    void writeToFile(int);  // 0 = std::out mode, anything else = std::app mode
    void addToData(Sales);  // adds a new element to the list; only for loading from files
    void add(Sales);    // adds a new element to the list and file
    bool remove(int);

    int findUsername(std::string) const;
    int findPassword(std::string) const;

    void loadFromFile(); // load Database from text file
    std::string toString();
};