// ProductDB.cpp
#include "ProductDB.h"

ProductDB::ProductDB(int newSize, std::string fname) {
    maxlength = newSize;
    size = 0;
    filename = fname;
    data[maxlength];
}

ProductDB::~ProductDB() {
    delete[] data;  // deletes the contents of the database
}

void ProductDB::resize() {
    //resize the array so it can accomodate more data
    //predondition - size of the array == size of the data
    //postcondition - new array that's twice the size

    //get a new temp array
    Product* temp = new Product[maxlength * 2];
    for (int i = 0; i < maxlength; i++) {
        temp[i] = data[i];
    }
    data = temp;//pointing to the new array
    maxlength *= 2;
}

bool ProductDB::needtoresize() {
    //return if the data is equal to the array length
    return maxlength == size;
}

int ProductDB::getSize() const {
    return size;
}

int ProductDB::findElement(std::string name) const {
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

Product ProductDB::get(int index) const {
    if (index < size && index >= 0) {   // valid index
        return data[index];
    }
    else {
        throw std::invalid_argument("cannot pass a negative index");
    }
}

bool ProductDB::isEqual(Product first, Product second) {
    if (first.getName() == second.getName()) {
        return true;
    }
    return false;
}

void ProductDB::print() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << data[i].toString() << std::endl;
    }
}

void ProductDB::addToData(Product newElement) {
    // add the element into the list
    if (needtoresize()) {
        resize();
    }
    data[size] = newElement;
    size++;
}

void ProductDB::add(Product newElement) {
    // add the element into the list
    if (needtoresize()) {
        resize();
    }
    // add the new element into the Database file
    std::ofstream dbfile;
    dbfile.open(filename, std::ios_base::app);  // opens the file in append mode

    // add the contents of the newElement to the file
    if (size == 0) {
        dbfile << "Product" << std::endl;    // writes the type to the file
    }

    // write Product to file
    dbfile << newElement.getName();
    dbfile << newElement.getType();
    dbfile << newElement.getPrice();

    dbfile << std::endl;
    dbfile.close();

    data[size] = newElement;
    size++;
}

bool ProductDB::remove(Product element) {       // not complete yet
    // remove the element from the list
    for (int i = 0; i < getSize(); i++) {
        if (isEqual(data[i], element)) {    // the element was found
            //data.std::remove(0, getSize() - 1, data[i]);    // removes data[i]
            size--;
            return true;
        }
    }

    // copy contents of data into a temp array
    Product* temp = new Product[getSize() - 1];

    // rewrite the Database file
    std::ofstream dbfile;
    dbfile.open(filename);

    dbfile.close();
}

void ProductDB::loadFromFile() {
    // open the file
    std::ifstream dbfile(filename);
    std::string fileDataType;   // holds the type of the objects stored in the file
    std::getline(dbfile, fileDataType);

    // Product attributes
    std::string name;
    std::string type;
    double price;

    Product p;  // the new Product to be added

    // reading the contents of the file
    std::string line;
    while (std::getline(dbfile, line)) {    // read lines until end of the file
        std::ifstream linefile(line);

        // read the contents for Product
        linefile >> name;
        linefile >> type;
        linefile >> price;

        // create the new Product and add to the database
        p = Product(name, type, price);
    }
    dbfile.close(); // closes the file
}

std::string ProductDB::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data[i].toString() + "\n";
    }
    return toString;
}