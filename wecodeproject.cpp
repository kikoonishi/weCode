// wecodeproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "CustomerDB.h"
#include "SalesDB.h"
#include "ManagerDB.h"
#include "OrderDB.h"
#include "ProductDB.h"
#include "ServiceDB.h"
using namespace std;

// global function prototypes
void shopMenu(ProductDB, ServiceDB);
void changeInfo(Customer);
void customerMenu(Customer, ProductDB, ServiceDB);
void salesMenu(Sales, OrderDB, ProductDB, ServiceDB, CustomerDB, SalesDB, ManagerDB);
void managerMenu(Manager, OrderDB, ProductDB, ServiceDB, CustomerDB, SalesDB, ManagerDB);

void loadExampleCustomers(CustomerDB);  // run once to set up file for CustomerDB
void loadExampleSales(SalesDB);         // run once to set up file for SalesDB
void loadExampleManagers(ManagerDB);    // run once to set up file for ManagerDB
void loadExampleOrders(OrderDB);        // run once to set up file for OrderDB
void loadExampleProducts(ProductDB);    // run once to set up file for ProductDB
void loadExampleServices(ServiceDB);    // run once to set up file for ServiceDB


int main()
{
    // Databases
    CustomerDB customers = CustomerDB(0, "customers.txt");
    SalesDB sales = SalesDB(0, "sales.txt");
    ManagerDB managers = ManagerDB(0, "managers.txt");
    OrderDB orders = OrderDB(0, "orders.txt");
    ProductDB products = ProductDB(0, "products.txt");
    ServiceDB services = ServiceDB(0, "services.txt");

    // populate the Databases by reading from the text files
    customers.loadFromFile();
    sales.loadFromFile();
    managers.loadFromFile();
    orders.loadFromFile();
    products.loadFromFile();
    services.loadFromFile();

    // have a temporary object for each login case
    Customer customer = Customer();
    Sales salesperson = Sales();
    Manager manager = Manager();

    string username, password;

    cout << "LOGIN" << endl;
    cout << "Enter USERNAME:" << endl;
    cin >> username;
    cout << "Enter PASSWORD:" << endl;
    cin >> password;

    int x = 0;  // check who is logged in

    // check if Customer login was found
    int cUserIndex = customers.findUsername(username);
    int cPassIndex = customers.findPassword(password);

    // check if Sales login was found
    int sUserIndex = sales.findUsername(username);
    int sPassIndex = sales.findPassword(password);

    // check if Manager login was found
    int mUserIndex = managers.findUsername(username);
    int mPassIndex = managers.findPassword(password);

    // search across databases for a matching login
    if (cUserIndex == cPassIndex && cUserIndex >= 0) {
        customer = customers.get(cUserIndex);
        cout << "Logging in as: Customer" << endl;
        x = 1;
    }
    else if (sUserIndex == sPassIndex && sUserIndex >= 0) {
        salesperson = sales.get(sUserIndex);
        cout << "Logging in as: Sales" << endl;
        x = 2;
    }
    else if (mUserIndex == mPassIndex && mUserIndex >= 0) {
        manager = managers.get(mUserIndex);
        cout << "Logging in as: Manager" << endl;
        x = 3;
    }

    if (x == 1)// CUSTOMER
    {
        customerMenu(customer, products, services); // invoke the menu for Customers
    }
    else if (x == 2)// SALES
    {
        salesMenu(salesperson, orders, products, services, customers, sales, managers); // invoke the menu for Sales
    }
    else if (x == 3)// MANAGER
    {
        managerMenu(manager, orders, products, services, customers, sales, managers);   // invoke the menu for Managers
    }
    else {
        string choice;
        cout << "Unable to login. Which login do you want to create? (customer, sales, manager): " << endl;
        cin >> choice;

        if (choice == "customer") {
            customerMenu(customer, products, services);
        }
        else if (choice == "sales") {
            salesMenu(salesperson, orders, products, services, customers, sales, managers);
        }
        else if (choice == "manager") {
            managerMenu(manager, orders, products, services, customers, sales, managers);
        }
        else {
            cout << "Invalid choice. Leaving the system.\n" << endl;
        }

    }

}

void shopMenu(ProductDB products, ServiceDB services)
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
        for (int i = 0; i < products.getSize(); i++)
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

void changeInfo(Customer customer)
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

void customerMenu(Customer customer, ProductDB products, ServiceDB services)
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

void salesMenu(Sales salesperson, OrderDB placedOrders, ProductDB products, ServiceDB services, CustomerDB customers, SalesDB sales, ManagerDB managers)
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

            int indexC = customers.findElement(customerID);
            if (indexC < 0) {   // negative index
                break;
            }
            Customer customer = customers.get(indexC); // finds the customer based on the id to be used for the order

            if (productOrService == "product")
            {
                int indexP = products.findElement(productServiceName);
                if (indexP < 0) {   // negative value
                    break;
                }
                Product product = products.get(indexP);
                Order order = Order(product, orderName, customer);
                placedOrders.add(order);    // adds the order to database
            }
            else if (productOrService == "service")
            {
                int indexS = services.findElement(productServiceName);
                if (indexS < 0) {   // negative value
                    break;
                }
                Service service = services.get(indexS);
                Order order = Order(service, orderName, customer);
                placedOrders.add(order);    // adds the order to database
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

            int indexO = placedOrders.findElement(orderName);
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

                int indexP = products.findElement(productName);
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

                int indexS = services.findElement(serviceName);
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

                int indexC = customers.findElement(customerID);
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

void managerMenu(Manager manager, OrderDB placedOrders, ProductDB products, ServiceDB services, CustomerDB customers, SalesDB sales, ManagerDB managers)
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
            placedOrders.add(order);    // adds the order to database
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

            int indexO = placedOrders.findElement(orderName);
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

                int indexP = products.findElement(productName);
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

                int indexS = services.findElement(serviceName);
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

                int indexC = customers.findElement(customerID);
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
                products.add(product);  // adds the product to database
            }
            else if (choice == "service")
            {
                cout << "Enter service name, service type, service hourly rate and service hours" << endl;
                string sName, sType, sHourlyRateString;
                int sHours;
                cin >> sName >> sType >> sHourlyRateString >> sHours;
                double sHourlyRate = stod(sHourlyRateString); // string to double function
                Service service = Service(sName, sType, sHourlyRate, sHours);
                services.add(service);  // adds the service to database
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
                int indexP = products.findElement(find);
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
                    cin >> name;
                    p.setName(name);
                }
                else if (option == 2)
                {
                    cout << "Enter proper type:" << endl;
                    string type;
                    cin >> type;
                    p.setType(type);
                }
                else if (option == 3)
                {
                    cout << "Enter proper price:" << endl;
                    double price;
                    cin >> price;
                    p.setPrice(price);
                }



            }
            else if (choice == "service")
            {
                cout << "Enter Service name to be edited" << endl;
                string find;
                cin >> find;

                //find the product with the corresponding name
                int indexS = services.findElement(find);
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
                    cin >> name;
                    s.setName(name);
                }
                else if (option == 2)
                {
                    cout << "Enter proper type:" << endl;
                    string type;
                    cin >> type;
                    s.setType(type);
                }
                else if (option == 3)
                {
                    cout << "Enter proper hourly rate:" << endl;
                    double hourlyRate;
                    cin >> hourlyRate;
                    s.setRate(hourlyRate);
                }
                else if (option == 4)
                {
                    cout << "Enter proper number of hours" << endl;
                    int hours;
                    cin >> hours;
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
                cin >> name;

                int indexP = products.findElement(name);
                if (indexP < 0) {    // negative index; not found
                    break;
                }
                if (products.remove(indexP)) { // removes the Product
                }
                else {
                    throw std::invalid_argument("invalid removal of data at index: " + indexP);
                }
            }
            else if (choice == "service")
            {
                cout << "Enter service name:" << endl;
                string name;
                cin >> name;

                int indexS = services.findElement(name);
                if (indexS < 0) {    // negative index; not found
                    break;
                }
                if (services.remove(indexS)) { // removes the Service
                }
                else {
                    throw std::invalid_argument("invalid removal of data at index: " + indexS);
                }
            }


        }
        else if (option == 8)
        {
            cout << "Enter the id of the customer to be edited:" << endl;
            string customerID;
            cin >> customerID;

            int indexC = customers.findElement(customerID);
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

void loadExampleCustomers(CustomerDB customers) {
    // add to Customer Database and the text file
    for (int i = 0; i < 100; i++) {
        string un = "username" + to_string(i);
        string pw = "password" + to_string(i);
        string name = "Alexander" + to_string(i);
        Address ad1 = Address(to_string(i) + "1234 Road rd", "Naperville", "IL", "60540", "USA");
        Address ad2 = Address(to_string(i) + "4321 Lane ln", "Naperville", "IL", "60540", "USA");
        PhoneNumber ph = PhoneNumber("1234567890");
        Account acc = Account(name, ad1, ad2, ph);
        Customer newCust = Customer(un, pw, acc, "c" + to_string(i), "residential");
        customers.add(newCust);
    }
}

void loadExampleSales(SalesDB sales) {
    // add to Sales Database and the text file; uncomment and run once if you do not have the text file
    for (int i = 0; i < 100; i++) {
        string un = "susername" + to_string(i);
        string pw = "spassword" + to_string(i);
        string name = "Kiko" + to_string(i);
        Address ad1 = Address(to_string(i) + "1234 Road rd", "Naperville", "IL", "60540", "USA");
        Address ad2 = Address(to_string(i) + "4321 Lane ln", "Naperville", "IL", "60540", "USA");
        PhoneNumber ph = PhoneNumber("1234567890");
        Account acc = Account(name, ad1, ad2, ph);
        Sales newSales = Sales(un, pw, acc, "s" + to_string(i));
        sales.add(newSales);
    }
}

void loadExampleManagers(ManagerDB managers) {
    // add to Manager Database and the text file; uncomment and run once if you do not have the text file
    for (int i = 0; i < 100; i++) {
        string un = "musername" + to_string(i);
        string pw = "mpassword" + to_string(i);
        string name = "Logan" + to_string(i);
        Address ad1 = Address(to_string(i) + "1234 Road rd", "Naperville", "IL", "60540", "USA");
        Address ad2 = Address(to_string(i) + "4321 Lane ln", "Naperville", "IL", "60540", "USA");
        PhoneNumber ph = PhoneNumber("1234567890");
        Account acc = Account(name, ad1, ad2, ph);
        Manager newManager = Manager(un, pw, acc, "m" + to_string(i));
        managers.add(newManager);
    }
}

void loadExampleOrders(OrderDB orders) {
    // add to Order Database and the text file; uncomment and run once if you do not have the text file
    for (int i = 0; i < 100; i++) {
        std::string orderName = "order" + to_string(i);

        // for Product in Order
        std::string pName = "product" + to_string(i);
        std::string pType;
        double pPrice;

        if (i % 3 == 1) {   // make the product a dvr
            pType = "dvr";
            pPrice = 149.99;
        }
        else if (i % 3 == 2) {  // make the product a camera
            pType = "camera";
            pPrice = 249.79;
        }
        else {  // make the product an accessory 
            pType = "accessory";
            pPrice = 39.99;
        }
        Product p = Product(pName, pType, pPrice);

        // for Service in Order
        std::string sName = "service" + to_string(i);
        std::string sType;
        double sRate;
        double sHours;
        if (i % 3 == 1) {   // make the product a dvr
            sType = "security";
            sRate = 119.99;
            sHours = 4;
        }
        else if (i % 3 == 2) {  // make the product a camera
            sType = "surveillance";
            sRate = 79.99;
            sHours = 2;
        }
        else {  // make the product an accessory 
            sType = "theater";
            sRate = 59.99;
            sHours = 3;
        }
        Service s = Service(sName, sType, sRate, sHours);

        // for Customer in Order
        string un = "username" + to_string(i);
        string pw = "password" + to_string(i);
        string name = "Alexander" + to_string(i);
        Address ad1 = Address(to_string(i) + "1234 Road rd", "Naperville", "IL", "60540", "USA");
        Address ad2 = Address(to_string(i) + "4321 Lane ln", "Naperville", "IL", "60540", "USA");
        PhoneNumber ph = PhoneNumber("1234567890");
        Account acc = Account(name, ad1, ad2, ph);
        Customer c = Customer(un, pw, acc, "c" + to_string(i), "residential");

        // add the Order
        Order newOrder = Order(p, s, orderName, c);
        orders.add(newOrder);
    }
}

void loadExampleProducts(ProductDB products) {
    // add to Product Database and the text file; uncomment and run once if you do not have the text file
    for (int i = 0; i < 100; i++) {
        string name = "product" + to_string(i);
        string type;
        double price;
        if (i % 3 == 1) {   // make the product a dvr
            type = "dvr";
            price = 149.99;
        }
        else if (i % 3 == 2) {  // make the product a camera
            type = "camera";
            price = 249.79;
        }
        else {  // make the product an accessory 
            type = "accessory";
            price = 39.99;
        }
        Product newProduct = Product(name, type, price);
        products.add(newProduct);
    }
}

void loadExampleServices(ServiceDB services) {
    // add to Service Database and the text file; uncomment and run once if you do not have the text file
    for (int i = 0; i < 100; i++) {
        string name = "service" + to_string(i);
        string type;
        double rate;
        int hours;

        if (i % 3 == 1) {   // make the product a dvr
            type = "security";
            rate = 119.99;
            hours = 4;
        }
        else if (i % 3 == 2) {  // make the product a camera
            type = "surveillance";
            rate = 79.99;
            hours = 2;
        }
        else {  // make the product an accessory 
            type = "theater";
            rate = 59.99;
            hours = 3;
        }
        Service newService = Service(name, type, rate, hours);
        services.add(newService);
    }
}