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
#include "ds/doubly_linked_list.h"
#include "ds/exceptions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        
        DoublyLinkedList<int> doublyLinkedList;
        DoublyLinkedList<int>::Iterator iterator;
        
        doublyLinkedList.insert_front(300);
        doublyLinkedList.insert_front(200);
        doublyLinkedList.insert_front(100);
        
        doublyLinkedList.insert_back(400);
        doublyLinkedList.insert_back(500);
        doublyLinkedList.insert_back(600);
        
        
        for(iterator = doublyLinkedList.begin(); iterator != doublyLinkedList.end(); ++iterator) {
            cout << *iterator << "\t";
        }
        
        doublyLinkedList.remove_front();
        doublyLinkedList.remove_back();
        
    } catch(Exceptions exceptions) {
        cout << exceptions.get_message();
    }
    return 0;
}

