// ProductDB.cpp
#include "ProductDB.h"
#include <sstream>

ProductDB::ProductDB(int newSize, std::string fname) {
    maxlength = newSize;
    filename = fname;
    data.resize(maxlength);
}

int ProductDB::getSize() const {
    return data.size();
}

int ProductDB::findElement(std::string name) const {
    if (getSize() == 0) {   // empty Database
        return -1;
    }
    else {  // there is at least one element in the Database
        for (int i = 0; i < getSize(); i++) {
            if (data.at(i).getName() == name) { // if ID (Customer, Sales, Manager) or name (Order, Product, Service) are equal
                return i;
            }
        }
    }
    return -1;  // element not found
}

Product ProductDB::get(int index) const {
    if (index < getSize() && index >= 0) {   // valid index
        return data.at(index);
    }
    else {
        throw std::invalid_argument("cannot pass a negative index");
    }
}

bool ProductDB::isEqual(Product first, Product second) {
    if (first.getName() == second.getName()) {
        return true;
    }
    return false;
}

void ProductDB::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << data.at(i).toString() << std::endl;
    }
}

void ProductDB::writeToFile(int mode) {
    std::ofstream dbfile;

    // check if append or open mode
    if (mode == 0) {    // open in append mode
        dbfile.open(filename, std::ios_base::app);  // opens the file in append mode
        Product p = data.back();

        // write Product to file
        dbfile << p.getName() + " ";
        dbfile << p.getType() + " ";
        dbfile << std::to_string(p.getPrice()) + " ";

        dbfile << std::endl;
        dbfile.close();
    }
    else {  // rewrite entire file
        dbfile.open(filename);

        // add each attribute value to file for each Product
        for (Product p : data) {
            dbfile << p.getName() + " ";
            dbfile << p.getType() + " ";
            dbfile << std::to_string(p.getPrice()) + " ";

            dbfile << std::endl;
        }
        dbfile.close();
    }
}

void ProductDB::addToData(Product newElement) {
    // add the element into the list
    data.emplace_back(newElement);
}

void ProductDB::add(Product newElement) {
    // add the element into the list
    addToData(newElement);

    // add the new element into the Database file
    writeToFile(0);
}

bool ProductDB::remove(int remove) {       // not complete yet
    // check if valid index for remove
    if (remove >= getSize() || remove < 0) {
        return false;
    }
    // erase the element
    data.erase(data.begin() + remove);

    // rewrite the Database file
    writeToFile(1);
    return true;
}

void ProductDB::loadFromFile() {
    // open the file
    std::ifstream dbfile(filename);

    // Product attributes
    std::string name;
    std::string type;
    double price;

    // reading the contents of the file
    std::string line;
    while (std::getline(dbfile, line)) {    // read lines until end of the file
        std::stringstream linefile(line);

        // read the contents for Product
        linefile >> name;
        linefile >> type;
        linefile >> price;

        // create the new Product and add to the database
        Product p = Product(name, type, price);
        addToData(p);
    }
    dbfile.close(); // closes the file
}

std::string ProductDB::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data.at(i).toString() + "\n";
    }
    return toString;
}