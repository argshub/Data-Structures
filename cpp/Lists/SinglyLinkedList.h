//
// Created by argshub on 8/21/2017.
//
#include "ListEmptyExceptions.h"
#ifndef CPP_SINGLYLINKEDLIST_H
#define CPP_SINGLYLINKEDLIST_H

template <typename T>
class SinglyLinkedList {
    private:
        class SinglyNode;
    private:
        SinglyNode *_head;
        int _capacity;
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        void addFront(const T &element);
        void removeFront() throw(ListEmptyExceptions);
        const T &front() const throw(ListEmptyExceptions);
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    _capacity = 0;
    _head = NULL;
}

template <typename  T>
void SinglyLinkedList<T>::addFront(const T &element) {
    SinglyNode *_node = new SinglyNode;
    _node->_element = element;
    if(_head == NULL) { _head = _node; return; }
    _node->_next = _head;
    _head = _node;
}

template <typename T>
void SinglyLinkedList<T>::removeFront() throw(ListEmptyExceptions){
    if(_head == NULL) throw ListEmptyExceptions("list is empty");
    _head = _head->_next;
}

template <typename T>
const T &SinglyLinkedList<T>::front() const throw(ListEmptyExceptions) {
    if (_head == NULL) throw ListEmptyExceptions("list is empty");
    return _head->_element;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    delete _head;
}

// Node Definition
template <typename T>
class SinglyLinkedList<T>::SinglyNode {
    private:
        SinglyNode *_next;
        T _element;
        friend class SinglyLinkedList;

    private:
        SinglyNode();
};

template <typename T>
SinglyLinkedList<T>::SinglyNode::SinglyNode() {
    _next = NULL;
}

#endif //CPP_SINGLYLINKEDLIST_H
