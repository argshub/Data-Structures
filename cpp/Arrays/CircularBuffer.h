//
// Created by argshub on 10/8/2017.
//

#ifndef CPP_CIRCULARBUFFER_H_H
#define CPP_CIRCULARBUFFER_H_H

#include "CircularBufferException.h"
template <typename T>
class CircularBuffer {
private:
    T *_data;
    int _capacity, _front, _count;
public:
    CircularBuffer(int capacity = 10);
    void put(const T &element) throw(BufferOverflow);
    const T get() throw(BufferEmptyException);
    ~CircularBuffer();
};

template <typename T>
const T CircularBuffer<T>::get() throw(BufferEmptyException) {
    if(_count == 0) throw BufferEmptyException("Buffer in Empty");
    T _clearData = *(_data+_front);
    _front = ++_front == _capacity ? 0 : _front;
    _count--;
    return _clearData;

}

template <typename T>
void CircularBuffer<T>::put(const T &element) throw(BufferOverflow) {
    if(_count == _capacity) throw BufferOverflow("Buffer Overflow", _capacity);
    *(_data+((_front + _count++) % _capacity)) = element;
}

template <typename T>
CircularBuffer<T>::CircularBuffer(int capacity) {
    _capacity = capacity;
    _data = new T[_capacity];
    _front = _count = 0;
}

template <typename T>
CircularBuffer<T>::~CircularBuffer() {
    delete [] _data;
}

#endif //CPP_CIRCULARBUFFER_H_H
