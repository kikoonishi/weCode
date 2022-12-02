// PhoneNumber.cpp
#include "PhoneNumber.h"

PhoneNumber::PhoneNumber() {
    setPhoneNumber("12345678910");
}

PhoneNumber::PhoneNumber(std::string newPhoneNumber) {
    setPhoneNumber(newPhoneNumber);
}

void PhoneNumber::setPhoneNumber(std::string newPhoneNumber) {
    // check if a valid phone number; e.g. 16301234567, length = 11
    if (newPhoneNumber.length() != 11) {
        return; // invalid PhoneNumber
    }
    else {
        for (int i = 0; i < newPhoneNumber.length(); i++) {
            if (!isdigit(newPhoneNumber.at(i))) {
                return; // invalid PhoneNumber
            }
        }
        phone_number = newPhoneNumber;  // valid PhoneNumber
    }
}

std::string PhoneNumber::getPhoneNumber() const {
    return phone_number;
}

std::string PhoneNumber::toString() {
    std::string toString = "";
    std::string phoneNum = getPhoneNumber();
    toString += phoneNum.at(0) + "(";       // e.g. 1(
    toString += phoneNum.substr(1, 4) + ")";    // e.g. 630)
    toString += phoneNum.substr(4, 7) + "-";    // e.g. 123- 
    toString += phoneNum.substr(7);     // e.g. 4567
    return toString;    // e.g. 1(630)123-457
}