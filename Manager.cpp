//Author weCode
//Manager.cpp

#include <string>
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


//Product/Service
//add,delete,edit product/service
void Manager::addProduct(Database<Product> productData, Product product) {
    //add product to database
    productData.add(product);
}

void Manager::addService(Database<Service> serviceData, Service service) {
    //add service to database
    serviceData.add(service);
}

void Manager::deleteProduct(Database<Product> productData, Product product) {
    //delete product from daatabase
    productData.remove(product);
}

void Manager::deleteService(Database<Service> serviceData, Service service) {
    serviceData.remove(service);
}

void Manager::modifyProduct(Database<Product> productData, Product product, Product newProduct) {
    //remove
    productData.remove(product);
    //add product in database
    productData.add(newProduct);
}

void Manager::modifyService(Database<Service> serviceData, Service service, Service newService) {
    //remove
    serviceData.remove(service);
    //add product in database
    serviceData.add(newService);
}

void Manager::viewProduct(Database<Product> productData) {
    //get database as string and print
    productData.print();
}

void Manager::viewService(Database<Service> serviceData) {
    //get database as string and print
    serviceData.print();
}

//Order
void Manager::placeOrder(Database<Order> orderData, Order order) {
    //add order to database (ordername, product/service, quantity)
    orderData.add(order);
}

void Manager::deleteOrder(Database<Order> orderData, Order order) {
    //delete order from database
    orderData.remove(order);
}

void Manager::modifyOrder(Database<Order> orderData, Order existingOrder, Order newOrder) {
    //delete existing order
    orderData.remove(existingOrder);
    //add new order
    orderData.add(newOrder);

}

void Manager::viewOrder(Database<Order> orderData) {
    //get database as string and print
    orderData.print();
}
