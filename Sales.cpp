//Author weCode
//Sales.cpp


#include <iostream>
#include <string>
#include "Sales.h" // include definition of class Sales from Sales.h

////////TODO need to be changed based on database
template <class T>
Sales<T>::Sales() : Customer(){
    //TODO default constructor
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
    database.deleteElement(order);
}

template <class T>
void Sales<T>::deleteOrder(Database<T> database, std::string ordername){
    //get object from db by passing ordername (should it be index?)
    Order order = database.get(ordername);
    //delete order from database
    database.deleteElement(order);
}

template <class T>
void Sales<T>::deleteOrder(Database<T> database, Customer customer){
    //delete order from database
    database.deleteElement(customer);
}

template <class T>
void Sales<T>::modifyOrder(Database<T> database, Order existingOrder, Order newOrder){
    //replace existing order to new order
    database.modify(existingOrder, newOrder);
    
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
