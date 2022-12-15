// SalesDB.cpp
#include "SalesDB.h"
#include <sstream>

SalesDB::SalesDB(int newSize, std::string fname) {
    maxlength = newSize;
    filename = fname;
    data.resize(maxlength);
}

int SalesDB::getSize() const {
    return data.size();
}

int SalesDB::findElement(std::string id) const {
    if (getSize() == 0) {   // empty Database
        return -1;
    }
    else {  // there is at least one element in the Database
        for (int i = 0; i < getSize(); i++) {
            if (data.at(i).getSalesID() == id) { // if ID (Customer, Sales, Manager) or name (Order, Product, Service) are equal
                return i;
            }
        }
    }
    return -1;  // element not found
}

Sales SalesDB::get(int index) const {
    if (index < getSize() && index >= 0) {   // valid index
        return data.at(index);
    }
    else {
        throw std::invalid_argument("cannot pass a negative index");
    }
}

bool SalesDB::isEqual(Sales first, Sales second) {
    if (first.getSalesID() == second.getSalesID()) {
        return true;
    }
    return false;
}

void SalesDB::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << data.at(i).toString() << std::endl;
    }
}

void SalesDB::writeToFile(int mode) {
    std::ofstream dbfile;

    // check if append or open mode
    if (mode == 0) {    // open in append mode
        dbfile.open(filename, std::ios_base::app);  // opens the file in append mode
        Sales s = data.back();

        // add each attribute value to file for the one Sales
        dbfile << s.getSalesID() + " ";   // writes ID value to file

        dbfile << s.getUsername() + " "; // writes Customer username to file
        dbfile << s.getPassword() + " "; // writes Customer password to file

        dbfile << s.getAccount().getName() + " ";    // writes Customer Account name to file
        dbfile << s.getAccount().getAddress1().toString() + " "; // writes Account Address 1 to file
        dbfile << s.getAccount().getAddress2().toString() + " "; // writes Account Address 2 to file
        dbfile << s.getAccount().getPhoneNumber().getPhoneNumber() + " ";    // writes Account Phone Number to file

        dbfile << std::endl;
        dbfile.close();
    }
    else {  // rewrite entire file
        dbfile.open(filename);

        // add each attribute value to file for each Sales
        for (Sales s : data) {
            dbfile << s.getSalesID() + " ";   // writes ID value to file

            dbfile << s.getUsername() + " "; // writes Customer username to file
            dbfile << s.getPassword() + " "; // writes Customer password to file

            dbfile << s.getAccount().getName() + " ";    // writes Customer Account name to file
            dbfile << s.getAccount().getAddress1().toString() + " "; // writes Account Address 1 to file
            dbfile << s.getAccount().getAddress2().toString() + " "; // writes Account Address 2 to file
            dbfile << s.getAccount().getPhoneNumber().getPhoneNumber() + " ";    // writes Account Phone Number to file

            dbfile << std::endl;
        }
        dbfile.close();
    }
}

void SalesDB::addToData(Sales newElement) {
    // add the element into the list
    data.emplace_back(newElement);
}

void SalesDB::add(Sales newElement) {
    // add the element into the list
    addToData(newElement);

    // add the new element into the Database file
    writeToFile(0);
}

bool SalesDB::remove(int remove) {     
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

int SalesDB::findUsername(std::string username) const {
    if (getSize() == 0) {   // empty Database
        return -1;
    }
    else {  // there is at least one element in the Database
        for (int i = 0; i < getSize(); i++) {
            if (data.at(i).getUsername() == username) { // if usernames are equal
                return i;
            }
        }
    }
    return -1;  // element not found
}

int SalesDB::findPassword(std::string password) const {
    if (getSize() == 0) {   // empty Database
        return -1;
    }
    else {  // there is at least one element in the Database
        for (int i = 0; i < getSize(); i++) {
            if (data.at(i).getPassword() == password) { // if passwords are equal
                return i;
            }
        }
    }
    return -1;  // element not found
}

void SalesDB::loadFromFile() {
    // open the file
    std::ifstream dbfile(filename);

    // User attributes
    std::string username;
    std::string password;
    std::string accountName; // for user_account
    // for Address 1 in user_account
    std::string sa1number;
    std::string sa1name;
    std::string sa1label;
    std::string city1;
    std::string state1;
    std::string areaCode1;
    std::string country1;
    // for Address 2 in user_account
    std::string sa2number;
    std::string sa2name;
    std::string sa2label;
    std::string city2;
    std::string state2;
    std::string areaCode2;
    std::string country2;

    std::string phoneNumber; // for Phone in user_account

    // check 1st char to see if Customer, Sales, or Manager ID
        // e.g. c1234 = customer_id
        // e.g. s5678 = sales_id
        // e.g. m9010 = manager_id

    std::string line;
    while (std::getline(dbfile, line)) { // read each line of the file, until end of the file
        std::stringstream linefile(line);   // to parse the line from the file
        std::string id;
        dbfile >> id;   // read in the id

        // read contents for User (for Sales to inherit)
        linefile >> username;
        linefile >> password;
        linefile >> accountName;

        // read contents for Address 1
        linefile >> sa1number;
        linefile >> sa1name;
        linefile >> sa1label;
        linefile >> city1;
        linefile >> state1;
        linefile >> areaCode1;
        linefile >> country1;

        // read contents for Address 2
        linefile >> sa2number;
        linefile >> sa2name;
        linefile >> sa2label;
        linefile >> city2;
        linefile >> state2;
        linefile >> areaCode2;
        linefile >> country2;

        // read contents for PhoneNumber
        linefile >> phoneNumber;

        // creating the new Sales and adding to Database
        PhoneNumber ph = PhoneNumber(phoneNumber);  // loaded the PhoneNumber
        Address addr1 = Address(sa1number + " " + sa1name + " " + sa1label, city1, state1, areaCode1, country1);    // loaded the Address 1
        Address addr2 = Address(sa2number + " " + sa2name + " " + sa2label, city2, state2, areaCode2, country2);    // loaded the Address 2
        Account acc = Account(accountName, addr1, addr2, ph);
        Sales s = Sales(username, password, acc, id);
        addToData(s);   // adds Sales to data
    }
    dbfile.close(); // close the file
}

std::string SalesDB::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data.at(i).toString() + "\n";
    }
    return toString;
}