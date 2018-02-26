/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CircularLinkedListTest.cpp
 * Author: argshub
 *
 * Created on February 26, 2018, 4:28 PM
 */

#include <iostream>
#include "ds/circular_linked_list.h"
#include "ds/exceptions.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        CircularLinkedList<int> circularLinkedList;

        circularLinkedList.insert(100);
        circularLinkedList.insert(200);
        circularLinkedList.insert(300);
        
        cout << circularLinkedList.front() << "\n";
        
        circularLinkedList.advance();
        
        cout << circularLinkedList.front() << "\n";
        
        circularLinkedList.advance();
        
        circularLinkedList.remove();
        
        cout << circularLinkedList.front() << "\n";
        
        circularLinkedList.remove();
        
        
        
        cout << circularLinkedList.front();
    } catch(Exceptions exceptions) {
        cout << exceptions.get_message();
    }
    return 0;
}

