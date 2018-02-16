/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BitArrayTest.cpp
 * Author: argshub
 *
 * Created on February 16, 2018, 4:03 PM
 */

#include <iostream>
#include "ds/bit_array.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    BitArray bitArray(100);
    
    bitArray.setBit(0);
    bitArray.setBit(10);
    bitArray.setBit(15);
    bitArray.setBit(31);
    bitArray.setBit(23);
    bitArray.setBit(62);
    bitArray.setBit(93);
    bitArray.setBit(99);
    
    bitArray.clearBit(23);
    
    for(int i = 0; i < 100; i++) {
        if(bitArray.checkBit(i)) cout << "BIT" << i << " : " << 1 << "\n";
        else cout << "BIT" << i << " : " << 0 << "\n";
    }
    
    return 0;
}

