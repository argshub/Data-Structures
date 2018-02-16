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
// Exceptions Definition

Exceptions::Exceptions(const string& message, int capacity) {
    this->_message = message;
    this->_capacity = capacity;
}

#endif /* EXCEPTIONS_H */

