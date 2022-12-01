//Author: weCode
//Manager.h

#include <string>
#include "Sales.h"
#include "Product.h"
#include "Service.h"

template <class T>
class Manager :public Sales {
    private:
        Product product;//need be deleted
        Service service;//need
        static Database<T> productData;
        static Database<T> serviceData;
        
    public:
        Manager():Sales();//default constructor
        Manager(std::string):Sales(std::string);//?

        //TODO receive database as parameter
        //add,delete,edit product/service in database
        void addProduct(std::string, double);
        void addService(std::string, double);
        void deleteProduct(std::string);//delete product by name
        void deleteService(std::string);//delete service by name
        void editProduct(std::string, double);//search by name and change price
        void editService(std::string, double);

/*
in main
Product P(something);
productData.add(P);
*/

/*
change customer/name or both
 change product (newProduct)
  change service (newService)
*/
};
