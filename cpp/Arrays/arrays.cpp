//
// Created by argshub on 8/21/2017.
//

#include <iostream>

#include "arrays.h"

int main() {

    try{
        array<char> arr(20);
        arr[0] = 'M';
        std::cout << arr[0];
        std::cout << arr[20];
    } catch (IndexOutOfRange indexOutOfRange) {
        std::cout << '\n' << indexOutOfRange.getMessage();
    }

    return 0;
}