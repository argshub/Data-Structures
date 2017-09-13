//
// Created by argshub on 8/24/2017.
//

#include <iostream>
#include "Sequence.h"

int main() {

    Sequence<int> sequence;
    Sequence<int >::Iterator iterator;

    sequence.insertFront(200);
    sequence.insertFront(100);

    sequence.insertBack(300);
    sequence.insertBack(400);

    for (iterator = sequence.begin(); iterator != sequence.end(); ++iterator) {
        std::cout << *iterator << '\n';
        std::cout << "index of " << sequence.indexOf(iterator) << '\n';
        std::cout << "at index " << sequence.indexOf(iterator) << " " << *sequence.atIndex(sequence.indexOf(iterator)) << '\n';
    }

    sequence.eraseFront();
    sequence.eraseBack();

    return 0;
}