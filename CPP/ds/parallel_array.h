/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "exceptions.h"
/* 
 * File:   parallel_array.h
 * Author: argshub
 *
 * Created on February 16, 2018, 8:47 PM
 */

#ifndef PARALLEL_ARRAY_H
#define PARALLEL_ARRAY_H

template <typename A, typename B, typename C>
class ParallelArray {
    private:
        int _capacity;
        A *_firstArray;
        B *_secondArray;
        C *_thirdArray;
    public:
        ParallelArray(int capacity);
        void atIndex(int index, A first, B second, C third) throw (IndexOutOfRange);
        void atIndex(int index) throw (IndexOutOfRange);
        ~ParallelArray();
};

template <typename A, typename B, typename C>
ParallelArray<A, B, C>::ParallelArray(int capacity) {
    this->_capacity = capacity;
    this->_firstArray = new A[this->_capacity];
    this->_secondArray = new B[this->_capacity];
    this->_thirdArray = new C[this->_capacity];
}

template <typename A, typename B, typename C>
ParallelArray<A, B, C>::~ParallelArray() {
    delete [] _firstArray;
    delete [] _secondArray;
    delete [] _thirdArray;
}


template <typename A, typename B, typename C>
void ParallelArray<A, B, C>::atIndex(int index, A first, B second, C third) throw(IndexOutOfRange) {
    if(index >= this->_capacity) throw IndexOutOfRange("Index out of Range", this->_capacity);
    this->_firstArray[index] = first;
    this->_secondArray[index] = second;
    this->_thirdArray[index] = third;
}

template <typename A, typename B, typename C>
void ParallelArray<A, B, C>::atIndex(int index) throw (IndexOutOfRange) {
    if(index >= this->_capacity) throw IndexOutOfRange("Index out of Range", this->_capacity);
    cout << "First: " << this->_firstArray[index] << " Second: " << this->_secondArray[index] << " Third: " << this->_thirdArray[index] << "\n";
}

#endif /* PARALLEL_ARRAY_H */

