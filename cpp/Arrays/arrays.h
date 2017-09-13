//
// Created by argshub on 8/21/2017.
//
#include "IndexOutOfRange.h"

#ifndef CPP_ARRAY_H
#define CPP_ARRAY_H

template <typename T>
class array {
    private:
        T *_arr;
        int _capacity;
    public:
        array(int capacity = 20);
        T &operator[](int index) throw(IndexOutOfRange);
        ~array();
};

template <typename T>
array<T>::array(int capacity) {
    _capacity = capacity;
    _arr = new T[_capacity];
}

template <typename T>
T& array<T>::operator[](int index) throw(IndexOutOfRange) {
    if(index >= _capacity) throw IndexOutOfRange("index out of range", _capacity);
    return *(_arr+index);
}

template <typename T>
array<T>::~array() {
    delete [] _arr;
}

#endif //CPP_ARRAY_H
