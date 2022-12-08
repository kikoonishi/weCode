// User.h
#pragma once

#include <iostream>
#include <string>
#include <Account.h>

class User {
private:
    static int total_users;
    std::string username;
    std::string password;
    Account user_account;   // the Customer's account: holds name, Address, PhoneNumber
public:
    User(); // default constructor
    User(std::string, std::string); // overloaded constructor

    void setUsername(std::string);
    void setPassword(std::string);
    void setAccount(Account);

    static int getTotalUsers() { return total_users; }

    std::string getUsername() const;
    std::string getPassword() const;
    Account getAccount() const;

    std::string toString(); // for printing an instance of User
};
