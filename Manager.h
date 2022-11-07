//Author: weCode
//Manager.h

#include <Sales.h>
#include <ProductManager.h>

class Manager :private Sales{
    private:
        ProductManager productManager;//be able to delete/add/edit products/service
    public:
        Manager(); //default constructor
        Manager(ProductManager);
        
};