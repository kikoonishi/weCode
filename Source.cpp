// weCodeProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Manager.h"
#include "Sales.h"
#include "Customer.h"
#include "Order.h"
#include "User.h"
#include "Database.h"
using namespace std;

static void shopMenu(Database productsAndServices)
{

    cout << "Welcome to the shop! Select one of the following options to browse products and services" << endl;
    cout << "--------------------------------------------" << endl;
    cout << " 1. Cameras " << endl;
    cout << " 2. DVR's " << endl;
    cout << " 3. Accesories " << endl;
    cout << " 4. Installation " << endl;
    cout << " 5. Repair " << endl;
    cout << " 6. Other " << endl;

    int option;
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < productsAndServices.size; i++)
        {
            if () // go through list and if the type is a camera, then print the product as a toString
        }
    }
    else if (option == 2)
    {
        for (int i = 0; i < productsAndServices.size; i++)
        {
            if () // go through list and if the type is a DVR, then print the product as a toString
        }
    }
    else if (option == 3)
    {
        for (int i = 0; i < productsAndServices.size; i++)
        {
            if () // go through list and if the type is a Accesorie, then print the product as a toString
        }
    }
    else if (option == 4)
    {
        for (int i = 0; i < productsAndServices.size; i++)
        {
            if () // go through list and if the type is a Installation, then print the service as a toString
        }
    }
    else if (option == 5)
    {
        for (int i = 0; i < productsAndServices.size; i++)
        {
            if () // go through list and if the type is a Repair, then print the product as a toString
        }
    }
    else if (option == 6)
    {
        for (int i = 0; i < productsAndServices.size; i++)
        {
            if () // go through list and if the type is a Other, then print the product or service as a toString
        }
    }
}

static void changeInfo(Customer customer)
{
    cout << "Select one of the following to edit:" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1.Change Address 1" << endl;
    cout << "2.Change Address 2" << endl;
    cout << "3.Change Phone Number" << endl;
    // maybe do a change username and password???

    int option;
    cin >> option;

    if (option == 1) {
        cout << " Enter proper Street Address:" << endl;
        string edit;
        cin >> edit;
        customer.changeStreetAddress(1, edit);  // invokes setStreetAddress() from address1 or address2 in user_account
        cout << "Enter proper City:" << endl;
        cin >> edit;
        customer.changeCity(1, edit);   // invokes setCity() from address1 or address2 in user_account
        cout << "Enter proper State:" << endl;
        cin >> edit;
        customer.changeState(1, edit);  // invokes setState() from address1 or address2 in user_account
        cout << "Enter proper Area Code:" << endl;
        cin >> edit;
        customer.changeAreaCode(1, edit);   // invokes setAreaCode() from address1 or address2 in user_account
        cout << "Enter proper Country:" << endl;
        cin >> edit;
        customer.changeCountry(1, edit);
    }
    else if (option == 2) {
        cout << " Enter proper Street Address:" << endl;
        string edit;
        cin >> edit;
        customer.changeStreetAddress(2, edit);  // invokes setStreetAddress() from address1 or address2 in user_account
        cout << "Enter proper City:" << endl;
        cin >> edit;
        customer.changeCity(2, edit);   // invokes setCity() from address1 or address2 in user_account
        cout << "Enter proper State:" << endl;
        cin >> edit;
        customer.changeState(2, edit);  // invokes setState() from address1 or address2 in user_account
        cout << "Enter proper Area Code:" << endl;
        cin >> edit;
        customer.changeAreaCode(2, edit);   // invokes setAreaCode() from address1 or address2 in user_account
        cout << "Enter proper Country:" << endl;
        cin >> edit;
        customer.changeCountry(2, edit);
    }
    else if (option == 3) {
        cout << " Enter proper Phone Number:" << endl;
        string edit;
        cin >> edit;
        // change password command here

           
    }
    
}

static void customerMenu(Customer customer, Database productsAndServices)
{
    while (true) {
        cout << "Welcome! Select one of the following options" << endl;
        cout << "--------------------------------------------" << endl;
        cout << " 1. Shop " << endl;
        cout << " 2. My Info " << endl;
        cout << " 3. Logout " << endl;

        int option;
        cin >> option;
        if (option == 1)
        {
            shopMenu(productsAndServices);
        }
        else if (option == 2)
        {

            cout << customer.toString() << endl;
            cout << "Is the info correct?" << endl;
            string answer;
            cin >> answer;
            if (answer == "no" || answer == "No")
            {
                changeInfo(customer);
            }
        }
        else
        {
            exit(0);
        }
    }
            
}

static void salesMenu(Sales sales, Database placedOrders, Database productsAndServices)
{
    while (true)
    {
        cout << "Welcome! Select one of the following options" << endl;
        cout << "--------------------------------------------" << endl;
        cout << " 1. Shop " << endl;
        cout << " 2. Place Orders " << endl;
        cout << " 3. View Orders " << endl;
        cout << " 4. Edit Order " << endl;
        cout << " 5. Logout " << endl;

        int option;
        cin >> option;
        if (option == 1)
        {
            shopMenu(productsAndServices);
        }
        else if (option == 2)
        {
            cout << " To place order, enter product or service name, an order name, and the customers ID:" << endl;
            string productServiceName;
            string orderName;
            int customerID;
            cin >> productServiceName >> orderName >> customerID;
            //find the product in the database using the products name and then get the product
            //find the customer in the database using the customerID and then get the customer
            // use order constructor
            // then place the order
            Order order;
            sales.placeOrder(order);
        }
        else if (option == 3)
        {

            placedOrders.print();
        }
        else if (option == 4)
        {
            Order order4;// need a way to find the order
            cout << "Choose an option of how to edit the order:" << endl;
            cout << "1.Edit product" << endl;
            cout << "2.Edit service" << endl;
            cout << "3.Edit customer" << endl;
            cout << "4.Edit order name" << endl;
            
            int choice;
            cin >> choice;

            if (option == 1)
            {
                order4.setProduct(Product p);
            }
            else if (option == 2)
            {
                order4.setService(Service s);
            }
            else if (option == 3)
            {
                order4.setCustomer(Customer c);
            }
            else if (option == 4)
            {
                order4.setOrderName(std::string name);
            }
            
        }
        else if (option == 5)
        {
            exit(0);
        }
    }
}

static void managerMenu(Manager manager, Database placedOrders,Database productsAndServices, Database users)
{

    while (true)
    {
        cout << "Welcome! Select one of the following options" << endl;
        cout << "--------------------------------------------" << endl;
        cout << " 1. Shop " << endl;
        cout << " 2. Place Orders " << endl;
        cout << " 3. View Orders " << endl;
        cout << " 4. Edit Order " << endl;
        cout << " 5. Create Product/Service " << endl;
        cout << " 6. Edit Product/Service " << endl;
        cout << " 7. Remove Product/Service " << endl;
        cout << " 8. Customers Info " << endl;
        cout << " 9. Logout " << endl;

        int option;
        cin >> option;
        if (option == 1)
        {
            shopMenu(productsAndServices);
        }
        else if (option == 2)
        {
            cout << " To place order, enter product or service name, an order name, and the customers ID:" << endl;
            string productServiceName;
            string orderName;
            int customerID;
            cin >> productServiceName >> orderName >> customerID;
            //find the product in the database using the products name and then get the product
            //find the customer in the database using the customerID and then get the customer
            // use order constructor
            // then place the order
            Order order;
            sales.placeOrder(order);
        }
        else if (option == 3)
        {
            placedOrders.print();
        }
        else if (option == 4)
        {
            Order order4;// need a way to find the order
            cout << "Choose an option of how to edit the order:" << endl;
            cout << "1.Edit product" << endl;
            cout << "2.Edit service" << endl;
            cout << "3.Edit customer" << endl;
            cout << "4.Edit order name" << endl;

            int choice;
            cin >> choice;

            if (option == 1)
            {
                order4.setProduct(Product p);
            }
            else if (option == 2)
            {
                order4.setService(Service s);
            }
            else if (option == 3)
            {
                order4.setCustomer(Customer c);
            }
            else if (option == 4)
            {
                order4.setOrderName(std::string name);
            }
        }
        else if (option == 5)
        {

            cout << "Would you like to add a product or a service? (Enter product or service):" << endl;
            string choice;
            cin >> choice;

            if (choice == "product")
            {
                cout << "Enter product name, product type, product price" << endl;
                string pName, pType, pPriceString;
                cin >> pName >> pType >> pPriceString;
                double pPrice = stod(pPriceString); // string to double function
                Product product = Product(pName, pType, pPrice);
                manager.addProduct(product);
            }
            else if (choice == "service")
            {
                cout << "Enter service name, service type, service hourly rate and service hours" << endl;
                string sName, sType, sHourlyRateString;
                int sHours;
                cin >> sName >> sType >> sHourlyRateString >> sHours;
                double sHourlyRate = stod(sHourlyRateString); // string to double function
                Service service = Service(sName, sType, sHourlyRate,sHours);
                manager.addService(service);
            }
        }
        else if (option == 6)
        {
            cout << "Would you like to edit a product or a service? (Enter product or service):" << endl;
            string choice;
            cin >> choice;
            if (choice == "product")
            {
                cout << "Enter Product name to be edited" << endl;
                string find;
                cin >> find;
                //find the product with the corresponding name
                Product p;

                cout << "Enter the option of how you would like to edit the product" << endl;
                cout << "1.Edit Product Name" << endl;
                cout << "2.Edit Product Type" << endl;
                cout << "3.Edit Product Price" << endl;

                int option;
                cin >> option;

                if (option == 1)
                {
                    cout << "Enter proper name:" << endl;
                    string name;
                    p.setName(name);
                }
                else if (option == 2)
                {
                    cout << "Enter proper type:" << endl;
                    string type;
                    p.setType(type);
                }
                else if (option == 3)
                {
                    cout << "Enter proper price:" << endl;
                    int price;
                    p.setPrice(price);
                }



            }
            else if (choice == "service")
            {
                cout << "Enter Service name to be edited" << endl;
                string find;
                cin >> find;
                //find the product with the corresponding name
                Service s;

                cout << "Enter the option of how you would like to edit the Service" << endl;
                cout << "1.Edit Service Name" << endl;
                cout << "2.Edit Service Type" << endl;
                cout << "3.Edit Service Hourly Rate" << endl;
                cout << "4.Edit Service Number of Hours" << endl;

                int option;
                cin >> option;

                if (option == 1)
                {
                    cout << "Enter proper name:" << endl;
                    string name;
                    s.setName(name);
                }
                else if (option == 2)
                {
                    cout << "Enter proper type:" << endl;
                    string type;
                    s.setType(type);
                }
                else if (option == 3)
                {
                    cout << "Enter proper hourly rate:" << endl;
                    double hourlyRate;
                    s.setRate(hourlyRate);
                }
                else if (option == 4)
                {
                    cout << "Enter proper number of hours" << endl;
                    int hours;
                    s.setHours(hours);
                }
            }


        }
        else if (option == 7)
        {
            Product product;
            Service service;
            string productName = product.getName();
            string serviceName = service.getName();

            //remove
        }
        else if (option == 8)
        {
            // find the user
            // mnue to change their info
            Customer customer;


            cout << " Enter proper Street Address:" << endl;
            string edit;
            cin >> edit;
            customer.changeStreetAddress(2, edit);  // invokes setStreetAddress() from address1 or address2 in user_account
            cout << "Enter proper City:" << endl;
            cin >> edit;
            customer.changeCity(2, edit);   // invokes setCity() from address1 or address2 in user_account
            cout << "Enter proper State:" << endl;
            cin >> edit;
            customer.changeState(2, edit);  // invokes setState() from address1 or address2 in user_account
            cout << "Enter proper Area Code:" << endl;
            cin >> edit;
            customer.changeAreaCode(2, edit);   // invokes setAreaCode() from address1 or address2 in user_account
            cout << "Enter proper Country:" << endl;
            cin >> edit;
        }
        else if (option == 9)
        {
            exit(0);
        }
    }
}



int main()
{

    string username;
    string password;
    User user;

    cout << "LOGIN" << endl;
    cout << "Enter USERNAME:" << endl;
    cin >> username;
    cout << "Enter PASSWORD:" << endl;
    cin >> password;



// search database to find user based on its username and password
// if username not found, user does not exist
// if username is found but password is wrong, reattempt password
        int x = 2;
        

        if (x == 1)// CUSTOMER
        {
            customerMenu();
        }
        else if (x == 2)// SALES
        { 
            salesMenu(); 
        }
        else if (x == 3)// MANAGER
        {
            managerMenu();
        }
    
}

