//
// Created by argshub on 9/23/2017.
//

#include <iostream>
#include <string>
#include "AdaptablePriorityQueue.h"

int main() {
    try {
        AdaptablePriorityQueue<int, std::string> adaptablePriorityQueue;
        AdaptablePriorityQueue<int, std::string>::Iterator iterator;
        adaptablePriorityQueue.insert(43, "Shazzad Hossain");
        adaptablePriorityQueue.insert(33, "Masum Billah");
        adaptablePriorityQueue.insert(116, "Ahsan Khan");
        adaptablePriorityQueue.insert(71, "Asik Hasan");
        adaptablePriorityQueue.insert(86, "Krisna Ghosh");

        for (iterator = adaptablePriorityQueue.begin(); iterator != adaptablePriorityQueue.end(); ++iterator) {
            std::cout << "key: " << iterator.key() << " value: " << iterator.value() << '\n';
            adaptablePriorityQueue.replaceValue(iterator, "JJJ");
        }
        adaptablePriorityQueue.removeMin();
    } catch (QueueEmptyException queueEmptyException) {
        std::cout << queueEmptyException.why();
    }
    return 0;
}