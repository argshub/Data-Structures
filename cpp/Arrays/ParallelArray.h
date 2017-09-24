//
// Created by argshub on 9/24/2017.
//
#include "ArrayOverflow.h"
#ifndef CPP_PARALLELARRAY_H
#define CPP_PARALLELARRAY_H

template<typename first, typename second, typename third>
class ParallelArray {
private:
    int _capacity;
    first *_firstArray;
    second *_secondArray;
    third *_thirdArray;
    int _size;
public:
    ParallelArray(int capacity = 10);
    void insert(first firstElement, second secondElement, third thirdElement) throw(ArrayOverflow);
    void echo();
};

template <typename first, typename second, typename third>
ParallelArray<first, second, third>::ParallelArray(int capacity) {
    _capacity = capacity;
    _firstArray = new first[_capacity];
    _secondArray = new second[_capacity];
    _thirdArray = new third[_capacity];
    _size = 0;
}

template <typename first, typename second, typename third>
void ParallelArray<first, second, third>::insert(first firstElement, second secondElement, third thirdElement) throw(ArrayOverflow) {
    if(_size >= _capacity) throw ArrayOverflow("array is overflow", _capacity);
    *(_firstArray+_size) = firstElement;
    *(_secondArray+_size) = secondElement;
   *(_thirdArray+_size) = thirdElement;
    _size++;
}

template <typename first, typename second, typename third>
void ParallelArray<first, second, third>::echo() {
    for (register int i = 0; i < _size; ++i)
        std::cout << "first: " << *(_firstArray+i) << "\tsecond: " << *(_secondArray+i) << "\tthird: " << *(_thirdArray+i) << '\n';
}


#endif //CPP_PARALLELARRAY_H
