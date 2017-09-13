//
// Created by argshub on 8/23/2017.
//

#include "IndexOutOfRange.h"

#ifndef CPP_BITARRAY_H
#define CPP_BITARRAY_H

class BitArray {
    private:
        int *_array;
        int _capacity, _size;
    public:
        BitArray(int capacity);
        void setBit(int index) throw(IndexOutOfRange);
        void clearBit(int index) throw(IndexOutOfRange);
        bool testBit(int index) throw(IndexOutOfRange);
};

BitArray::BitArray(int capacity) {
    _capacity = capacity;
    _size = capacity / 32 + 1;
    _array = new int[_size];
    for (int i = 0; i < _size; ++i) _array[i] = 0;
}

void BitArray::setBit(int index) throw(IndexOutOfRange) {
    if(index >= _capacity) throw IndexOutOfRange("index out of range", _capacity);
    _array[index / 32] |= (1 << (index % 32));
}

void BitArray::clearBit(int index) throw(IndexOutOfRange) {
    if(index >= _capacity) throw IndexOutOfRange("index out of range", _capacity);
    _array[index / 32] &= ~(1 << (index % 32));
}

bool BitArray::testBit(int index) throw(IndexOutOfRange) {
    if(index >= _capacity) throw IndexOutOfRange("index out of range", _capacity);
    return _array[index / 32] & (1 << (index % 32));
}



#endif //CPP_BITARRAY_H
