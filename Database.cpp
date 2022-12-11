// Database.cpp
#include "Database.h"

template <class T>
Database<T>::Database(int newSize, std::string fname) {
    maxlength = newSize;
    size = 0;
    filename = fname;
    data = new T[maxlength];
}

template <class T>
Database<T>::~Database() {
    delete[] data;  // deletes the contents of the database
}

template <class T>
void Database<T>::resize() {
    //resize the array so it can accomodate more data
    //predondition - size of the array == size of the data
    //postcondition - new array that's twice the size

    //get a new temp array
    T* temp = new T[maxlength * 2];
    for (int i = 0; i < maxlength; i++) {
        temp[i] = data[i];
    }
    data = temp;//pointing to the new array
    maxlength *= 2;
}

template <class T>
bool Database<T>::needtoresize() {
    //return if the data is equal to the array length
    return maxlength == size;
}

template <class T>
int Database<T>::getSize() const {
    return size;
}

template <class T>
int Database<T>::findElement(T element) const {
    if (getSize() == 0) {   // empty Database
        return -1;
    }
    else {  // there is at least one element in the Database
        for (int i = 0; i < getSize(); data) {
            if (isEqual(data[i], element) { // if ID (Customer, Sales, Manager) or name (Order, Product, Service) are equal
                return i;
            }
        }
    }
    return -1;  // element not found
}

template <class T>
T Database<T>::get(int index) const {
    if (index < size) {   // valid index
        return data[index];
    }
}

template <class T>
bool Database<T>::isEqual(T first, T second) {
    if (decltype(first) != decltype(second)) {  // objects of different types
        return false;
    }
    else {  // objects of same type
        // compare Customer
        if (decltype(first) == decltype(Customer)) {
            if (first.getCustomerID() == second.getCustomerID()) {  // check if Customer IDs are the same
                return true;
            }
            return false;   // different Customer ID
        }
        else if (decltype(first) == decltype(Sales)) {  // compare Sales
            if (first.getSalesID() == second.getSalesID()) {
                return true;
            }
            return false;   // different Sales ID
        }
        else if (decltype(first) == decltype(Manager)) {    // compare Manager
            if (first.getManagerID() == second.getManagerID()) {
                return true;
            }
            return false;   // different Manager ID
        }
        else if (decltype(first) == decltype(Order)) {  // compare Order
            if (first.getOrderName() == second.getOrderName()) {
                return true;
            }
            return false;   // different Order name
        }
        else if (decltype(first) == decltype(Product)) {    // compare Product
            if (first.getName() == second.getName()) {
                return true;
            }
            return false;   // different Product name
        }
        else if (decltype(first) == decltype(Service)) {    // compare Service
            if (first.getName() == second.getName()) {
                return true;
            }
            return false;   // different Service name
        }
        else {  // error
            throw std::invalid_argument("invalid comparison: " + decltype(first) + " to " + decltype(second));
        }

    }
}

template <class T>
void Database<T>::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << data[i].toString() << std::endl;
    }
}

template <class T>
void Database<T>::addToData(T element) {
    // add the element into the list
    if (needtoresize()) {
        resize();
    }
    data[size] = newElement;
    size++;
}

template <class T>
void Database<T>::add(T newElement) {
    // add the element into the list
    if (needtoresize()) {
        resize();
    }
    // add the new element into the Database file
    std::ofstream dbfile; 
    dbfile.open(filename, std::ios_base::app);  // opens the file in append mode

    // add the contents of the newElement to the file
    if (size == 0) {
        dbfile << decltype(newElement) << std::endl;    // writes the type to the file
    }

    // add each attribute value to file depending of type of newElement()
    if (decltype(newElement) == decltype(Customer)) {   // if Customer
        dbfile << newElement.getCustomerID();   // writes ID value to file
        dbfile << newElement.getCustomerType(); // writes type value to file

        dbfile << newElement.getUsername(); // writes Customer username to file
        dbfile << newElement.getPassword(); // writes Customer password to file

        dbfile << newElement.getAccount().getName();    // writes Customer Account name to file
        dbfile << newElement.getAccount().getAddress1().toString(); // writes Account Address 1 to file
        dbfile << newElement.getAccount().getAddress2().toString(); // writes Account Address 2 to file
        dbfile << newElement.getAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file
    }
    else if (decltype(newElement) == decltype(Sales)) {  // if Sales
        dbfile << newElement.getSalesID();   // writes ID value to file

        dbfile << newElement.getUsername(); // writes Sales username to file
        dbfile << newElement.getPassword(); // writes Sales password to file

        dbfile << newElement.getAccount().getName();    // writes Sales Account name to file
        dbfile << newElement.getAccount().getAddress1().toString(); // writes Account Address 1 to file
        dbfile << newElement.getAccount().getAddress2().toString(); // writes Account Address 2 to file
        dbfile << newElement.getAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file
    }
    else if (decltype(newElement) == decltype(Manager)) {    // if Manager
        dbfile << newElement.getManagerID();   // writes ID value to file

        dbfile << newElement.getUsername(); // writes Manager username to file
        dbfile << newElement.getPassword(); // writes Manager password to file

        dbfile << newElement.getAccount().getName();    // writes Manager Account name to file
        dbfile << newElement.getAccount().getAddress1().toString(); // writes Account Address 1 to file
        dbfile << newElement.getAccount().getAddress2().toString(); // writes Account Address 2 to file
        dbfile << newElement.getAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file
    }
    else if (decltype(newElement) == decltype(Order)) {
        // write order name to file
        dbfile << newElement.getOrderName();

        // write Product to file
        dbfile << newElement.getName();
        dbfile << newElement.getType();   
        dbfile << newElement.getPrice();

        // write Service to file
        dbfile << newElement.getName();
        dbfile << newElement.getType();  
        dbfile << newElement.getRate();
        dbfile << newElement.getHours();

        // write Customer to file
        dbfile << newElement.getCustomer().getCustomerID();   // writes ID value to file
        dbfile << newElement.getCustomer().getCustomerType(); // writes type value to file

        dbfile << newElement.getUsername(); // writes Customer username to file
        dbfile << newElement.getPassword(); // writes Customer password to file

        dbfile << newElement.getCustomer().getAccount().getName();    // writes Customer Account name to file
        dbfile << newElement.getCustomer().getAccount().getAddress1().toString(); // writes Account Address 1 to file
        dbfile << newElement.getCustomer().getAccount().getAddress2().toString(); // writes Account Address 2 to file
        dbfile << newElement.getCustomer().getAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file
    }
    else if (decltype(newElement) == decltype(Product)) {
        dbfile << newElement.getName();
        dbfile << newElement.getType();    
        dbfile << newElement.getPrice();
    }
    else if (decltype(newElement) == decltype(Service)) {
        dbfile << newElement.getName();
        dbfile << newElement.getType();     
        dbfile << newElement.getRate();
        dbfile << newElement.getHours();
    }
    dbfile << std::endl;
    dbfile.close();

    data[size] = newElement;
    size++;
}

template <class T>
void Database<T>::remove(T element) {   // get this working if time allows; low priority requirement
    // remove the element from the list
    for (int i = 0; i < getSize(); i++) {
        if (isEqual(data[i], element)) {
            data[i] = nullptr;
            size--;
        }
    }
    // rewrite the Database file
    //std::ofstream dbfile(filename);
    //dbfile.close();
}

template <class T>
void Database<T>::loadFromFile(std::string fname) {
    // open the file
    std::ifstream dbfile(fname);
    std::string fileDataType;   // holds the type of the objects stored in the file
    std::getline(dbfile, fileDataType);

    if (fileDataType == "User") {   // its the Database<User> file
        loadUserDB(dbfile);
    } 
    else if (fileDataType == "Order") { // its the Database<Order> file
         loadOrderDB(dbfile);
    }
    else if (fileDataType == "Product") {   // its the Database<Product> file
         loadProductDB(dbfile);
    }
    else if (fileDataType == "Service") {   // its the Database<Service> file
        loadServiceDB(dbfile);
    }
    dbfile.close(); // close the file
}

template <class T>
void Database<T>::loadUserDB(std::ifstream dbfile) {
    // User attributes
    std::string username;
    std::string password;
    std::string accountName; // for user_account
    // for Address 1 in user_account
    std::string sa1number;
    std::string sa1name;
    std::string sa1label;
    std::string city1;
    std::string state1;
    std::string areaCode1;
    std::string country1;
    // for Address 2 in user_account
    std::string sa2number;
    std::string sa2name;
    std::string sa2label;
    std::string city2;
    std::string state2;
    std::string areaCode2;
    std::string country2;

    std::string phoneNumber; // for Phone in user_account

    // objects to be created by reading from file
    Account acc;
    Address addr1;
    Address addr2;
    PhoneNumber ph;

    // check 1st char to see if Customer, Sales, or Manager ID
        // e.g. c1234 = customer_id
        // e.g. s5678 = sales_id
        // e.g. m9010 = manager_id

    std::string line;
    while (std::getline(dbfile, line) { // read each line of the file, until end of the file
        std::stringstream linefile(line);   // to parse the line from the file
        std::string id;
        dbfile >> id;   // read in the id

        if (id.at(0) == 'c') {  // customer_id
            // read contents for Customer
            Customer c;
            std::string customerType;   // customer_type attribute
            linefile >> customerType;

            // read contents for User (for Customer to inherit)
            linefile >> username;
            linefile >> password;
            linefile >> accountName;

            // read contents for Address 1
            linefile >> sa1number;
            linefile >> sa1name;
            linefile >> sa1label;
            linefile >> city1;
            linefile >> state1;
            linefile >> areaCode1;
            linefile >> country1;
            
            // read contents for Address 2
            linefile >> sa2number;
            linefile >> sa2name;
            linefile >> sa2label;
            linefile >> city2;
            linefile >> state2;
            linefile >> areaCode2;
            linefile >> country2;

            // read contents for PhoneNumber
            linefile >> phoneNumber;

            // creating the new Customer and adding to Database
            ph = new PhoneNumber(phoneNumber);  // loaded the PhoneNumber
            addr1 = new Address(sa1number + sa1name + sa1label, city1, state1, areaCode1, country1);    // loaded the Address 1
            addr2 = new Address(sa2number + sa2name + sa2label, city2, state2, areaCode2, country2);    // loaded the Address 2
            acc = new Account(accountName, addr1, addr2, ph);
            c = new Customer(username, password, acc, id, customerType);
            addToData(c);   // adds Customer to data
        }
        else if (id.at(0) == 's') { // sales_id
            Sales s;

            // read contents for User (for Sales to inherit)
            linefile >> username;
            linefile >> password;
            linefile >> accountName;

            // read contents for Address 1
            linefile >> sa1number;
            linefile >> sa1name;
            linefile >> sa1label;
            linefile >> city1;
            linefile >> state1;
            linefile >> areaCode1;
            linefile >> country1;

            // read contents for Address 2
            linefile >> sa2number;
            linefile >> sa2name;
            linefile >> sa2label;
            linefile >> city2;
            linefile >> state2;
            linefile >> areaCode2;
            linefile >> country2;

            // read contents for PhoneNumber
            linefile >> phoneNumber;

            // creating the new Sales and adding to Database
            ph = new PhoneNumber(phoneNumber);  // loaded the PhoneNumber
            addr1 = new Address(sa1number + sa1name + sa1label, city1, state1, areaCode1, country1);    // loaded the Address 1
            addr2 = new Address(sa2number + sa2name + sa2label, city2, state2, areaCode2, country2);    // loaded the Address 2
            acc = new Account(accountName, addr1, addr2, ph);
            s = new Sales(username, password, acc, id);
            addToData(s);   // adds Sales to data
        }
        else if (id.at(0) == 'm') { // manager_id
            Manager m;

            // read contents for User (for Sales to inherit)
            linefile >> username;
            linefile >> password;
            linefile >> accountName;

            // read contents for Address 1
            linefile >> sa1number;
            linefile >> sa1name;
            linefile >> sa1label;
            linefile >> city1;
            linefile >> state1;
            linefile >> areaCode1;
            linefile >> country1;

            // read contents for Address 2
            linefile >> sa2number;
            linefile >> sa2name;
            linefile >> sa2label;
            linefile >> city2;
            linefile >> state2;
            linefile >> areaCode2;
            linefile >> country2;

            // read contents for PhoneNumber
            linefile >> phoneNumber;

            // creating the new Sales and adding to Database
            ph = new PhoneNumber(phoneNumber);  // loaded the PhoneNumber
            addr1 = new Address(sa1number + sa1name + sa1label, city1, state1, areaCode1, country1);    // loaded the Address 1
            addr2 = new Address(sa2number + sa2name + sa2label, city2, state2, areaCode2, country2);    // loaded the Address 2
            acc = new Account(accountName, addr1, addr2, ph);
            m = new Manager(username, password, acc, id);
            addToData(m);   // adds Manager to data
        }
        else {  // incorrect data; error
            throw std::invalid_argument("invalid data: expected a user id");
        }
    }
}

template <class T>
void Database<T>::loadOrderDB(std::ifstream dbfile) {
    // Order attributes
    std::string orderName;

    // for Product in Order
    std::string pName;
    std::string pType;
    double pPrice; 

    // for Service in Order
    std::string sName;
    std::string sType;
    double sRate;  
    double sHours; 

    // for Customer in Order
    std::string customerID;
    std::string customerType;

    // User attributes
    std::string username;
    std::string password;
    std::string accountName; // for user_account

    // for Address 1 in user_account
    std::string sa1number;
    std::string sa1name;
    std::string sa1label;
    std::string city1;
    std::string state1;
    std::string areaCode1;
    std::string country1;

    // for Address 2 in user_account
    std::string sa2number;
    std::string sa2name;
    std::string sa2label;
    std::string city2;
    std::string state2;
    std::string areaCode2;
    std::string country2;

    std::string phoneNumber; // for Phone in user_account

    // objects to be created by reading from file
    Order o;
    Product p;
    Service s;
    Customer c;
    Account acc;
    Address addr1;
    Address addr2;
    PhoneNumber ph;

    // read the contents of the file
    std::string line;
    while (std::getline(dbfile, line) { // read each line of the file, until end of the file
        std::stringstream linefile(line);

        // read order name
        linefile >> orderName;

        // read contents for Product
        linefile >> pName;
        linefile >> pType;
        linefile >> pPrice;

        // read contents for Service
        linefile >> sName;
        linefile >> sType;
        linefile >> sRate;
        linefile >> sHours;

        // read contents for Customer
        linefile >> customerID;
        linefile >> customerType;

        // read contents for User (for Customer to inherit)
        linefile >> username;
        linefile >> password;
        linefile >> accountName;

        // read contents for Address 1
        linefile >> sa1number;
        linefile >> sa1name;
        linefile >> sa1label;
        linefile >> city1;
        linefile >> state1;
        linefile >> areaCode1;
        linefile >> country1;

        // read contents for Address 2
        linefile >> sa2number;
        linefile >> sa2name;
        linefile >> sa2label;
        linefile >> city2;
        linefile >> state2;
        linefile >> areaCode2;
        linefile >> country2;

        // read contents for PhoneNumber
        linefile >> phoneNumber;

        // create the new Customer for the Order
        ph = new PhoneNumber(phoneNumber);  // loaded the PhoneNumber
        addr1 = new Address(sa1number + sa1name + sa1label, city1, state1, areaCode1, country1);    // loaded the Address 1
        addr2 = new Address(sa2number + sa2name + sa2label, city2, state2, areaCode2, country2);    // loaded the Address 2
        acc = new Account(accountName, addr1, addr2, ph);
        c = new Customer(username, password, acc, customerID, customerType);

        // create the new Product and new Service for the Order
        p = new Product(pName, pType, pPrice);
        s = new Service(sName, sType, sRate, sHours);

        // create the new Order and add to the database
        o = new Order(p, s, orderName, c);
        addToData(o);
    }
}

template <class T>
void Database<T>::loadProductDB(std::ifstream dbfile) {
    // Product attributes
    std::string name;
    std::string type;
    double price;

    Product p;  // the new Product to be added

    // reading the contents of the file
    std::string line;
    while (std::getline(dbfile, line)) {    // read lines until end of the file
        std::stringstream linefile(line);

        // read the contents for Product
        linefile >> name;
        linefile >> type;
        linefile >> price;

        // create the new Product and add to the database
        p = new Product(name, type, price);
    }
}

template <class T>
void Database<T>::loadServiceDB(std::ifstream dbfile) {
    // Service attributes
    std::string name;
    std::string type;
    double rate;
    double hours;

    Service s;  // the new Service to be added

    // reading the contents of the file
    std::string line;
    while (std::getline(dbfile, line)) {    // read lines until end of the file
        std::stringstream linefile(line);

        // read the contents for Service
        linefile >> name;
        linefile >> type;
        linefile >> rate;
        linefile >> hours;

        // create the new Service and add to the database
        s = new Service(name, type, rate, hours);
    }
}

template <class T>
std::string Database<T>::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data[i].toString() + "\n";
    }
    return toString;
}
