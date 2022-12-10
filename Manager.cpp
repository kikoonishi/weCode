//Author weCode
//Manager.cpp

#include <string>
#include "Manager.h" // include definition of class Sales from Sales.h



Manager::Manager() : User() {    //default constructor
    //Manager field
    setManagerID("2");
}

//call parent class constructor 
Manager::Manager(std::string username, std::string password, std::string new_manager_id): User(username, password){
    setManagerID(new_manager_id);
}

//set id
void Manager::setManagerID(std::string newID){ manager_id = newID; }
//get id
std::string Manager::getManagerID(){ return manager_id; }

//return fields as string
std::string Manager::toString() {
    std::string toString = "";
    toString += "Manager ID: " + manager_id;
    return toString;
}


//Product/Service
template <class T>
//add,delete,edit product/service
void Manager::addProduct(Database<T> productData, Product product){
    //add product to database
    productData.add(product);
}

template <class T>
void Manager::addService(Database<T> serviceData, Service service){
    //add service to database
    serviceData.add(service);
}

template <class T>
void Manager::deleteProduct(Database<T> productData, Product product){
    //delete product from daatabase
    productData.remove(this->product);
}

template <class T>
void Manager::deleteService(Database<T> serviceData, Service service){
    serviceData.deleteElement(this->service);
}

template <class T>
void Manager::modifyProduct(Database<T> productData, Product product, Product newProduct){
    //remove
    productData.remove(product);
    //add product in database
    productData.add(newProduct);
}

template <class T>
void Manager::modifyService(Database<T> serviceData, Service service, Service newService){
    //remove
    serviceData.remove(product);
    //add product in database
    serviceData.add(newProduct);
}

template <class T>
void Manager::viewProduct(Database<T> productData){
   //get database as string and print
   productData.print();
}

template <class T>
void Manager::viewService(Database<T> serviceData){
   //get database as string and print
   serviceData.print();
}

//Order
template <class T>
void Manager::placeOrder(Database<T> orderData, Order order){
    //add order to database (ordername, product/service, quantity)
    orderData.add(order);
}

template <class T>
void Manager::deleteOrder(Database<T> orderData, Order order){
    //delete order from database
    orderData.remove(order);
}

template <class T>
void Manager::modifyOrder(Database<T> orderData, Order existingOrder, Order newOrder){
    //delete existing order
    orderData.remove(existingOrder);
    //add new order
    orderData.add(newOrder);
    
}

template <class T>
void Manager::viewOrder(Database<T> orderData){
   //get database as string and print
   orderData.print();
}
