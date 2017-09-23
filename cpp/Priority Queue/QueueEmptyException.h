//
// Created by argshub on 9/23/2017.
//

#include <string>
#ifndef CPP_QUEUEEMPTYEXCEPTION_H
#define CPP_QUEUEEMPTYEXCEPTION_H

class QueueEmptyException {
private:
    std::string _message;
public:
    QueueEmptyException(const std::string &message): _message(message) {}
    const std::string &why() const { return _message; }
};

#endif //CPP_QUEUEEMPTYEXCEPTION_H
