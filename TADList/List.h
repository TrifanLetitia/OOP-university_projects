//
// Created by Leti on 28.04.2022.
//

#ifndef SOCIALNETWORK_LIST_H
#define SOCIALNETWORK_LIST_H

#include "iostream"
using namespace std;
#include <ostream>

template<class T>
class List {
public:
    T *elems;
    int capacity;
    int size;
    void resize();
public:
    /*
     * default constructor
     */
    List();
    /*
     * destructor
     */
    ~List();
    T &operator[](int index);
    /*
     * a
     */
    List<T> & operator=(const List<T>& temp);
    /*
     * return size of list
     */
    int Size();
    /*
     * add an element to the list
     */
    void add(const T& item);
    /*
     * removeElem an element from the list
     */
    void remove(int index);
    /*
     * removeElem all elements from the list
     */
    void clear();
    /*
     * get an element by index of list
     */
    T getAt(int index);
    List<T>(const List<T> &other);
    /*
     * replace an item with another item
     */
    void replace(int index, const T& item);

    bool operator==(const List<T> &e);
};

template<class T>
T &List<T>::operator[](int index) {
    return elems[index];
}


template<class T>
List<T> &List<T>::operator=(const List<T>& temp) {
    if (this != &temp) {
        delete[] this->elems;
        this->elems = new T[temp.capacity];
        this->capacity = temp.capacity;
        this->size = temp.size;
        //this->expenses = other.expenses;
        for (int i = 0; i < size; i++) {
            this->elems[i] = temp.elems[i];
        }
    }
    return *this;
}

template<class T>
int List<T>::Size() {
    return this->size;
}

template<class T>
void List<T>::add(const T& item) {
    if (size == capacity) {
        resize();
    }
    this->elems[size] = item;
    size++;
}

template<class T>
List<T>::List(const List<T> &other) {
    this->capacity = other.capacity;
    this->size = other.size;

    T * newElems = new T[capacity];

    for (int i = 0; i < other.size; i++) {
        newElems[i] = other.elems[i];
    }
    this->elems = newElems;
}

template<class T>
void List<T>::resize() {
    capacity = capacity + capacity;
    T *newElems = new T[capacity];

    for (int i = 0; i < size; i++) {
        newElems[i] = elems[i];
    }
    delete[] elems;
    elems = newElems;
}

template<class T>
List<T>::List() {
    this->capacity=10;
    this->elems = new T [capacity];
    this->size=0;
}

template<class T>
List<T>::~List() {
    delete [] elems;
}

template<class T>
void List<T>::remove(int index) {
    if (index >= size) {
        return;
    }
    for (int i = index; i < this->size - 1; i++) {
        this->elems[i] = this->elems[i + 1];
    }
    this->size--;
}

template<class T>
T List<T>::getAt(int index) {
    if(index >= 0 && index < size){
        return elems[index];
    }
}

template<class T>
void List<T>::clear() {
    delete [] elems;
    this->size = 0;
}

template<class T>
void List<T>::replace(int index, const T &item) {
    this->elems[index] = item;
}

template<class T>
bool List<T>::operator==(const List<T> &e) {
    if(this == &e)
        return true;
    for(size_t i = 0; i < size; ++i) {
        if(elems[i] != e.elems[i])
            // ^^^         ^^^
            return false;
    }
    //&& (this->size == e.size) && (this->capacity == e.capacity);
}


#endif //SOCIALNETWORK_LIST_H
