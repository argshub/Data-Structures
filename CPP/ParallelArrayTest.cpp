/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParallelArray.cpp
 * Author: argshub
 *
 * Created on February 16, 2018, 9:09 PM
 */

#include <iostream>
#include <string>
#include "ds/parallel_array.h"
#include "ds/exceptions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    try {
        
        ParallelArray<int, string, float> parallelArray(6);
        
        parallelArray.atIndex(0, 6043, "ShazzadHossain", 4.4);
        parallelArray.atIndex(1, 6028, "RaselAhmed", 5.0);
        parallelArray.atIndex(2, 6033, "MasumBillah", 5.0);
        parallelArray.atIndex(3, 6071, "AsikHasan", 5.0);
        parallelArray.atIndex(4, 6016, "AhasanKhan", 5.0);
        parallelArray.atIndex(5, 6086, "KrisnaGhosh", 5.0);
        
        
        
        parallelArray.atIndex(0);
        parallelArray.atIndex(5);
        
        
        
    } catch(Exceptions exceptions) {
        cout << exceptions.get_message();
        cout << exceptions.get_capacity();
    }
    
    return 0;
}

