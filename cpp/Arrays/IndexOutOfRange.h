//
// Created by argshub on 8/21/2017.
//
#include "exceptions.h"
#ifndef CPP_INDEXOUTOFRANGE_H
#define CPP_INDEXOUTOFRANGE_H

class IndexOutOfRange: public Exceptions {
    private:
        int _capacity;
    public:
        IndexOutOfRange(const std::string &message, int capacity) : _capacity(capacity), Exceptions(message) {}
        inline const int getCapacity() const { return _capacity; }
};

#endif //CPP_INDEXOUTOFRANGE_H
