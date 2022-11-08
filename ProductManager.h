//Author: weCode
//ProductManager.h
//Manager can add/delete/edit products/services from database

#include <Product.h>
#include <Service.h>

class ProductManager {//could be done in product/service class?
    private:
        Product product;
        Service service;
    public:
        ProductManager();
        ProductManager(Product);
        ProductManager(Service);

        Product getProduct();
        Service getService();

        //add,delete,edit product/service
        void addProduct(Product);
        void addService(Service);
        void deleteProduct(Product);
        void deleteService(Service);
        void editProduct(Product);
        void editService(Service);

};