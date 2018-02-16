/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SinglyLinkedListTest.cpp
 * Author: argshub
 *
 * Created on February 13, 2018, 1:53 PM
 */

#include <iostream>
#include "ds/singly_linked_list.h"
#include "ds/exceptions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        SinglyLinkedList<int> singly_linked_list;
        SinglyLinkedList<int>::Iterator iterator;
        
        singly_linked_list.insert_front(900);
        singly_linked_list.insert_front(800);
        singly_linked_list.insert_front(700);
        singly_linked_list.insert_front(600);
        singly_linked_list.insert_front(500);
        singly_linked_list.insert_front(400);
        singly_linked_list.insert_front(300);
        singly_linked_list.insert_front(200);
        singly_linked_list.insert_front(100);
        singly_linked_list.remove_front();
        
        for(iterator = singly_linked_list.begin(); iterator != singly_linked_list.end(); ++iterator) std::cout << *iterator << "\t";
        
        
    } catch(Exceptions exceptions) {
        cout << exceptions.get_message();
    }
    return 0;
}

