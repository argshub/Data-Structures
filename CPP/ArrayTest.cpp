/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayTest.cpp
 * Author: argshub
 *
 * Created on February 12, 2018, 9:39 PM
 */

#include <iostream>
#include "ds/array.h"
#include "ds/exceptions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        Array<int> array;
        
        for(int i = 0; i < 20; i++) array[i] = (i * i);
        for(int i = 0; i < 20; i++) cout << array[i] << '\t';
        
    } catch(Exceptions exceptions) {
        cout << "Message: " << exceptions.get_message() << "\n";
        cout << "Capacity: " << exceptions.get_capacity();
    }
    return 0;
}

