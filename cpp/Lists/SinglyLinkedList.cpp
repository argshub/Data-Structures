//
// Created by argshub on 8/21/2017.
//

#include <iostream>
#include "SinglyLinkedList.h"

int main() {

    try{
        SinglyLinkedList<char> singlyLinkedList;
        singlyLinkedList.addFront('M');
        singlyLinkedList.addFront('S');
        singlyLinkedList.removeFront();
        std::cout << singlyLinkedList.front();
    } catch (ListEmptyExceptions listEmptyExceptions) {
        std::cout << listEmptyExceptions.getMessage();
    }

    return 0;
}
