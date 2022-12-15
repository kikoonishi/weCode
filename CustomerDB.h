// CustomerDB.h
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "User.h"
#include "Customer.h"

class CustomerDB {
private:
    std::vector<Customer> data = std::vector<Customer>(10);
    int maxlength;
    std::string filename;

public:
    CustomerDB(int maxlength = 25, std::string = "customers.txt");
    int getSize() const;
    int findElement(std::string) const;
    Customer get(int) const;
    bool isEqual(Customer, Customer);

    void print();
    void writeToFile(int);  // 0 = std::out mode, anything else = std::app mode
    void addToData(Customer);  // adds a new element to the list; only for loading from files
    void add(Customer);    // adds a new element to the list and file
    bool remove(int);

    int findUsername(std::string) const;
    int findPassword(std::string) const;

    void loadFromFile(); // load Database from text file
    std::string toString();
};