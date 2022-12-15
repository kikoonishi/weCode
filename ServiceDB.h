// ServiceDB.h
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Service.h"

class ServiceDB {
private:
    std::vector<Service> data = std::vector<Service>(10);
    int maxlength;
    std::string filename;

public:
    ServiceDB(int = 25, std::string = "services.txt");
    int getSize() const;
    int findElement(std::string) const;
    Service get(int) const;
    bool isEqual(Service, Service);

    void print();
    void writeToFile(int);  // 0 = std::out mode, anything else = std::app mode
    void addToData(Service);  // adds a new element to the list; only for loading from files
    void add(Service);    // adds a new element to the list and file
    bool remove(int);

    void loadFromFile(); // load Database from text file
    std::string toString();
};