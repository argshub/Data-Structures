//
// Created by argshub on 10/8/2017.
//

#ifndef CPP_CIRCULARBUFFEREXCEPTION_H
#define CPP_CIRCULARBUFFEREXCEPTION_H

#include <string>

class CircularBufferException {
private:
    std::string _message;
    int _capacity;
protected:
    CircularBufferException(const std::string &message, int capacity = 0): _message(message), _capacity(capacity) {}

public:
    const std::string &why() const { return _message; }
    const int getCapacity() const { return _capacity; }
};

class BufferOverflow: public CircularBufferException {
public:
    BufferOverflow(const std::string &message, const int capacity): CircularBufferException(message, capacity) {}
};

class BufferEmptyException: public CircularBufferException {
public:
    BufferEmptyException(const std::string &message): CircularBufferException(message) {}
};

#endif //CPP_CIRCULARBUFFEREXCEPTION_H
