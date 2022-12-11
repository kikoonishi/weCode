// ServiceDB.cpp
#include "ServiceDB.h"

ServiceDB::ServiceDB(int newSize, std::string fname) {
    maxlength = newSize;
    size = 0;
    filename = fname;
    data[maxlength];
}

ServiceDB::~ServiceDB() {
    delete[] data;  // deletes the contents of the database
}

void ServiceDB::resize() {
    //resize the array so it can accomodate more data
    //predondition - size of the array == size of the data
    //postcondition - new array that's twice the size

    //get a new temp array
    Service* temp = new Service[maxlength * 2];
    for (int i = 0; i < maxlength; i++) {
        temp[i] = data[i];
    }
    data = temp;//pointing to the new array
    maxlength *= 2;
}

bool ServiceDB::needtoresize() {
    //return if the data is equal to the array length
    return maxlength == size;
}

int ServiceDB::getSize() const {
    return size;
}

int ServiceDB::findElement(std::string name) const {
    if (getSize() == 0) {   // empty Database
        return -1;
    }
    else {  // there is at least one element in the Database
        for (int i = 0; i < getSize(); data) {
            if (data[i].getName() == name) { // if ID (Customer, Sales, Manager) or name (Order, Product, Service) are equal
                return i;
            }
        }
    }
    return -1;  // element not found
}

Service ServiceDB::get(int index) const {
    if (index < size && index >= 0) {   // valid index
        return data[index];
    }
    else {
        throw std::invalid_argument("cannot pass a negative index");
    }
}

bool ServiceDB::isEqual(Service first, Service second) {
    if (first.getName() == second.getName()) {
        return true;
    }
    return false;
}

void ServiceDB::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << data[i].toString() << std::endl;
    }
}

void ServiceDB::addToData(Service newElement) {
    // add the element into the list
    if (needtoresize()) {
        resize();
    }
    data[size] = newElement;
    size++;
}

void ServiceDB::add(Service newElement) {
    // add the element into the list
    if (needtoresize()) {
        resize();
    }
    // add the new element into the Database file
    std::ofstream dbfile;
    dbfile.open(filename, std::ios_base::app);  // opens the file in append mode

    // add the contents of the newElement to the file
    if (size == 0) {
        dbfile << "Service" << std::endl;    // writes the type to the file
    }

    // write the Service to the file
    dbfile << newElement.getName();
    dbfile << newElement.getType();
    dbfile << newElement.getRate();
    dbfile << newElement.getHours();

    dbfile << std::endl;
    dbfile.close();

    data[size] = newElement;
    size++;
}

bool ServiceDB::remove(Service element) {       // not complete yet
    // remove the element from the list
    for (int i = 0; i < getSize(); i++) {
        if (isEqual(data[i], element)) {    // the element was found
            //data.std::remove(0, getSize() - 1, data[i]);    // removes data[i]
            size--;
            return true;
        }
    }

    // copy contents of data into a temp array
    Service* temp = new Service[getSize() - 1];

    // rewrite the Database file
    std::ofstream dbfile;
    dbfile.open(filename);

    dbfile.close();
}

void ServiceDB::loadFromFile() {
    // open the file
    std::ifstream dbfile(filename);
    std::string fileDataType;   // holds the type of the objects stored in the file
    std::getline(dbfile, fileDataType);

    // Service attributes
    std::string name;
    std::string type;
    double rate;
    double hours;

    Service s;  // the new Service to be added

    // reading the contents of the file
    std::string line;
    while (std::getline(dbfile, line)) {    // read lines until end of the file
        std::ifstream linefile(line);

        // read the contents for Service
        linefile >> name;
        linefile >> type;
        linefile >> rate;
        linefile >> hours;

        // create the new Service and add to the database
        s = Service(name, type, rate, hours);
    }
    dbfile.close(); // closes the file
}

std::string ServiceDB::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data[i].toString() + "\n";
    }
    return toString;
}