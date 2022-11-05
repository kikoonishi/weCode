// Customer.h
#include <iostream>
#include <string>
#include <User.h>

class Customer : private User {
    private:
        std::string customer_id;
    public:
        Customer(); // default constructor
        Customer(std::string);  // overloaded constructor

        void setCustomerID(std::string);  
        void changeStreetAddress(int, std::string);  // invokes setStreetAddress() from address1 or address2 in user_account
        void changeCity(int, std::string);   // invokes setCity() from address1 or address2 in user_account
        void changeState(int, std::string);  // invokes setState() from address1 or address2 in user_account
        void changeAreaCode(int, std::string);   // invokes setAreaCode() from address1 or address2 in user_account
        void changeCountry(int, std::string);   // invokes setCountry() from address1 or address2 in user_account

        std::string getCustomerID();
        void viewProducts();    // Customer can see the store's products
        void viewPrices();  // Customer can see the prices of the store's products

        std::string toString(); // for printing an instance of Customer
};