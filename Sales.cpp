//Author weCode
//Sales.cpp


#include <iostream>
#include <string>
#include "Sales.h" // include definition of class Sales from Sales.h

////////TODO need to be changed based on database

template <class T>
Sales<T>::Sales(std::string cID) : Customer(this->cID){}

/*
//? or this for members in user
Sales<T>::Sales(std::string username, std::string password, etc) : Customer(){}
*/

template <class T>
//??create separate method for place service order and product order
void Sales<T>::placeOrder(std::string product, std::string name, int quantity){//??product/service, customer name, quantity
    //create order object
    Order order(this->product);//TODO orderName and quantity too?
    //add order to database (ordername, product/service, quantity)
    orderData.add(this->order);
}

template <class T>
void Sales<T>::placeOrder(std::string service){
    //create order object
    Order order(this->service);//TODO
    //add order to database (ordername, product/service, quantity)
    orderData.add(this->order);
}

template <class T>
void Sales<T>::deleteOrder(std::string item){
    //delete order by ordername
    //delete order from database
    orderData.deleteElement(this->item);
}

template <class T>
void Sales<T>::modifyOrder(std::string ordername, int quantity){
    //modify by ordername and quantity
    //modify order object
    
}
template <class T>
void Sales<T>::modifyOrder(std::string, std::string){
}////modify by ordername or productname from one parameter to another

template <class T>
void Sales<T>::viewOrder(std::string){
   //serch order by ordername
}