//
// Created by argshub on 8/22/2017.
//

#include "QueueExceptions.h"

#ifndef CPP_QUEUE_H
#define CPP_QUEUE_H

template <typename T>
class Queue {
    private:
        class Node;

    private:
        Node *_front, *_rear;
        int _capacity;
        int _size;

    public:
        Queue(int capacity = 20);
        ~Queue();
        void enqueue(const T &element) throw (QueueOverflow);
        void dequeue() throw (QueueEmpty);
        const T &front() const  throw (QueueEmpty);
};

template <typename T>
Queue<T>::Queue(int capacity) {
    _capacity = capacity;
    _size = 0;
    _front = _rear = NULL;
}

template <typename T>
Queue<T>::~Queue() {
    delete _front, _rear;
}

template <typename T>
void Queue<T>::enqueue(const T &element) throw (QueueOverflow) {
    if(_size >= _capacity) throw QueueOverflow("queue is overflow", _size);
    Node *_node = new Node;
    _node->_element = element;
    _size++;
    if(_front == NULL)  { _front = _rear = _node; return; }
    _rear = _rear->_next = _node;
}

template <typename T>
void Queue<T>::dequeue() throw (QueueEmpty) {
    if(_front == NULL) throw QueueEmpty("queue is empty", _size);
    _size--;
    if(_front == _rear) { _front = _rear = NULL; return; }
    _front = _front->_next;
}

template <typename T>
const T &Queue<T>::front() const throw (QueueEmpty){
    if(_front == NULL) throw QueueEmpty("queue is empty", _size);
    return _front->_element;
}

// Node definition
template <typename T>
class Queue<T>::Node {
    private:
        Node *_next;
        T _element;
        friend class Queue;

    private:
        Node();
};

template <typename T>
Queue<T>::Node::Node() {
    _next = NULL;
}

#endif //CPP_QUEUE_H
