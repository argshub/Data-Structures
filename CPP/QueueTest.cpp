/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueTest.cpp
 * Author: argshub
 *
 * Created on February 18, 2018, 3:29 PM
 */

#include <iostream>
#include "ds/queue.h"
#include "ds/exceptions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
        try {
            Queue<int> queue(10);
            
            queue.enqueue(100);
            queue.enqueue(200);
            queue.enqueue(300);
            queue.enqueue(400);
            queue.enqueue(500);
            queue.enqueue(600);
            queue.enqueue(700);
            queue.enqueue(800);
            queue.enqueue(900);
            queue.enqueue(1000);
            
            
            queue.dequeue();
            
            cout << queue.front() << "\t";
            queue.dequeue();
            
        } catch(Exceptions exceptions) {
            cout << "Message: " <<  exceptions.get_message() << " Capacity: " << exceptions.get_capacity();
        }
    return 0;
}

