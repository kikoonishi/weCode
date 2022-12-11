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

static void shopMenu(Database<Product> products, Database<Service> services)
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
        for (int i = 0; i < products.getSize(); i++)
        {
            if (products.get(i).getType() == "camera") { // go through list and if the type is a camera, then print the product as a toString
                cout << products.get(i).toString() << endl;
            }
        }
    }
    else if (option == 2)
    {
        for (int i = 0; i < i < products.getSize(); i++)
        {
            if (products.get(i).getType() == "dvr") { // go through list and if the type is a DVR, then print the product as a toString
                cout << products.get(i).toString() << endl;
            }
        }
    }
    else if (option == 3)
    {
        for (int i = 0; i < products.getSize(); i++)
        {
            if (products.get(i).getType() == "accessory") { // go through list and if the type is an accessory , then print the product as a toString
                cout << products.get(i).toString() << endl;
            }
        }
    }
    else if (option == 4)
    {
        for (int i = 0; i < services.getSize(); i++)
        {
            if (services.get(i).getType() == "installation") { // go through list and if the type is an installation, then print the service as a toString
                cout << services.get(i).toString() << endl;
            }
        }
    }
    else if (option == 5)
    {
        for (int i = 0; i < services.getSize(); i++)
        {
            if (services.get(i).getType() == "repair") { // go through list and if the type is a Repair, then print the product as a toString
                cout << services.get(i).toString() << endl;
            }
        }
    }
    else if (option == 6)
    {
        for (int i = 0; i < services.getSize(); i++)
        {
            if (services.get(i).getType() == "other") { // go through list and if the type is a Other, then print the product or service as a toString
                cout << services.get(i).toString() << endl;
            }
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

static void customerMenu(Customer customer, Database<Product> products, Database<Service> services)
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
            shopMenu(products, services);
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

static void salesMenu(Sales salesperson, Database<Order> placedOrders, Database<Product> products, 
    Database<Service> services, Database<Customer> customers, Database<Sales> sales, Database<Manager> managers)
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
            shopMenu(products, services);
        }
        else if (option == 2)
        {
            cout << " To place order, enter if you are ordering a product or service, enter product or service name, an order name, and the customers ID:" << endl;
            string productOrService;
            string productServiceName;
            string orderName;
            string customerID;
            cin >> productOrService >> productServiceName >> orderName >> customerID;
            //find the product in the database using the products name and then get the product
            //find the customer in the database using the customerID and then get the customer
            // use order constructor
            // then place the order

            Customer tempC = Customer();
            tempC.setCustomerID(customerID);

            int indexC = customers.findElement(tempC);
            if (indexC < 0) {   // negative index
                break;
            }
            Customer customer = customers.get(indexC); // finds the customer based on the id to be used for the order

            if (productOrService == "product")
            {
                Product tempP = Product();
                tempP.setName(productServiceName);

                int indexP = products.findElement(tempP);
                if (indexP < 0) {   // negative value
                    break;
                }
                Product product = products.get(indexP);
                Order order = Order(product, orderName, customer);
                salesperson.placeOrder(placedOrders, order);
            }
            else if (productOrService == "service")
            {
                Service tempS = Service();
                tempS.setName(productServiceName);

                int indexS = services.findElement(tempS);
                if (indexS < 0) {   // negative value
                    break;
                }
                Service service = services.get(indexS);
                Order order = Order(service, orderName, customer);
                salesperson.placeOrder(placedOrders, order);
            }


        }
        else if (option == 3)
        {
            placedOrders.toString();
        }
        else if (option == 4)
        {
            cout << "Enter the order name you would like to edit:" << endl;
            string orderName;
            cin >> orderName;

            Order tempO = Order();
            tempO.setOrderName(orderName);

            int indexO = placedOrders.findElement(tempO);
            if (indexO < 0) {   // negative index
                break;  
            }
            Order order = placedOrders.get(indexO);


            cout << "Choose an option of how to edit the order:" << endl;
            cout << "1.Edit product" << endl;
            cout << "2.Edit service" << endl;
            cout << "3.Edit customer" << endl;
            cout << "4.Edit order name" << endl;

            int choice;
            cin >> choice;

            if (option == 1)
            {
                cout << "Enter the correct name of the product to be input:" << endl;
                string productName;
                cin >> productName;

                Product tempP = Product();
                tempP.setName(productName);

                int indexP = products.findElement(tempP);
                if (indexP < 0) {   // negative index
                    break;
                }
                Product p = products.get(indexP);
                order.setProduct(p);
            }
            else if (option == 2)
            {
                cout << "Enter the correct name of the service to be input:" << endl;
                string serviceName;
                cin >> serviceName;

                Service tempS = Service();
                tempS.setName(serviceName);

                int indexS = services.findElement(tempS);
                if (indexS < 0) {   // negative index
                    break;
                }
                Service s = services.get(indexS);
                order.setService(s);
            }
            else if (option == 3)
            {
                cout << "Enter the correct id of the customer to be input:" << endl;
                string customerID;
                cin >> customerID;

                Customer tempC = Customer();
                tempC.setCustomerID(customerID);

                int indexC = customers.findElement(tempC);
                if (indexC < 0) {   // negative value
                    break;
                }
                Customer c = customers.get(indexC);
                order.setCustomer(c);
            }
            else if (option == 4)
            {
                cout << "Enter the correct name of the order to be input:" << endl;
                string properOrderName;
                order.setOrderName(properOrderName);
            }

        }
        else if (option == 5)
        {
            exit(0);
        }
    }
}

static void managerMenu(Manager manager, Database<Order> placedOrders, Database<Product> products, 
    Database<Service> services, Database<Customer> customers, Database<Sales> sales, Database<Manager> managers)
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
            shopMenu(products, services);
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
            manager.placeOrder(placedOrders, order);
        }
        else if (option == 3)
        {
            placedOrders.print();
        }
        else if (option == 4)
        {
            cout << "Enter the order name you would like to edit:" << endl;
            string orderName;
            cin >> orderName;

            Order tempO = Order();
            tempO.setOrderName(orderName);

            int indexO = placedOrders.findElement(tempO);
            if (indexO < 0) {    // negative index; not found
                break;
            }
            Order order = placedOrders.get(indexO);


            cout << "Choose an option of how to edit the order:" << endl;
            cout << "1.Edit product" << endl;
            cout << "2.Edit service" << endl;
            cout << "3.Edit customer" << endl;
            cout << "4.Edit order name" << endl;

            int choice;
            cin >> choice;

            if (option == 1)
            {
                cout << "Enter the correct name of the product to be input:" << endl;
                string productName;
                cin >> productName;

                Product tempP = Product();
                tempP.setName(productName);

                int indexP = products.findElement(tempP);
                if (indexP < 0) {    // negative index; not found
                    break;
                }
                Product p = products.get(indexP);

                order.setProduct(p);
            }
            else if (option == 2)
            {
                cout << "Enter the correct name of the service to be input:" << endl;
                string serviceName;
                cin >> serviceName;

                Service tempS = Service();
                tempS.setName(serviceName);

                int indexS = services.findElement(tempS);
                if (indexS < 0) {    // negative index; not found
                    break;
                }
                Service s = services.get(indexS);

                order.setService(s);
            }
            else if (option == 3)
            {
                cout << "Enter the correct id of the customer to be input:" << endl;
                string customerID;
                cin >> customerID;

                Customer tempC = Customer();
                tempC.setCustomerID(customerID);

                int indexC = customers.findElement(tempC);
                if (indexC < 0) {    // negative index; not found
                    break;
                }
                Customer c = customers.get(indexC);

                order.setCustomer(c);
            }
            else if (option == 4)
            {
                cout << "Enter the correct name of the order to be input:" << endl;
                string properOrderName;
                order.setOrderName(properOrderName);
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
                manager.addProduct(products, product);
            }
            else if (choice == "service")
            {
                cout << "Enter service name, service type, service hourly rate and service hours" << endl;
                string sName, sType, sHourlyRateString;
                int sHours;
                cin >> sName >> sType >> sHourlyRateString >> sHours;
                double sHourlyRate = stod(sHourlyRateString); // string to double function
                Service service = Service(sName, sType, sHourlyRate, sHours);
                manager.addService(services, service);
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
                Product tempP = Product();
                tempP.setName(find);

                int indexP = products.findElement(tempP);
                if (indexP < 0) {    // negative index; not found
                    break;
                }
                Product p = products.get(indexP);

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

                Service tempS = Service();
                tempS.setName(find);

                int indexS = services.findElement(tempS);
                if (indexS < 0) {    // negative index; not found
                    break;
                }
                Service s = services.get(indexS);

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

            cout << "Would you like to remove a product or a service? (Enter product or service):" << endl;
            string choice;
            cin >> choice;

            if (choice == "product")
            {
                cout << "Enter product name:" << endl;
                string name;

                Product tempP = Product();
                tempP.setName(name);

                int indexP = products.findElement(tempP);
                if (indexP < 0) {    // negative index; not found
                    break;
                }
                Product p = products.get(indexP);
                manager.deleteProduct(products, p);
            }
            else if (choice == "service")
            {
                cout << "Enter service name:" << endl;
                string name;

                Service tempS = Service();
                tempS.setName(name);

                int indexS = services.findElement(tempS);
                if (indexS < 0) {    // negative index; not found
                    break;
                }
                Service s = services.get(indexS);
                manager.deleteService(services, s);
            }


        }
        else if (option == 8)
        {
            cout << "Enter the id of the customer to be edited:" << endl;
            string customerID;
            cin >> customerID;

            Customer tempC = Customer();
            tempC.setCustomerID(customerID);

            int indexC = customers.findElement(tempC);
            if (indexC < 0) {    // negative index; not found
                break;
            }
            Customer customer = customers.get(indexC);


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
    // Databases
    Database<Customer> customers = Database<Customer>(100, "customers.txt");
    Database<Sales> sales = Database<Sales>(100, "sales.txt");
    Database<Manager> managers = Database<Manager>(100, "managers.txt");
    Database<Order> orders = Database<Order>(100, "orders.txt");
    Database<Product> products = Database<Product>(100, "products.txt");
    Database<Service> services = Database<Service>(100, "services.txt");

    // load Databases from file

    string username;
    string password;

    Customer customer;
    Sales salesperson;
    Manager manager;

    cout << "LOGIN" << endl;
    cout << "Enter USERNAME:" << endl;
    cin >> username;
    cout << "Enter PASSWORD:" << endl;
    cin >> password;

    int x;  // check who is logged in

    // check if Customer login was found
    int cUserIndex = customers.findUsername(username);
    int cPassIndex = customers.findPassword(password);

    if (cUserIndex == cPassIndex && cUserIndex >= 0) {
        customer = customers.get(cUserIndex);
        x = 1;
    }

    // check if Sales login was found
    int sUserIndex = sales.findUsername(username);
    int sPassIndex = sales.findPassword(password);

    if (sUserIndex == sPassIndex && sUserIndex >= 0) {
        salesperson = sales.get(sUserIndex);
        x = 2;
    }

    // check if Manager login was found
    int mUserIndex = managers.findUsername(username);
    int mPassIndex = managers.findPassword(password);

    if (mUserIndex == mPassIndex && mUserIndex >= 0) {
        manager = managers.get(mUserIndex);
        x = 3;
    }

    // search database to find user based on its username and password
    // if username not found, user does not exist
    // if username is found but password is wrong, reattempt password


    if (x == 1)// CUSTOMER
    {
        customerMenu(customer, products, services);
    }
    else if (x == 2)// SALES
    {
        salesMenu(salesperson, orders, products, services, customers, sales, managers);
    }
    else if (x == 3)// MANAGER
    {
        managerMenu(manager, orders, products, services, customers, sales, managers);
    }

}
