//
// Created by argshub on 8/21/2017.
//
#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    try {
        DoublyLinkedList<int> doublyLinkedList;
        doublyLinkedList.insertFront(100);
        doublyLinkedList.insertFront(400);
        doublyLinkedList.insertBack(200);
        doublyLinkedList.insertBack(500);

        std::cout << doublyLinkedList.front();
        std::cout << doublyLinkedList.back();

        doublyLinkedList.removeFront();
        doublyLinkedList.removeBack();
    } catch (ListEmptyExceptions listEmptyExceptions) {
        std::cout << listEmptyExceptions.getMessage();
    }
    return 0;
}
