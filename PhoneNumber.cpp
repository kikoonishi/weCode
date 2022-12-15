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
    toString += getPhoneNumber();
    return toString;    // e.g. 1(630)123-457
}

void PhoneNumber::copy(PhoneNumber toCopy) {
    this->phone_number = toCopy.getPhoneNumber();
}