//
// Created by argshub on 9/5/2017.
//

#include <string>
#ifndef CPP_KEYNOTEXIST_H
#define CPP_KEYNOTEXIST_H
class KeyNotExist {
private:
    std::string _message;
public:
    KeyNotExist(const std::string &message): _message(message) {}
    const std::string &getMessage() const { return _message; }
};
#endif //CPP_KEYNOTEXIST_H
