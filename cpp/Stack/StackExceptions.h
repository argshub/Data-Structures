//
// Created by argshub on 8/22/2017.
//

#include <string>
#ifndef CPP_STACKEXCEPTIONS_H
#define CPP_STACKEXCEPTIONS_H

using namespace std;
class StackExceptions {
    private:
        string _message;
        int _capacity;
    public:
        StackExceptions(const string &message, int &capacity);
        const string &getMessage() const { return _message; }
        const int &getCapacity() const { return _capacity; }
};

StackExceptions::StackExceptions(const std::string &message, int &capacity): _message(message), _capacity(capacity) {}

class StackEmpty: public StackExceptions {
    public:
        StackEmpty(const string &message, int &capacity): StackExceptions(message, capacity){}
};

class StackOverflow : public StackExceptions {
    public:
        StackOverflow(const string &message, int &capacity) : StackExceptions(message, capacity) {}
};
#endif //CPP_STACKEXCEPTIONS_H
