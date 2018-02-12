/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   array.h
 * Author: argshub
 *
 * Created on February 12, 2018, 9:19 PM
 */

#include "exceptions.h"

#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
    private:
        T *_array_of_data;
        int _capacity;
    public:
        Array(int capacity);
        Array(): Array(20) {}
        T &operator[](int index) throw (IndexOutOfRange);
        ~Array();
};

// Array Definition
template <typename T>
Array<T>::Array(int capacity) {
    this->_capacity = capacity;
    this->_array_of_data = new T[this->_capacity];
}

template <typename T>
Array<T>::~Array() {
    delete [] this->_array_of_data;
}

template <typename T>
T &Array<T>::operator[](int index) throw (IndexOutOfRange) {
    if(index >= this->_capacity) throw IndexOutOfRange("Index Out Of Range", this->_capacity);
    return *(this->_array_of_data+index);
}

#endif /* ARRAY_H */

