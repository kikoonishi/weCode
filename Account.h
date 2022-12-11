// Account.h
#pragma once

#include <iostream>
#include <string>
#include "Address.h"
#include "PhoneNumber.h"

class Account {
private:
    std::string name;   // name of the Account holder
    Address address1;    // Account holder's primary Address
    Address address2;   // Account holder's secondary Address (optional)
    PhoneNumber phone;  // Account holder's PhoneNumber
public:
    Account();      // default constructor
    Account(std::string, Address, Address, PhoneNumber); // overloaded constructor

    void setName(std::string);
    void setAddress1(Address);
    void setAddress2(Address);
    void setPhoneNumber(std::string);

    std::string getName() const;
    Address getAddress1() const;
    Address getAddress2() const;
    PhoneNumber getPhoneNumber() const;

    std::string toString(); // for printing an instance of Account
    void copy(Account);
};
