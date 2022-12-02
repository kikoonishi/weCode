// Customer.cpp
#include "Customer.h"
#include "Database.h"

Customer::Customer() {
    setCustomerID("0");
    setCustomerType("Residential");
    //setCustomerAccount();
    ++total_customers;
}

Customer::Customer(std::string newID, std::string type, Account userAccount) {
    setCustomerID(newID);
    setCustomerType(type);
    setCustomerAccount(userAccount);
    ++total_customers;
}

void Customer::setCustomerID(std::string id) { customer_id = id; }

void Customer::setCustomerType(std::string t) { customer_type = t; }

void Customer::setCustomerAccount(Account userAccount) { customer_account = userAccount; }

std::string Customer::getCustomerID() const { return customer_id; }

std::string Customer::getCustomerType() const { return customer_type; }

void Customer::changeStreetAddress(int addressNum, std::string newSA) {
    if (addressNum == 1) {
        customer_account.getAddress1().setStreetAddress(newSA);
    } 
    else if (addressNum == 2) {
        customer_account.getAddress2().setStreetAddress(newSA);
    } 
    else {
        // error
    }
}

void Customer::changeCity(int addressNum, std::string newCI) {
    if (addressNum == 1) {
        customer_account.getAddress1().setCity(newCI);
    } 
    else if (addressNum == 2) {
        customer_account.getAddress2().setCity(newCI);
    } 
    else {
        // error
    }
}

void Customer::changeState(int addressNum, std::string newST) {
    if (addressNum == 1) {
        customer_account.getAddress1().setState(newST);
    } 
    else if (addressNum == 2) {
        customer_account.getAddress2().setState(newST);
    } 
    else {
        // error
    }
}

void Customer::changeAreaCode(int addressNum, std::string newAC) {
    if (addressNum == 1) {
        customer_account.getAddress1().setAreaCode(newAC);
    } 
    else if (addressNum == 2) {
        customer_account.getAddress2().setAreaCode(newAC);
    } 
    else {
        // error
    }
}

void Customer::changeCountry(int addressNum, std::string newCO) {
    if (addressNum == 1) {
        customer_account.getAddress1().setCountry(newCO);
    } 
    else if (addressNum == 2) {
        customer_account.getAddress2().setCountry(newCO);
    } 
    else {
        // error
    }
}

//  check Order.h, Product.h, Services.h files for both functions
void Customer::viewProducts() {//Database<Products> products) {

}

void Customer::viewServices() {

}
//

std::string Customer::toString() {
    std::string toString = "";
    toString += customer_account.toString() + "\n";
    toString += "Customer ID: " + customer_id + "\n";
    toString += customer_type;
    return toString;
}