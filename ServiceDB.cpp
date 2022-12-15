// ServiceDB.cpp
#include "ServiceDB.h"
#include <sstream>

ServiceDB::ServiceDB(int newSize, std::string fname) {
    maxlength = newSize;
    filename = fname;
    data.resize(maxlength);
}

int ServiceDB::getSize() const {
    return data.size();
}

int ServiceDB::findElement(std::string name) const {
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

Service ServiceDB::get(int index) const {
    if (index < getSize() && index >= 0) {   // valid index
        return data.at(index);
    }
    else {
        throw std::invalid_argument("cannot pass a negative index");
    }
}

bool ServiceDB::isEqual(Service first, Service second) {
    if (first.getName() == second.getName()) {
        return true;
    }
    return false;
}

void ServiceDB::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << data.at(i).toString() << std::endl;
    }
}

void ServiceDB::writeToFile(int mode) {
    std::ofstream dbfile;

    // check if append or open mode
    if (mode == 0) {    // open in append mode
        dbfile.open(filename, std::ios_base::app);  // opens the file in append mode
        Service s = data.back();

        // write Product to file
        dbfile << s.getName() + " ";
        dbfile << s.getType() + " ";
        dbfile << std::to_string(s.getRate()) + " ";
        dbfile << std::to_string(s.getHours()) + " ";

        dbfile << std::endl;
        dbfile.close();
    }
    else {  // rewrite entire file
        dbfile.open(filename);

        // add each attribute value to file for each Product
        for (Service s : data) {
            dbfile << s.getName() + " ";
            dbfile << s.getType() + " ";
            dbfile << std::to_string(s.getRate()) + " ";
            dbfile << std::to_string(s.getHours()) + " ";

            dbfile << std::endl;
        }
        dbfile.close();
    }
}

void ServiceDB::addToData(Service newElement) {
    // add the element into the list
    data.emplace_back(newElement);
}

void ServiceDB::add(Service newElement) {
    // add the element into the list
    addToData(newElement);

    // add the new element into the Database file
    writeToFile(0);
}

bool ServiceDB::remove(int remove) {       // not complete yet
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

void ServiceDB::loadFromFile() {
    // open the file
    std::ifstream dbfile(filename);

    // Service attributes
    std::string name;
    std::string type;
    double rate;
    double hours;

    Service s;  // the new Service to be added

    // reading the contents of the file
    std::string line;
    while (std::getline(dbfile, line)) {    // read lines until end of the file
        std::stringstream linefile(line);

        // read the contents for Service
        linefile >> name;
        linefile >> type;
        linefile >> rate;
        linefile >> hours;

        // create the new Service and add to the database
        s = Service(name, type, rate, hours);
        addToData(s);
    }
    dbfile.close(); // closes the file
}

std::string ServiceDB::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data.at(i).toString() + "\n";
    }
    return toString;
}