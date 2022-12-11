//Author: weCode
//Manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"
#include "Order.h"
#include "Product.h"
#include "Service.h"

//template <class T>
class Manager :public User {
private:
    std::string manager_id;

public:
    Manager(); // default constructor
    Manager(std::string, std::string, Account, std::string);//Manager fields + username, password

    void setManagerID(std::string);
    std::string getManagerID() const;
    std::string toString();
};

#endif
