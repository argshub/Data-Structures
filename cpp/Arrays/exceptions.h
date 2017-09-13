//
// Created by argshub on 8/21/2017.
//
#include <string>

#ifndef CPP_EXCEPTIONS_H
#define CPP_EXCEPTIONS_H

class Exceptions {
    private:
        std::string _message;
    public:
        Exceptions(const std::string &message);
        const std::string getMessage() const ;
};

Exceptions::Exceptions(const std::string &message) {
    _message = message;
}

const std::string Exceptions::getMessage() const {
    return _message;
}


#endif //CPP_EXCEPTIONS_H
