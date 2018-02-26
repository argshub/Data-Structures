/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "exceptions.h"
/* 
 * File:   circular_linked_list.h
 * Author: argshub
 *
 * Created on February 25, 2018, 5:25 PM
 */

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

template <typename T>
class CircularLinkedList {
    private:
        class Node;
        private:
            Node *_head;
    
    public:
        CircularLinkedList();
        void insert(const T &element);
        const T &front() const throw (ListIsEmpty);
        void advance() throw (ListIsEmpty);
        void remove() throw (ListIsEmpty);
        
};

// Node Declaration

template <typename T>
class CircularLinkedList<T>::Node {
    private:
        Node *_next;
        T _element;
        friend class CircularLinkedList;
        private:
            Node(const T &element): _next(NULL), _element(element) {}
};

// Circular Linked List Definition

template <typename T>
CircularLinkedList<T>::CircularLinkedList() {
    this->_head = NULL;
}

template <typename T>
void CircularLinkedList<T>::insert(const T &element) {
    Node *_newNode = new Node(element);
    if(this->_head == NULL) {
        this->_head = _newNode;
        this->_head->_next = _newNode;
    }
    else {
        _newNode->_next = this->_head->_next;
        this->_head->_next = _newNode;
    }
}

template <typename T>
const T &CircularLinkedList<T>::front() const throw (ListIsEmpty) {
    if(this->_head == NULL) throw ListIsEmpty("List Is Empty");
    return this->_head->_element;
}

template <typename T>
void CircularLinkedList<T>::advance() throw (ListIsEmpty) {
    if(this->_head == NULL) throw ListIsEmpty("List Is Empty");
    this->_head = this->_head->_next;
}

template <typename T>
void CircularLinkedList<T>::remove() throw (ListIsEmpty) {
    if(this->_head == NULL) throw ListIsEmpty("List Is Empty");
    if(this->_head->_next == this->_head) this->_head = NULL;
    else this->_head->_next = this->_head->_next->_next;
}

#endif /* CIRCULAR_LINKED_LIST_H */

