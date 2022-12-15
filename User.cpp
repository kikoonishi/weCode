// User.cpp
#include "User.h"

User::User() {
    setUsername("username");
    setPassword("password");
}

User::User(std::string newUsername, std::string newPassword, Account newAccount) {
    setUsername(newUsername);
    setPassword(newPassword);
    setAccount(newAccount);
}

void User::setUsername(std::string newUsername) {
    username = newUsername;
}

void User::setPassword(std::string newPassword) {
    password = newPassword;
}

void User::setAccount(Account newAccount) {
    user_account.setName(newAccount.getName()); // copies new name
    user_account.setAddress1(newAccount.getAddress1()); // copies address1
    user_account.setAddress2(newAccount.getAddress2()); // copies address2
    user_account.setPhoneNumber(newAccount.getPhoneNumber().getPhoneNumber());   // copies phone
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

Account User::getAccount() const {
    return user_account;
}

std::string User::toString() {
    std::string toString = "";
    toString += "Username: " + username + "\n";
    toString += "Password: " + password;
    return toString;
}