/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoublyLinkedListTest.cpp
 * Author: argshub
 *
 * Created on February 15, 2018, 7:00 PM
 */

#include <iostream>
#include "ds/deque.h"
#include "ds/exceptions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        
        Deque<int> deque;
        deque.insertFront(100);
        deque.insertFront(200);
        deque.insertBack(300);
        deque.insertBack(400);

        cout << deque.front() << "\n";
        cout << deque.back() << "\n";

        deque.removeFront();
        deque.removeBack();

        cout << deque.front() << "\n";
        cout << deque.back() << "\n";

        deque.removeFront();
        deque.removeBack();
        
    } catch(Exceptions exceptions) {
        cout << exceptions.get_message();
    }
    return 0;
}

