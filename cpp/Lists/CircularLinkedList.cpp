//
// Created by argshub on 8/22/2017.
//
#include <iostream>
#include "CircularLinkedList.h"

int main() {
    try {
        CircularLinkedList<int > circularLinkedList;
        circularLinkedList.insert(100);
        circularLinkedList.insert(200);
        circularLinkedList.insert(300);

        std::cout << circularLinkedList.front();
        circularLinkedList.advance();
        std::cout << circularLinkedList.front();

        circularLinkedList.remove();
    } catch (ListEmptyExceptions listEmptyExceptions) {
        std::cout << listEmptyExceptions.getMessage();
    }
    return 0;
}