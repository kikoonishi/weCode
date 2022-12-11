// OrderDB.cpp
#include "OrderDB.h"

OrderDB::OrderDB(int newSize, std::string fname) {
    maxlength = newSize;
    size = 0;
    filename = fname;
    data[maxlength];
}

OrderDB::~OrderDB() {
    delete[] data;  // deletes the contents of the database
}

void OrderDB::resize() {
    //resize the array so it can accomodate more data
    //predondition - size of the array == size of the data
    //postcondition - new array that's twice the size

    //get a new temp array
    Order* temp = new Order[maxlength * 2];
    for (int i = 0; i < maxlength; i++) {
        temp[i] = data[i];
    }
    data = temp;//pointing to the new array
    maxlength *= 2;
}

bool OrderDB::needtoresize() {
    //return if the data is equal to the array length
    return maxlength == size;
}

int OrderDB::getSize() const {
    return size;
}

int OrderDB::findElement(std::string name) const {
    if (getSize() == 0) {   // empty Database
        return -1;
    }
    else {  // there is at least one element in the Database
        for (int i = 0; i < getSize(); data) {
            if (data[i].getOrderName() == name) { // if ID (Customer, Sales, Manager) or name (Order, Product, Service) are equal
                return i;
            }
        }
    }
    return -1;  // element not found
}

Order OrderDB::get(int index) const {
    if (index < size && index >= 0) {   // valid index
        return data[index];
    }
    else {
        throw std::invalid_argument("cannot pass a negative index");
    }
}

bool OrderDB::isEqual(Order first, Order second) {
    if (first.getOrderName() == second.getOrderName()) {
        return true;
    }
    return false;
}

void OrderDB::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << data[i].toString() << std::endl;
    }
}

void OrderDB::addToData(Order newElement) {
    // add the element into the list
    if (needtoresize()) {
        resize();
    }
    data[size] = newElement;
    size++;
}

void OrderDB::add(Order newElement) {
    // add the element into the list
    if (needtoresize()) {
        resize();
    }
    // add the new element into the Database file
    std::ofstream dbfile;
    dbfile.open(filename, std::ios_base::app);  // opens the file in append mode

    // add the contents of the newElement to the file
    if (size == 0) {
        dbfile << "Order" << std::endl;    // writes the type to the file
    }

    // write order name to file
    dbfile << newElement.getOrderName();

    // write Product to file
    dbfile << newElement.getProduct().getName();
    dbfile << newElement.getProduct().getType();
    dbfile << newElement.getProduct().getPrice();

    // write Service to file
    dbfile << newElement.getService().getName();
    dbfile << newElement.getService().getType();
    dbfile << newElement.getService().getRate();
    dbfile << newElement.getService().getHours();

    // write Customer to file
    dbfile << newElement.getCustomer().getCustomerID();   // writes ID value to file
    dbfile << newElement.getCustomer().getCustomerType(); // writes type value to file

    dbfile << newElement.getCustomer().getUsername(); // writes Customer username to file
    dbfile << newElement.getCustomer().getPassword(); // writes Customer password to file

    dbfile << newElement.getCustomer().getAccount().getName();    // writes Customer Account name to file
    dbfile << newElement.getCustomer().getAccount().getAddress1().toString(); // writes Account Address 1 to file
    dbfile << newElement.getCustomer().getAccount().getAddress2().toString(); // writes Account Address 2 to file
    dbfile << newElement.getCustomer().getAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file

    dbfile << std::endl;
    dbfile.close();

    data[size] = newElement;
    size++;
}

bool OrderDB::remove(Order element) {       // not complete yet
    // remove the element from the list
    for (int i = 0; i < getSize(); i++) {
        if (isEqual(data[i], element)) {    // the element was found
            //data.std::remove(0, getSize() - 1, data[i]);    // removes data[i]
            size--;
            return true;
        }
    }

    // copy contents of data into a temp array
    Customer* temp = new Customer[getSize() - 1];

    // rewrite the Database file
    std::ofstream dbfile;
    dbfile.open(filename);

    dbfile.close();
}

void OrderDB::loadFromFile() {
    // open the file
    std::ifstream dbfile(filename);
    std::string fileDataType;   // holds the type of the objects stored in the file
    std::getline(dbfile, fileDataType);

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
    while (std::getline(dbfile, line)) { // read each line of the file, until end of the file
        std::ifstream linefile(line);

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
        ph = PhoneNumber(phoneNumber);  // loaded the PhoneNumber
        addr1 = Address(sa1number + sa1name + sa1label, city1, state1, areaCode1, country1);    // loaded the Address 1
        addr2 = Address(sa2number + sa2name + sa2label, city2, state2, areaCode2, country2);    // loaded the Address 2
        acc = Account(accountName, addr1, addr2, ph);
        c = Customer(username, password, acc, customerID, customerType);

        // create the new Product and new Service for the Order
        p = Product(pName, pType, pPrice);
        s = Service(sName, sType, sRate, sHours);

        // create the new Order and add to the database
        o = Order(p, s, orderName, c);
        addToData(o);
    }
    dbfile.close(); // close the file
}

std::string OrderDB::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data[i].toString() + "\n";
    }
    return toString;
}