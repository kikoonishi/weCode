// Address.h
#include <iostream>
#include <string>

class Address {
    private:
        std::string streetAddress; // primary street address
        std::string city;
        std::string state;  // only if country is the United States
        std::string areaCode;
        std::string country;
    public:
        Address();  // default constructor
        Address(std::string, std::string, std::string, std::string, std::string);   // overloaded constructor

        // mutators / setters
        void setStreetAddress(std::string);
        void setCity(std::string);
        void setState(std::string);
        void setAreaCode(std::string);
        void setCountry(std::string);

        // accessors / getters
        std::string getStreetAddress();
        std::string getCity();
        std::string getState();
        std::string getAreaCode();
        std::string getCountry();
        std::string toString(); // for printing an instance of Address
};
