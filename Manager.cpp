//Author weCode
//Manager.cpp

#include <string>
#include "Manager.h" // include definition of class Sales from Sales.h

////////TODO need to be changed based on database

template <class T>
Manager<T>::Manager(std::string cID): Sales::Sales(cID)      //call parent class constructor 
{
}

template <class T>
//add,delete,edit product/service
void Manager<T>::addProduct(std::string name, double cost){
    //create product obj
    Product product(this->name,this->cost);
    //add product to database
    productData.add(this->product);
}

template <class T>
void Manager<T>::addService(std::string name, double cost){
    //create service obj
    Service service(this->name, this->cost);
    //add service to database
    serviceData.add(this->service);
}

template <class T>
void Manager<T>::deleteProduct(std::string name){
    //delete product from daatabase
    productData.deleteElement(this->name);
}

template <class T>
void Manager<T>::deleteService(std::string name){
    //delete service from database
    serviceData.deleteElement(this->name);
}

template <class T>
void Manager<T>::editProduct(std::string product, double cost){
    //edit product in database
}

template <class T>
void Manager<T>::editService(std::string product, double cost){
    //edit service in database
}

//?? is there any change other than cost?

