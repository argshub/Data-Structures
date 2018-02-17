/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "exceptions.h"
/* 
 * File:   stack.h
 * Author: argshub
 *
 * Created on February 17, 2018, 4:30 PM
 */

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
    
    private:
        class Node;
    
    private:
        int _capacity, _count;
        Node *_top;
    
    public:
        Stack(int capacity);
        Stack(): Stack(20) {}
        void push(const T &element) throw (StackOverflow);
        const T &top() const throw (StackIsEmpty);
        void pop() throw (StackIsEmpty);
};


// Node class

template <typename T>
class Stack<T>::Node {
    private:
        T _element;
        Node *_next;
        friend class Stack;
    private:
        Node(const T &element): _element(element), _next(NULL) {}
};


// Stack Definition

template <typename T>
Stack<T>::Stack(int capacity) {
    this->_capacity = capacity;
    this->_count = 0;
    this->_top = NULL;
}

template <typename T>
void Stack<T>::push(const T& element) throw (StackOverflow) {
    if(this->_count == this->_capacity) throw StackOverflow("Stack Overflow", this->_capacity);
    Node *_newNode = new Node(element);
    if(this->_top == NULL) this->_top = _newNode;
    else {
        _newNode->_next = this->_top;
        this->_top = _newNode;
    }
    this->_count++;
}

template <typename T>
const T &Stack<T>::top() const throw(StackIsEmpty) {
    if(this->_top == NULL) throw StackIsEmpty("Stack IS Empty");
    return this->_top->_element;
}


template <typename T>
void Stack<T>::pop() throw (StackIsEmpty) {
    if(this->_top == NULL) throw StackIsEmpty("Stack IS Empty");
    this->_top = this->_top->_next;
    this->_count--;
}

#endif /* STACK_H */

