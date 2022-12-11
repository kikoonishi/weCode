// PhoneNumber.h
#pragma once

#include <iostream>
#include <string>

class PhoneNumber {
private:
    std::string phone_number;   // phone number: e.g. 1(630)123-4567
public:
    PhoneNumber();  // default constructor
    PhoneNumber(std::string);   // overloaded constructor

    void setPhoneNumber(std::string);   // mutator method
    std::string getPhoneNumber() const;   // accessor method

    std::string toString(); // for printing an instance of PhoneNumber
    void copy(PhoneNumber);
};
