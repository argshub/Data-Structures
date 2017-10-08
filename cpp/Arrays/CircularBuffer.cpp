//
// Created by argshub on 10/8/2017


#include <iostream>
#include "CircularBuffer.h"

int main() {
    try {
        CircularBuffer<int> circularBuffer;
        circularBuffer.put(100);
        circularBuffer.put(200);
        circularBuffer.put(300);
        circularBuffer.put(400);
        circularBuffer.put(500);
        circularBuffer.put(600);
        circularBuffer.put(700);
        circularBuffer.put(800);
        circularBuffer.put(900);
        circularBuffer.put(1000);
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        circularBuffer.put(900);
        circularBuffer.put(1000);
        std::cout << '\n' << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';
        std::cout << circularBuffer.get() << '\t';

    } catch (CircularBufferException circularBufferException) {
        std::cout << "cause: " << circularBufferException.why() \
                    << "\ncapacity: " << circularBufferException.getCapacity();
    }
    return 0;
}