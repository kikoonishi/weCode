//Author weCode
//Manager.cpp

#include <string>
#include "Manager.h" // include definition of class Sales from Sales.h


template <class T>
Manager<T>::Manager() : Sales(){
    //TODO default constructor
    setCustomerID("0");
    setCustomerType("Sales");
    ++total_customers;
}

template <class T>
Manager<T>::Sales<T>(std::string newID, std::string type, Account userAccount): Sales(newID, type, userAccount){}      //call parent class constructor 

template <class T>
//add,delete,edit product/service
void Manager<T>::addProduct(Database<T> productData, Product product){
    //add product to database
    productData.add(product);
}

template <class T>
void Manager<T>::addService(Database<T> serviceData, Service service){
    //add service to database
    serviceData.add(service);
}

template <class T>
void Manager<T>::deleteProduct(Database<T> productData, Product product){
    //delete product from daatabase
    productData.remove(this->product);
}

template <class T>
void Manager<T>::deleteService(Database<T> serviceData, Service service){
    serviceData.deleteElement(this->service);
}

template <class T>
void modifyProduct(Database<T> productData, Product product, Product newProduct){
    //remove
    productData.remove(product);
    //add product in database
    productData.add(newProduct);
}

template <class T>
void Manager<T>::modifyService(Database<T> serviceData, Service service, Service newService){
    //remove
    serviceData.remove(product);
    //add product in database
    serviceData.add(newProduct);
}
