//
// Created by argshub on 8/21/2017.
//

#include "exceptions.h"
#ifndef CPP_LISTEMPTYEXCEPTIONS_H
#define CPP_LISTEMPTYEXCEPTIONS_H

class ListEmptyExceptions : public Exceptions{
    public:
        ListEmptyExceptions(const std::string &message): Exceptions(message) {}
};

#endif //CPP_LISTEMPTYEXCEPTIONS_H
