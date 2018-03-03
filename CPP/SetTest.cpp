/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SetTest.cpp
 * Author: argshub
 *
 * Created on March 3, 2018, 2:40 PM
 */

#include <iostream>
#include "ds/set.h"
#include "ds/exceptions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    try {
        
        Set<int> setA, setB, setC;
        Set<int>::Iterator iterator;
        Set<int>::SetOperation setOperation;
        
        setA.insert(100);
        setA.insert(300);
        setA.insert(200);
        setA.insert(50);
        setA.insert(400);
        setA.insert(50);
        
        setB.insert(50);
        setB.insert(200);
        setB.insert(700);
        
        setOperation.setUnion(setA, setB, setC);
        cout << "After Union\n:";
        for(iterator = setA.begin(); iterator != setA.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        for(iterator = setB.begin(); iterator != setB.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        for(iterator = setC.begin(); iterator != setC.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        
        
        setC.removeAll();
        cout << "After intersection\n:";
         setOperation.setIntersection(setA, setB, setC);
        for(iterator = setA.begin(); iterator != setA.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        for(iterator = setB.begin(); iterator != setB.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        for(iterator = setC.begin(); iterator != setC.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        
        setC.removeAll();
        cout << "After Difference\n:";
         setOperation.setDifference(setA, setB, setC);
        for(iterator = setA.begin(); iterator != setA.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        for(iterator = setB.begin(); iterator != setB.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        for(iterator = setC.begin(); iterator != setC.end(); ++iterator) cout << *iterator << "\t";
        cout << "\n";
        
        if(setA.isExistElement(50)) cout << "\nElement Exist";
        
        setA.remove(50);
        setA.remove(100);
        
        if(!setA.isExistElement(50)) cout << "\nElement Not Exist";
        
    } catch(Exceptions exceptions) {
        cout << exceptions.get_message();
    }
    
    return 0;
}

