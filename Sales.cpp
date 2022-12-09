//Author weCode
//Sales.cpp


#include <iostream>
#include <string>
#include "Sales.h" // include definition of class Sales from Sales.h


template <class T>
Sales<T>::Sales() : Customer(){
    //default constructor
    setCustomerID("0");
    setCustomerType("Sales");
    ++total_customers;
}

template <class T>
Sales<T>::Sales(std::string newID, std::string type, Account userAccount) : Customer(newID, type, userAccount){}

template <class T>
void Sales<T>::placeOrder(Database<T> database, Order order){
    //add order to database (ordername, product/service, quantity)
    database.add(order);
}


template <class T>
void Sales<T>::deleteOrder(Database<T> database, Order order){
    //delete order from database
    database.remove(order);
}

template <class T>
void Sales<T>::deleteOrder(Database<T> database, Customer customer){
    //delete order from database
    database.remove(customer);
}

template <class T>
void Sales<T>::modifyOrder(Database<T> database, Order existingOrder, Order newOrder){
    //delete existing order
    database.remove(existingOrder);
    //add new order
    database.add(newOrder);
    
}

template <class T>
void Sales<T>::viewOrder(Database<T> database){
   //get database as string and print
   std::cout << database.toString() << std::endl; 
}

template <class T>
std::string toString(Database<T> database){
    //get database as string and return
    return database.toString();
};
