//
// Created by argshub on 8/22/2017.
//
#include <iostream>
#include "Stack.h"

int main() {
    try {
        Stack<char> stack;
        stack.push('M');
        stack.push('S');
        stack.push('A');
        stack.push('K');

        std::cout << stack.top();
        stack.pop();
    } catch (StackExceptions stackExceptions) {
        std::cout << stackExceptions.getMessage();
        std::cout << stackExceptions.getCapacity();
    }
    return 0;
}
