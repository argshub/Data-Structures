//
// Created by argshub on 9/17/2017.
//

#include <iostream>
#include "set.h"

int main() {
    set<char> setA, setB, setC;
    set<char >::Iterator iterator;
    set<char >::SetOperation setOperation;

    // set A
    setA.add('B');
    setA.add('C');
    setA.add('D');
    setA.add('E');
    setA.add('A');

    // set B
    setB.add('D');
    setB.add('E');
    setB.add('F');

    std::cout << "set A: ";
    for (iterator = setA.begin(); iterator != setA.end(); ++iterator)
        std::cout << *iterator << '\t';

    std::cout << "\nset B: ";
    for (iterator = setB.begin(); iterator != setB.end(); ++iterator)
        std::cout << *iterator << '\t';

    // set union operation
    setOperation.setUnion(setA, setB, setC);
    std::cout << "\nafter set union C: ";
    for (iterator = setC.begin(); iterator != setC.end(); ++iterator)
        std::cout << *iterator << '\t';

    // set intersection operation
    setOperation.setIntersection(setA, setB, setC);
    std::cout << "\nafter set intersection C: ";
    for (iterator = setC.begin(); iterator != setC.end(); ++iterator)
        std::cout << *iterator << '\t';

    // set difference operation
    setOperation.setDifference(setA, setB, setC);
    std::cout << "\nafter set difference C: ";
    for (iterator = setC.begin(); iterator != setC.end(); ++iterator)
        std::cout << *iterator << '\t';

    setA.remove('D');
    return 0;
}