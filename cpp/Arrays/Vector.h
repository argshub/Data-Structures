//
// Created by argshub on 8/23/2017.
//

#include "IndexOutOfRange.h"
#ifndef CPP_VECTOR_H
#define CPP_VECTOR_H


template <typename T>
class Vector {
    private:
        T *_vec;
        int _capacity;

    public:
        Vector(int capacity = 20);
        ~Vector();
        T &operator[](int index);
        void reserve(int &capacity);
        const int getCapacity() const { return _capacity; }

};

template <typename T>
Vector<T>::Vector(int capacity) {
    _capacity = capacity;
    _vec = new T[_capacity];
}

template <typename T>
T &Vector<T>::operator[](int index) {
    if(index >= _capacity) this->reserve(_capacity);
    return *(_vec+index);
}

template <typename T>
Vector<T>::~Vector() {
    delete [] _vec;
}

template <typename T>
void Vector<T>::reserve(int &capacity) {
    T *_rese = new T[_capacity+capacity];
    for (int i = 0; i < _capacity; ++i) _rese[i] = _vec[i];
    _capacity += capacity;
    delete [] _vec;
    _vec = _rese;
}

#endif //CPP_VECTOR_H
