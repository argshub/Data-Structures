//
// Created by argshub on 8/23/2017.
//

#include <iostream>
#include "Lists.h"

int main() {

    Lists<int > lists;
    Lists<int >::Iterator iterator;

    lists.insertFront(200);
    lists.insertFront(100);
    lists.insertBack(300);
    lists.insertBack(400);

    for (iterator = lists.begin(); iterator != lists.end(); ++iterator) {
        std::cout << *iterator << '\n';
    }

    lists.eraseFront();
    lists.eraseBack();
    return 0;
}