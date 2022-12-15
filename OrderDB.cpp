// OrderDB.cpp
#include "OrderDB.h"
#include <sstream>

OrderDB::OrderDB(int newSize, std::string fname) {
    maxlength = newSize;
    filename = fname;
    data.resize(maxlength);
}

int OrderDB::getSize() const {
    return data.size();
}

int OrderDB::findElement(std::string name) const {
    if (getSize() == 0) {   // empty Database
        return -1;
    }
    else {  // there is at least one element in the Database
        for (int i = 0; i < getSize(); i++) {
            if (data.at(i).getOrderName() == name) { // if ID (Customer, Sales, Manager) or name (Order, Product, Service) are equal
                return i;
            }
        }
    }
    return -1;  // element not found
}

Order OrderDB::get(int index) const {
    if (index < getSize() && index >= 0) {   // valid index
        return data.at(index);
    }
    else {
        throw std::invalid_argument("cannot pass a negative index");
    }
}

bool OrderDB::isEqual(Order first, Order second) {
    if (first.getOrderName() == second.getOrderName()) {
        return true;
    }
    return false;
}

void OrderDB::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << data.at(i).toString() << std::endl;
    }
}

void OrderDB::writeToFile(int mode) {
    std::ofstream dbfile;

    // check if append or open mode
    if (mode == 0) {    // open in append mode
        dbfile.open(filename, std::ios_base::app);  // opens the file in append mode
        Order o = data.back();

        // write order name to file
        dbfile << o.getOrderName() + " ";

        // write Product to file
        dbfile << o.getProduct().getName() + " ";
        dbfile << o.getProduct().getType() + " ";
        dbfile << std::to_string(o.getProduct().getPrice()) + " ";

        // write Service to file
        dbfile << o.getService().getName() + " ";
        dbfile << o.getService().getType() + " ";
        dbfile << std::to_string(o.getService().getRate()) + " ";
        dbfile << std::to_string(o.getService().getHours()) + " ";

        // write Customer to file
        dbfile << o.getCustomer().getCustomerID() + " ";   // writes ID value to file
        dbfile << o.getCustomer().getCustomerType() + " "; // writes type value to file

        dbfile << o.getCustomer().getUsername() + " "; // writes Customer username to file
        dbfile << o.getCustomer().getPassword() + " "; // writes Customer password to file

        dbfile << o.getCustomer().getAccount().getName() + " ";    // writes Customer Account name to file
        dbfile << o.getCustomer().getAccount().getAddress1().toString() + " "; // writes Account Address 1 to file
        dbfile << o.getCustomer().getAccount().getAddress2().toString() + " "; // writes Account Address 2 to file
        dbfile << o.getCustomer().getAccount().getPhoneNumber().getPhoneNumber() + " ";    // writes Account Phone Number to file

        dbfile << std::endl;
        dbfile.close();
    }
    else {  // rewrite entire file
        dbfile.open(filename);

        // add each attribute value to file for each Order
        for (Order o : data) {
            // write order name to file
            dbfile << o.getOrderName() + " ";

            // write Product to file
            dbfile << o.getProduct().getName() + " ";
            dbfile << o.getProduct().getType() + " ";
            dbfile << std::to_string(o.getProduct().getPrice()) + " ";

            // write Service to file
            dbfile << o.getService().getName() + " ";
            dbfile << o.getService().getType() + " ";
            dbfile << std::to_string(o.getService().getRate()) + " ";
            dbfile << std::to_string(o.getService().getHours()) + " ";

            // write Customer to file
            dbfile << o.getCustomer().getCustomerID() + " ";   // writes ID value to file
            dbfile << o.getCustomer().getCustomerType() + " "; // writes type value to file

            dbfile << o.getCustomer().getUsername() + " "; // writes Customer username to file
            dbfile << o.getCustomer().getPassword() + " "; // writes Customer password to file

            dbfile << o.getCustomer().getAccount().getName() + " ";    // writes Customer Account name to file
            dbfile << o.getCustomer().getAccount().getAddress1().toString() + " "; // writes Account Address 1 to file
            dbfile << o.getCustomer().getAccount().getAddress2().toString() + " "; // writes Account Address 2 to file
            dbfile << o.getCustomer().getAccount().getPhoneNumber().getPhoneNumber() + " ";    // writes Account Phone Number to file

            dbfile << std::endl;
        }
        dbfile.close();
    }
}

void OrderDB::addToData(Order newElement) {
    // add the element into the list
    data.emplace_back(newElement);
}

void OrderDB::add(Order newElement) {
    // add the element into the list
    addToData(newElement);

    // add the new element into the Database file
    writeToFile(0);
}

bool OrderDB::remove(int remove) {       // not complete yet
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

void OrderDB::loadFromFile() {
    // open the file
    std::ifstream dbfile(filename);

    // Order attributes
    std::string orderName;

    // for Product in Order
    std::string pName;
    std::string pType;
    double pPrice;

    // for Service in Order
    std::string sName;
    std::string sType;
    double sRate;
    double sHours;

    // for Customer in Order
    std::string customerID;
    std::string customerType;

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

    // read the contents of the file
    std::string line;
    while (std::getline(dbfile, line)) { // read each line of the file, until end of the file
        std::stringstream linefile(line);

        // read order name
        linefile >> orderName;

        // read contents for Product
        linefile >> pName;
        linefile >> pType;
        linefile >> pPrice;

        // read contents for Service
        linefile >> sName;
        linefile >> sType;
        linefile >> sRate;
        linefile >> sHours;

        // read contents for Customer
        linefile >> customerID;
        linefile >> customerType;

        // read contents for User (for Customer to inherit)
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

        // create the new Customer for the Order
        PhoneNumber ph = PhoneNumber(phoneNumber);  // loaded the PhoneNumber
        Address addr1 = Address(sa1number + " " + sa1name + " " + sa1label, city1, state1, areaCode1, country1);    // loaded the Address 1
        Address addr2 = Address(sa2number + " " + sa2name + " " + sa2label, city2, state2, areaCode2, country2);    // loaded the Address 2
        Account acc = Account(accountName, addr1, addr2, ph);
        Customer c = Customer(username, password, acc, customerID, customerType);

        // create the new Product and new Service for the Order
        Product p = Product(pName, pType, pPrice);
        Service s = Service(sName, sType, sRate, sHours);

        // create the new Order and add to the database
        Order o = Order(p, s, orderName, c);
        addToData(o);
    }
    dbfile.close(); // close the file
}

std::string OrderDB::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data.at(i).toString() + "\n";
    }
    return toString;
}