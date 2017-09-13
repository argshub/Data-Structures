//
// Created by argshub on 8/23/2017.
//

#include <iostream>
#include "Vector.h"


int main() {
    Vector<int> vector(20);

    vector[0] = 100;
    std::cout << vector.getCapacity() << '\n';
    std::cout << vector[0] << '\n';

    vector[20] = 400;
    std::cout << vector.getCapacity() << '\n';
    std::cout << vector[20] << '\n';

    return 0;
}