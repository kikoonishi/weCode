//Author: weCode
//Manager.h

#include "Sales.h"

class Manager :public Sales {
    public:
        using Sales::Sales; //inherit constructor

        //add,delete,edit product/service
        void addProduct(std::string, double);
        void addService(std::string, double);
        void deleteProduct(Product);
        void deleteService(Service);
        void editProduct(Product);
        void editService(Service);
        
};
