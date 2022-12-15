// Customer.h
#pragma once

#include "User.h"
#include "Product.h"
#include "Service.h"

class Customer : public User {
private:
    std::string customer_id;
    std::string customer_type;  // business, government, or residential
public:
    Customer(); // default constructor + User fields
    Customer(std::string, std::string, Account, std::string, std::string);  // Customer fields + User fields

    void setCustomerID(std::string);
    void setCustomerType(std::string);

    void changeStreetAddress(int, std::string);  // invokes setStreetAddress() from address1 or address2 in user_account
    void changeCity(int, std::string);   // invokes setCity() from address1 or address2 in user_account
    void changeState(int, std::string);  // invokes setState() from address1 or address2 in user_account
    void changeAreaCode(int, std::string);   // invokes setAreaCode() from address1 or address2 in user_account
    void changeCountry(int, std::string);   // invokes setCountry() from address1 or address2 in user_account

    std::string getCustomerID() const;
    std::string getCustomerType() const;

    std::string toString(); // for printing an instance of Customer
    void copy(Customer);
};