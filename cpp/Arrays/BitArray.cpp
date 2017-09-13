//
// Created by argshub on 8/23/2017.
//

#include <iostream>
#include "BitArray.h"

int main() {
    try {
        BitArray bitArray(80);

        bitArray.setBit(16);
        bitArray.setBit(18);
        std::cout << bitArray.testBit(16) << '\n';
        bitArray.clearBit(18);
        std::cout << bitArray.testBit(18);
    } catch (IndexOutOfRange indexOutOfRange) {
        std::cout << indexOutOfRange.getMessage();
        std::cout << indexOutOfRange.getCapacity();
    }
    return 0;
}