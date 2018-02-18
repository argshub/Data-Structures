/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "exceptions.h"
/* 
 * File:   queue.h
 * Author: argshub
 *
 * Created on February 18, 2018, 3:10 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
    private:
        class Node;
    private:
        int _capacity, _counter;
        Node *_head, *_tail;
    public:
        Queue(int capacity);
        Queue(): Queue(20){}
        void enqueue(const T &element) throw (QueueIsFull);
        void dequeue() throw (QueueIsEmpty);
        const T &front() const  throw (QueueIsEmpty);
        
};

// Node class

template <typename T>
class Queue<T>::Node {
    private:
        T _element;
        Node *_next;
        friend class Queue;
        private:
            Node(const T &element): _element(element), _next(NULL) {}
};

// Queue definition

template <typename T>
Queue<T>::Queue(int capacity) {
    this->_head = this->_tail = NULL;
    this->_capacity = capacity;
    this->_counter = 0;
}

template <typename T>
void Queue<T>::enqueue(const T& element) throw (QueueIsFull) {
    if(this->_counter == this->_capacity) throw QueueIsFull("Queue is Full", this->_capacity);
    Node *_newNode = new Node(element);
    if(this->_head == NULL) this->_head = this->_tail = _newNode;
    else this->_tail = this->_tail->_next = _newNode;
    this->_counter++;
}

template <typename T>
void Queue<T>::dequeue() throw (QueueIsEmpty) {
    if(this->_head == NULL) throw QueueIsEmpty("Queue is Empty");
    if(this->_head == this->_tail) this->_head = this->_tail = NULL;
    else this->_head = this->_head->_next;
    this->_counter--;
}

template <typename T>
const T &Queue<T>::front() const throw (QueueIsEmpty) {
    if(this->_head == NULL) throw QueueIsEmpty("Queue Is Empty");
    return this->_head->_element;
}

#endif /* QUEUE_H */

