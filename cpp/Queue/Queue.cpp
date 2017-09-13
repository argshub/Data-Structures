//
// Created by argshub on 8/22/2017.
//
#include <iostream>
#include "Queue.h"

int main() {
    try {
        Queue<int> queue;
        queue.enqueue(100);
        queue.enqueue(200);
        queue.enqueue(300);
        queue.enqueue(400);
        queue.enqueue(500);
        queue.enqueue(600);
        queue.enqueue(700);
        queue.enqueue(800);
        queue.enqueue(900);

        queue.dequeue();
        std::cout << queue.front() << '\n';
        queue.dequeue();
        queue.dequeue();
        std::cout << queue.front() << '\n';
        queue.dequeue();
    } catch(QueueExceptions queueExceptions) {
        std::cout << queueExceptions.getMessage();
        std::cout << queueExceptions.getCapacity();
    }
    return 0;
}
