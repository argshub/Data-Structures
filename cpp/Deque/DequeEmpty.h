//
// Created by argshub on 8/22/2017.
//

#include <string>

#ifndef CPP_DEQUEEMPTY_H
#define CPP_DEQUEEMPTY_H

class DequeEmpty {
    private:
        std::string _message;
    public:
        DequeEmpty(const std::string &message): _message(message) {}
        inline const std::string &getMessage() const { return _message; }
};

#endif //CPP_DEQUEEMPTY_H
