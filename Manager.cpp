//Author weCode
//Manager.cpp

#include <string>
#include "Manager.h" // include definition of class Sales from Sales.h

////////TODO need to be changed based on database

//TODO constructor

template <class T>
Manager<T>::Manager() : Sales(){
    //TODO default constructor
    setCustomerID("0");
    setCustomerType("Sales");
    ++total_customers;
}

template <class T>
Manager<T>::Manager(std::string newID, std::string type, Account userAccount): Sales(newID, type, userAccount){}      //call parent class constructor 

template <class T>
//add,delete,edit product/service
void Manager<T>::addProduct(Database<T> productData, Product product){
    //add product to database
    productData.add(this->product);
}

template <class T>
void Manager<T>::addService(Database<T> serviceData, Service service){
    //add service to database
    serviceData.add(this->service);
}

template <class T>
void Manager<T>::deleteProduct(Database<T> productData, Product product){
    //delete product from daatabase
    productData.deleteElement(this->product);
}

template <class T>
void Manager<T>::deleteProduct(Database<T> productData, std::string name){
    //get object from db by passing name (should it be index?)
    Product product = productData.get(name);
    //delete product from daatabase
    productData.deleteElement(this->product);
}

template <class T>
void Manager<T>::deleteService(Database<T> serviceData, Service service){
    //delete service from database
    serviceData.deleteElement(this->service);
}

template <class T>
void Manager<T>::deleteService(Database<T> serviceData, std::string name){
    //get object from db by passing name (should it be index?)
    Service service = serviceData.get(name);
    //delete service from database
    serviceData.deleteElement(this->service);
}

template <class T>
void modifyProduct(Database<T> productData, Product product, Product newProduct){
    //edit product in database
    productData.modify(product, newProduct);
}

template <class T>
void Manager<T>::modifyService(Database<T> serviceData, Service service, Service newService){
    //edit service in database
    serviceData.modify(service, newService);
}

