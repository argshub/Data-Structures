/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bit_array.h
 * Author: argshub
 *
 * Created on February 16, 2018, 3:40 PM
 */

#include "exceptions.h"

#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

class BitArray {
private:
    int *_arrayOfData;
    int _capacity;
    int _arraySize;
public:
    BitArray(int capacity);
    BitArray(): BitArray(64) {}
    void setBit(int index) throw (IndexOutOfRange);
    void clearBit(int index) throw (IndexOutOfRange);
    bool checkBit(int index) throw(IndexOutOfRange);
    ~BitArray() { delete [] this->_arrayOfData; }
};


// Bit Definition

BitArray::BitArray(int capacity) {
    this->_capacity = capacity;
    this->_arraySize = this->_capacity / 32 + 1;
    this->_arrayOfData = new int[this->_arraySize];
    for(int i = 0; i < this->_arraySize; i++) *(this->_arrayOfData+i) = 0;
}

void BitArray::setBit(int index) throw (IndexOutOfRange) {
    if(index >= this->_capacity) throw IndexOutOfRange("Index Out Of Range", this->_capacity);
    *(this->_arrayOfData+(index / 32)) |= (1 << (index % 32));
}

void BitArray::clearBit(int index) throw (IndexOutOfRange) {
    if(index >= this->_capacity) throw IndexOutOfRange("Index Out Of Range", this->_capacity);
    *(this->_arrayOfData+(index / 32)) &= ~(1 << (index % 32));
}

bool BitArray::checkBit(int index) throw (IndexOutOfRange) {
    if(index >= this->_capacity) throw IndexOutOfRange("Index Out Of range", this->_capacity);
    return *(this->_arrayOfData+(index / 32)) & (1 << (index % 32));
}

#endif /* BIT_ARRAY_H */

