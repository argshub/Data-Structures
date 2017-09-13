//
// Created by argshub on 9/4/2017.
//

#include <iostream>
#include "BitField.h"

int main() {

    struct status call;

    call.checkNumber = 1;

    if(call.checkNumber) call.preparedForDialing;
    else std::cout << "number isn't correct";
    return 0;
}