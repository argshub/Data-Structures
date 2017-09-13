//
// Created by argshub on 8/22/2017.
//

#include <iostream>
#include "Deque.h"


int main() {
    try {
        Deque<char> deque;
        deque.insertFront('M');
        deque.insertFront('B');
        deque.insertFront('C');

        deque.insertBack('S');
        deque.insertBack('A');
        deque.insertBack('P');

        deque.removeFront();
        deque.removeBack();

        std::cout << deque.front();
        std::cout << deque.back();
    } catch(DequeEmpty dequeEmpty) {
        std::cout << dequeEmpty.getMessage();
    }
    return 0;
}