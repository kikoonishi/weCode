// Account.cpp
#include "Account.h"

Account::Account() {
    setName("Nobody");
}

Account::Account(std::string newName, Address newAddress1, Address newAddress2, PhoneNumber newPhone) {
    setName(newName);
    setAddress1(newAddress1);
    setAddress2(newAddress2);
    setPhoneNumber(newPhone.getPhoneNumber());
}

void Account::setName(std::string newName) {
    name = newName;
}

void Account::setAddress1(Address newAddress) {     // deep copy
    address1.setStreetAddress(newAddress.getStreetAddress());  // gets new street address
    address1.setCity(newAddress.getCity());    // gets new city
    address1.setState(newAddress.getState());  // gets new state
    address1.setAreaCode(newAddress.getAreaCode());    // gets new area code
    address1.setCountry(newAddress.getCountry());  // gets new country
}

void Account::setAddress2(Address newAddress) {     // deep copy
    address2.setStreetAddress(newAddress.getStreetAddress());  // gets new street address
    address2.setCity(newAddress.getCity());    // gets new city
    address2.setState(newAddress.getState());  // gets new state
    address2.setAreaCode(newAddress.getAreaCode());    // gets new area code
    address2.setCountry(newAddress.getCountry());  // gets new country
}

void Account::setPhoneNumber(std::string newPhoneNumber) {
    phone.setPhoneNumber(newPhoneNumber);
}

std::string Account::getName() const {
    return name;
}

Address Account::getAddress1() const {
    return address1;
}

Address Account::getAddress2() const {
    return address2;
}

PhoneNumber Account::getPhoneNumber() const {
    return phone;
}

std::string Account::toString() {
    std::string toString = "";
    toString += "Account: " + getName() + "\n";
    toString += "Address 1: " + getAddress1().toString() + "\n";
    toString += "Address 2: " + getAddress2().toString() + "\n";
    toString += "Phone Number: " + getPhoneNumber().toString();
    return toString;
}

void Account::copy(Account toCopy) {
    this->name = toCopy.getName();
    this->address1.copy(toCopy.getAddress1());
    this->address2.copy(toCopy.getAddress2());
    this->phone.copy(toCopy.getPhoneNumber());
}