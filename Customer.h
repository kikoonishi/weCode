// Customer.h
#pragma once

#include <iostream>
#include <string>
#include "User.h"
#include "Account.h"
#include "Product.h"
#include "Service.h"
#include "Database.h"

class Customer : public User {
private:
    static int total_customers;
    std::string customer_id;
    std::string customer_type;  // business, government, or residential
public:
    Customer(); // default constructor
    Customer(std::string, std::string, Account, std::string, std::string);  // Customer fields + User fields

    void setCustomerID(std::string);
    void setCustomerType(std::string);

    void changeStreetAddress(int, std::string);  // invokes setStreetAddress() from address1 or address2 in user_account
    void changeCity(int, std::string);   // invokes setCity() from address1 or address2 in user_account
    void changeState(int, std::string);  // invokes setState() from address1 or address2 in user_account
    void changeAreaCode(int, std::string);   // invokes setAreaCode() from address1 or address2 in user_account
    void changeCountry(int, std::string);   // invokes setCountry() from address1 or address2 in user_account

    static int getTotalCustomers() { return total_customers; } // gets the number of Customer instances

    std::string getCustomerID() const;
    std::string getCustomerType() const;

    void viewProducts(Database<Product>);    // Customer can see the store's products
    void viewServices(Database<Service>);  // Customer can see the store's services

    std::string toString(); // for printing an instance of Customer
    void copy(Customer);   
};
