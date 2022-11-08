//Author: weCode
//Manager.h

#include <Sales.h>
#include <ProductManager.h>

class Manager :public Sales {
    public:
        using Sales::Sales; //inherit constructor

        //add,delete,edit product/service
        void addProduct(Product);
        void addService(Service);
        void deleteProduct(Product);
        void deleteService(Service);
        void editProduct(Product);
        void editService(Service);
        
};