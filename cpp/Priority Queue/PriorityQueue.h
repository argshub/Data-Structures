//
// Created by argshub on 9/22/2017.
//
#include "QueueEmptyException.h"
#ifndef CPP_PRIORITYQUEUE_H
#define CPP_PRIORITYQUEUE_H

template <typename K>
class PriorityQueue {
private:
    class Node;

private:
    Node *_front;
public:
    PriorityQueue();
    ~PriorityQueue();
    void insert(const K &element) ;
    const K &min() throw(QueueEmptyException);
    void removeMin() throw(QueueEmptyException);
};

template <typename K>
PriorityQueue<K>::PriorityQueue() {
    _front = NULL;
}

template <typename K>
PriorityQueue<K>::~PriorityQueue() {
    delete  _front;
}

template <typename K>
void PriorityQueue<K>::insert(const K &element){
    Node *_newNode = new Node;
    _newNode->_element = element;
    if(_front == NULL || _front->_element > element) {
        _newNode->_next = _front;
        _front = _newNode;
        return;
    }
    Node *_head = _front, *_previous = _front;
    do {
        if(_head->_element > element) break;
        _previous = _head;
        _head = _head->_next;
    } while (_head != NULL);
    _newNode->_next = _head;
    _previous->_next = _newNode;
}

template <typename K>
const K &PriorityQueue<K>::min() throw(QueueEmptyException) {
    if(_front == NULL) throw QueueEmptyException("queue is empty");
    return _front->_element;
}

template <typename K>
void PriorityQueue<K>::removeMin() throw(QueueEmptyException) {
    if(_front == NULL) throw QueueEmptyException("queue is empty");
    _front = _front->_next;
}

// node definition


template <typename K>
class PriorityQueue<K>::Node {
private:
    K _element;
    Node *_next;
    friend class PriorityQueue;
private:
    Node();
};

template <typename K>
PriorityQueue<K>::Node::Node() {
    _next = NULL;
}

#endif //CPP_PRIORITYQUEUE_H
