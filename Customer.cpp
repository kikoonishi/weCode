// Customer.cpp
#include "Customer.h"
#include "Database.h"

Customer::Customer() : User() {
    setCustomerID("c0");
    setCustomerType("Residential");
    ++total_customers;
}

Customer::Customer(std::string username, std::string password, Account user_account, std::string newID, std::string type) : User(username, password, user_account) {
    setCustomerID(newID);
    setCustomerType(type);
    ++total_customers;
}

void Customer::setCustomerID(std::string id) { customer_id = id; }

void Customer::setCustomerType(std::string t) { customer_type = t; }

std::string Customer::getCustomerID() const { return customer_id; }

std::string Customer::getCustomerType() const { return customer_type; }

void Customer::changeStreetAddress(int addressNum, std::string newSA) {
    if (addressNum == 1) {
        getAccount().getAddress1().setStreetAddress(newSA);
    }
    else if (addressNum == 2) {
        getAccount().getAddress2().setStreetAddress(newSA);
    }
    else { // error
        throw std::invalid_argument("address number must be 1 or 2");
    }
}

void Customer::changeCity(int addressNum, std::string newCI) {
    if (addressNum == 1) {
        getAccount().getAddress1().setCity(newCI);
    }
    else if (addressNum == 2) {
        getAccount().getAddress2().setCity(newCI);
    }
    else { // error
        throw std::invalid_argument("address number must be 1 or 2");
    }
}

void Customer::changeState(int addressNum, std::string newST) {
    if (addressNum == 1) {
        getAccount().getAddress1().setState(newST);
    }
    else if (addressNum == 2) {
        getAccount().getAddress2().setState(newST);
    }
    else { // error
        throw std::invalid_argument("address number must be 1 or 2");
    }
}

void Customer::changeAreaCode(int addressNum, std::string newAC) {
    if (addressNum == 1) {
        getAccount().getAddress1().setAreaCode(newAC);
    }
    else if (addressNum == 2) {
        getAccount().getAddress2().setAreaCode(newAC);
    }
    else { // error
        throw std::invalid_argument("address number must be 1 or 2");
    }
}

void Customer::changeCountry(int addressNum, std::string newCO) {
    if (addressNum == 1) {
        getAccount().getAddress1().setCountry(newCO);
    }
    else if (addressNum == 2) {
        getAccount().getAddress2().setCountry(newCO);
    }
    else { // error
        throw std::invalid_argument("address number must be 1 or 2");
    }
}

//  check Order.h, Product.h, Services.h files for both functions
void Customer::viewProducts(Database<Product> products) {
    products.print();   // displays each Product
}

void Customer::viewServices(Database<Service> services) {
    services.print();   // displays each Service
}

std::string Customer::toString() {
    std::string toString = "";
    toString += getAccount().toString() + "\n";
    toString += "Customer ID: " + customer_id + "\n";
    toString += customer_type;
    return toString;
}

void Customer::copy(Customer toCopy) { 
    this->customer_id = toCopy.getCustomerID();
    this->customer_type = toCopy.getCustomerType();
    this->setUsername(toCopy.getUsername());
    this->setPassword(toCopy.getPassword());
    this->setAccount(toCopy.getAccount());
}
