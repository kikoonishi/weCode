// User.h
#include <iostream>
#include <string>
#include <Account.h>

class User {
    private:
        std::string username;
        std::string password;
        Account user_account;   // the Customer's account: holds name, Address, PhoneNumber
    public:
        User(); // default constructor
        User(std::string, std::string); // overloaded constructor

        void setUsername(std::string);
        void setPassword(std::string);
        void setAccount(Account);

        std::string getUsername();
        std::string getPassword();
        Account getAccount();

        std::string toString(); // for printing an instance of User
};