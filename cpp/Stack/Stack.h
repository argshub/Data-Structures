//
// Created by argshub on 8/22/2017.
//

#include "StackExceptions.h"
#ifndef CPP_STACK_H
#define CPP_STACK_H

template <typename T>
class Stack {
    private:
        T *_stk;
        int _capacity;
        int _size;
    public:
        Stack(int capacity = 20);
        ~Stack();
        void push(const T &element) throw(StackOverflow);
        const T &top() throw(StackEmpty);
        void pop() throw (StackEmpty);
};

template <typename T>
Stack<T>::Stack(int capacity) {
    _capacity = capacity;
    _size = 0;
    _stk = new T[_capacity];
}

template <typename T>
void Stack<T>::push(const T &element) throw (StackOverflow) {
    if(_size >= _capacity) throw StackOverflow("stack is overflow", _capacity);
    *(_stk+_size++) = element;
}

template <typename T>
const T &Stack<T>::top() throw(StackEmpty) {
    if(_size == 0) throw StackEmpty("Stack is empty", _size);
    return *(_stk+(_size - 1));
}

template <typename T>
void Stack<T>::pop() throw (StackEmpty) {
    if(_size == 0) throw StackEmpty("stack is empty", _size);
    _size--;
}

template <typename T>
Stack<T>::~Stack() {
    delete [] _stk;
}

#endif //CPP_STACK_H
