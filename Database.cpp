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
            if (data[i] == element) {
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
            if (first.customer_id == second.customer_id) {  // check if Customer IDs are the same
                if (first.customer_type == second.customer_type) {  // check if the same type of Customer (residential, business, government)
                    if ()
                }
            }
        }
        else if (decltype(first) == decltype(Sales<T>)) {  // compare Sales

        }
        else if (decltype(first) == decltype(Manager<T>)) {    // compare Manager

        }
        else if (decltype(first) == decltype(Order)) {  // compare Order

        }
        else if (decltype(first) == decltype(Product)) {    // compare Product

        }
        else if (decltype(first) == decltype(Service)) {    // compare Service
            
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

        dbfile << newElement.getCustomerAccount().getName();    // writes Customer Account name to file
        dbfile << newElement.getCustomerAccount().getAddress1().toString(); // writes Account Address 1 to file
        dbfile << newElement.getCustomerAccount().getAddress2().toString(); // writes Account Address 2 to file
        dbfile << newElement.getCustomerAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file
    }
    else if (decltype(newElement) == decltype(Sales<T>)) {  // if Sales
        dbfile << newElement.getCustomerID();   // writes ID value to file
        dbfile << newElement.getCustomerType(); // writes type value to file

        dbfile << newElement.getCustomerAccount().getName();    // writes Sales Account name to file
        dbfile << newElement.getCustomerAccount().getAddress1().toString(); // writes Account Address 1 to file
        dbfile << newElement.getCustomerAccount().getAddress2().toString(); // writes Account Address 2 to file
        dbfile << newElement.getCustomerAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file
    }
    else if (decltype(newElement) == decltype(Manager<T>)) {    // if Manager
        dbfile << newElement.getCustomerID();   // writes ID value to file
        dbfile << newElement.getCustomerType(); // writes type value to file

        dbfile << newElement.getCustomerAccount().getName();    // writes Manager Account name to file
        dbfile << newElement.getCustomerAccount().getAddress1().toString(); // writes Account Address 1 to file
        dbfile << newElement.getCustomerAccount().getAddress2().toString(); // writes Account Address 2 to file
        dbfile << newElement.getCustomerAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file
    }
    else if (decltype(newElement) == decltype(Order)) {
        // write Product to file
        dbfile << newElement.getName();
        dbfile << newElement.getType();     // not implemented in Product.h
        dbfile << newElement.getPrice();

        // write Service to file
        dbfile << newElement.getName();
        dbfile << newElement.getType();     // not implemented in Service.h
        dbfile << newElement.getRate();
        dbfile << newElement.getHours();

        // write order name to file
        dbfile << newElement.getOrderName();

        // write Customer to file
        //  getCustomer() not implemented in Order.h
        dbfile << newElement.getCustomer().getCustomerID();   // writes ID value to file
        dbfile << newElement.getCustomer().getCustomerType(); // writes type value to file

        dbfile << newElement.getCustomer().getCustomerAccount().getName();    // writes Customer Account name to file
        dbfile << newElement.getCustomer().getCustomerAccount().getAddress1().toString(); // writes Account Address 1 to file
        dbfile << newElement.getCustomer().getCustomerAccount().getAddress2().toString(); // writes Account Address 2 to file
        dbfile << newElement.getCustomer().getCustomerAccount().getPhoneNumber().getPhoneNumber();    // writes Account Phone Number to file
    }
    else if (decltype(newElement) == decltype(Product)) {
        dbfile << newElement.getName();
        dbfile << newElement.getType();     // not implemented in Product.h
        dbfile << newElement.getPrice();
    }
    else if (decltype(newElement) == decltype(Service)) {
        dbfile << newElement.getName();
        dbfile << newElement.getType();     // not implemented in Service.h
        dbfile << newElement.getRate();
        dbfile << newElement.getHours();
    }
    dbfile << std::endl;
    dbfile.close();

    data[size] = newElement;
    size++;
}

template <class T>
void Database<T>::remove(T element) {
    // remove the element from the list
    for (int i = 0; i < getSize(); i++) {
        if (isEqual(data[i], element)) {
            data[i] = nullptr;
            size--;
        }
    }
    // rewrite the Database file
    std::ofstream dbfile(filename);
    for (int i = 0; i < getSize(); i++) {
        dbfile << data[i].firstname;
        dbfile << data[i].lastname;
        dbfile << data[i].type;
        dbfile << std::endl;
    }
    dbfile.close();
}

template <class T>
void Database<T>::loadFromFile(std::string fname) {
    // open the file
    std::ifstream dbfile(fname);
    std::string fileDataType;   // holds the type of the objects stored in the file
    dbfile >> fileDataType;

    while (!dbfile.eof()) { // not at the end of the file
        if (fileDataType == "User") {
            // loadUserDB();
        } 
        else if (fileDataType == "Order") {
            // loadOrderDB();
        }
        else if (fileDataType == "Product") {
            // loadOrderDB();
        }
        else if (fileDataType == "Service") {
            // loadServiceDB();
        }
        
    }
    dbfile.close();
}

template <class T>
void Database<T>::loadUserDB() {

}

template <class T>
void Database<T>::loadOrderDB() {

}

template <class T>
void Database<T>::loadProductDB() {

}

template <class T>
void Database<T>::loadServiceDB() {

}

template <class T>
std::string Database<T>::toString() {
    std::string toString = "";
    for (int i = 0; i < getSize(); i++) {
        toString += data[i].toString() + "\n";
    }
    return toString;
}
