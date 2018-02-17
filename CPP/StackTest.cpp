/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackTest.cpp
 * Author: argshub
 *
 * Created on February 17, 2018, 4:49 PM
 */

#include <iostream>
#include "ds/stack.h"
#include "ds/exceptions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        Stack<int> stack(10);
        
        stack.push(900);
        stack.push(800);
        stack.push(700);
        stack.push(600);
        stack.push(500);
        stack.push(400);
        stack.push(300);
        stack.push(200);
        stack.push(100);
        stack.push(1000);
        
        cout << stack.top() << "\n";
        stack.pop();
        stack.pop();
        stack.pop();
        
        cout << stack.top() << "\n";
        
    } catch(Exceptions exceptions) {
        cout << "Message: " << exceptions.get_message() << " Capacity: " << exceptions.get_capacity();
    }
    
    return 0;
}

