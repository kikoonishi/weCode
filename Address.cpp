// Address.cpp
#include "Address.h"

Address::Address() {
    setStreetAddress("0");
    setCity("0");
    setState("0");
    setAreaCode("0");
    setCountry("0");
}

Address::Address(std::string newStreetAddress, std::string newCity, std::string newState, std::string newAreaCode, std::string newCountry) {
    setStreetAddress(newStreetAddress);
    setCity(newCity);
    setState(newState);
    setAreaCode(newAreaCode);
    setCountry(newCountry);
}

void Address::setStreetAddress(std::string newStreetAddress) {
    streetAddress = newStreetAddress;
}

void Address::setCity(std::string newCity) {
    city = newCity;
}
void Address::setState(std::string newState) {
    state = newState;
}
void Address::setAreaCode(std::string newAreaCode) {
    areaCode = newAreaCode;
}

void Address::setCountry(std::string newCountry) {
    country = newCountry;
}

std::string Address::getStreetAddress() const {
    return streetAddress;
}

std::string Address::getCity() const {
    return city;
}
std::string Address::getState() const {
    return state;
}
std::string Address::getAreaCode() const {
    return areaCode;
}

std::string Address::getCountry() const {
    return country;
}

std::string Address::toString() {
    std::string toString = "";
    toString += getStreetAddress() + " ";  // e.g. 1234 Example Rd.
    toString += getCity() + ", ";   // e.g. Naperville
    toString += getState() + " ";  // e.g. IL
    toString += getAreaCode() + " ";   // e.g. 12345
    toString += getCountry();  // e.g. United States
    return toString;
}