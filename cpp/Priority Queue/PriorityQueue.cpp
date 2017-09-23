//
// Created by argshub on 9/22/2017.
//

#include <iostream>
#include <string>
#include "PriorityQueue.h"

int main() {
    try {
        PriorityQueue<int > priorityQueue;
        priorityQueue.insert(100);
        priorityQueue.insert(30);
        priorityQueue.insert(300);
        priorityQueue.insert(60);
        priorityQueue.insert(250);
        priorityQueue.insert(10);

        std::cout << priorityQueue.min();
        priorityQueue.removeMin();
        priorityQueue.removeMin();
        priorityQueue.removeMin();
        priorityQueue.removeMin();
        priorityQueue.removeMin();
        std::cout << priorityQueue.min();
        } catch (QueueEmptyException queueEmptyException) {
        std::cout << queueEmptyException.why();
    }
    return 0;
}