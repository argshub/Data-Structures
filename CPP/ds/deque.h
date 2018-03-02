/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "exceptions.h"
/* 
 * File:   deque.h
 * Author: argshub
 *
 * Created on March 2, 2018, 4:58 PM
 */

#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
class Deque {
   
    private:
        class Node;
        
        private:
            Node *_header, *_trailer;
        public:
            Deque();
            void insertFront(const T &element);
            void insertBack(const T &element);
            const T &front() throw (DequeIsEmpty);
            const T &back() throw (DequeIsEmpty);
            void removeFront() throw (DequeIsEmpty);
            void removeBack() throw (DequeIsEmpty);
            
            private:
                void insert(Node *follower, const T &element);
                void remove(Node *follower);
    
};

// Node class

template <typename T>
class Deque<T>::Node {
    private:
        Node *_next, *_previous;
        T _element;
        friend class Deque;
        Node(): _next(NULL), _previous(NULL) {}
};

//  Deque Definition

template <typename T>
Deque<T>::Deque() {
    this->_header = new Node;
    this->_trailer = new Node;
    this->_header->_next = this->_trailer;
    this->_trailer->_previous = this->_header;
}

template <typename T>
void Deque<T>::insertFront(const T &element) {
    this->insert(this->_header->_next, element);
}

template <typename T>
void Deque<T>::insert(Node *follower, const T& element) {
    Node *_newNode = new Node;
    _newNode->_element = element;
    _newNode->_next = follower;
    _newNode->_previous = follower->_previous;
    follower->_previous = follower->_previous->_next = _newNode;
}

template <typename T>
void Deque<T>::insertBack(const T& element) {
    this->insert(this->_trailer, element);
}

template <typename T>
const T &Deque<T>::front() throw (DequeIsEmpty) {
    if(this->_header->_next == this->_trailer) throw DequeIsEmpty("Deque is Empty");
    return this->_header->_next->_element;
}

template <typename T>
const T &Deque<T>::back() throw (DequeIsEmpty) {
    if(this->_header->_next == this->_trailer) throw DequeIsEmpty("Deque is Empty");
    return this->_trailer->_previous->_element;
}

template <typename T>
void Deque<T>::remove(Node* follower) {
    Node *_next = follower->_next;
    Node *_previous = follower->_previous;
    _next->_previous = _previous;
    _previous->_next = _next;
}

template <typename T>
void Deque<T>::removeFront() throw (DequeIsEmpty) {
    if(this->_header->_next == this->_trailer) throw DequeIsEmpty("Deque is Empty");
    this->remove(this->_header->_next);
}

template <typename T>
void Deque<T>::removeBack() throw (DequeIsEmpty) {
    if(this->_header->_next == this->_trailer) throw DequeIsEmpty("Deque is Empty");
    this->remove(this->_trailer->_previous);
}

#endif /* DEQUE_H */

