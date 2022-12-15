//Author weCode
//Manager.cpp

#include "Manager.h" // include definition of class Sales from Sales.h



Manager::Manager() : User() {    //default constructor
    //Manager field
    setManagerID("2");
}

//call parent class constructor 
Manager::Manager(std::string username, std::string password, Account user_account, std::string new_manager_id) : User(username, password, user_account) {
    setManagerID(new_manager_id);
}

//set id
void Manager::setManagerID(std::string newID) { manager_id = newID; }
//get id
std::string Manager::getManagerID() const { return manager_id; }

//return fields as string
std::string Manager::toString() {
    std::string toString = "";
    toString += "Manager ID: " + manager_id;
    return toString;
}