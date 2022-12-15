// ManagerDB.h
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "User.h"
#include "Manager.h"

class ManagerDB {
private:
    std::vector<Manager> data = std::vector<Manager>(10);
    int maxlength;
    std::string filename;

public:
    ManagerDB(int = 25, std::string = "managers.txt");
    int getSize() const;
    int findElement(std::string) const;
    Manager get(int) const;
    bool isEqual(Manager, Manager);

    void print();
    void writeToFile(int);  // 0 = std::out mode, anything else = std::app mode
    void addToData(Manager);  // adds a new element to the list; only for loading from files
    void add(Manager);    // adds a new element to the list and file
    bool remove(int);

    int findUsername(std::string) const;
    int findPassword(std::string) const;

    void loadFromFile(); // load Database from text file
    std::string toString();
};