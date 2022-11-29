//Database.cpp

#include <string>
#include "Database.h"

template <class T>
void Database<T>::resize(){
    //resize the array so it can accomodate more data
    //predondition - size of the array == size of the data
    //postcondition - new array that's twice the size

    //get a new temp array
    T *temp = new T[arraylength * 2];
    for (int i= 0; i<arraylength; i++){
        temp[i] = data[i];
    }
    data = temp;//pointing to the new array
    arraylength *= 2;
}

template <class T>
bool Database<T>::needtoresize(){
    //return if the data is equal to the array length
    return arraylength == listsize;
}

template <class T>
void Database<T>::add(T item){
    //add the item to the end of the list

    //check to see if theres enough space
    if(needtoresize())
        resize();
    data[listsize] = item;//add item to the end
    listsize++;//increment listsize
}

template <class T>
void Database<T>::insert(int index, T item){
    if (needtoresize())
        resize();
    
    for (int i=listsize; i>= index; i--){
        data[listsize+1] = data[listsize];
    }
    data[index] = item;
    listsize++;
}

//delete element based on index
template <class T>
void Database<T>::deleteElement(int index){

}

//delete element based on item
template <class T>
void Database<T>::deleteElement(T item){

}

//get specific item by value in it
template<class T>
T Database<T>::getElement(std::string){

}

//get specific item by index
template<class T>
T Database<T>::getElement(int index){

}

