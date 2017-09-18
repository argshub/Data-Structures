//
// Created by argshub on 9/17/2017.
//

#include <iostream>
#include "MultiSet.h"

int main() {
    MultiSet<char> multiSet;
    MultiSet<char >::Iterator iterator;
    multiSet.add('B');
    multiSet.add('C');
    multiSet.add('D');
    multiSet.add('E');
    multiSet.add('B');
    multiSet.add('C');
    multiSet.add('A');

    for (iterator = multiSet.begin(); iterator != multiSet.end(); ++iterator)
        std::cout << *iterator << '\t';

    multiSet.remove('B');
    return 0;
}