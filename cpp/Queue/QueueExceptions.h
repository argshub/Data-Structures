//
// Created by argshub on 8/22/2017.
//

#include <string>

#ifndef CPP_QUEUEEXCEPTIONS_H
#define CPP_QUEUEEXCEPTIONS_H

using namespace std;

class QueueExceptions {
    private:
        string _message;
        int _capacity;
    public:
        QueueExceptions(const string &message, const int &capacity): _message(message), _capacity(capacity) {}
        inline const string &getMessage() const { return _message; }
        inline const int &getCapacity() const { return _capacity; }
};

class QueueOverflow: public QueueExceptions {
    public:
        QueueOverflow(const string &message, const int &capacity): QueueExceptions(message, capacity) {}
};

class QueueEmpty: public QueueExceptions {
    public:
        QueueEmpty(const string  &message, const int &capacity): QueueExceptions(message, capacity) {}
};

#endif //CPP_QUEUEEXCEPTIONS_H
