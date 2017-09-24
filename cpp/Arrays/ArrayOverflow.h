//
// Created by argshub on 9/24/2017.
//
#include <string>
#ifndef CPP_ARRAYOVERFLOW_H
#define CPP_ARRAYOVERFLOW_H

class ArrayOverflow {
private:
    std::string _message;
    int _capacity;
public:
    ArrayOverflow(const std::string &message, int capacity): _message(message), _capacity(capacity) {}
    const std::string &why() const { return _message; }
    const  int getCapacity() const { return _capacity; }
};
#endif //CPP_ARRAYOVERFLOW_H
