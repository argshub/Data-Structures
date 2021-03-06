/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exceptions.h
 * Author: argshub
 *
 * Created on February 12, 2018, 9:41 PM
 */
#include <string>
using namespace std;

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class Exceptions {
private:
    string _message;
    int _capacity;
protected:
    Exceptions(const string &message, int capacity);
    Exceptions(const string &message): Exceptions(message, 0) {}
public:
    const string &get_message() const { return this->_message; }
    const int &get_capacity() const { return  this->_capacity; }
};

// Index Out Of range Class

class IndexOutOfRange: public Exceptions {
public:
    IndexOutOfRange(const string &message, int capacity): Exceptions(message, capacity) {}
};

// class List Is Empty 

class ListIsEmpty: public Exceptions {
public:
    ListIsEmpty(const string &message): Exceptions(message) {}
};

// Stack Overflow Class

class StackOverflow: public Exceptions {
public:
    StackOverflow(const string &message, int capacity): Exceptions(message, capacity) {}
};

// Stack IS Empty class

class StackIsEmpty: public Exceptions {
public:
    StackIsEmpty(const string &message): Exceptions(message) {}
};

// Queue is Full class

class QueueIsFull: public Exceptions {
public:
    QueueIsFull(const string &message, int capacity): Exceptions(message, capacity) {}
};

// Queue is Empty
class QueueIsEmpty: public Exceptions {
public:
    QueueIsEmpty(const string &message): Exceptions(message) {}
};

// Deque Is Empty

class DequeIsEmpty: public Exceptions {
public:
    DequeIsEmpty(const string &message): Exceptions(message) {}
};

// Set Element Not found

class SetElementNotExist: public Exceptions {
public:
    SetElementNotExist(const string &message): Exceptions(message) {}
};

// Exceptions Definition

Exceptions::Exceptions(const string& message, int capacity) {
    this->_message = message;
    this->_capacity = capacity;
}

#endif /* EXCEPTIONS_H */

