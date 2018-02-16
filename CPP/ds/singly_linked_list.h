/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "exceptions.h"
/* 
 * File:   singly_linked_list.h
 * Author: argshub
 *
 * Created on February 13, 2018, 1:38 PM
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


// Singly Linked List Declaration
template <typename T>
class SinglyLinkedList {
    private:
        class Node;
    public:
        class Iterator;
    private:
        Node *_head;
    public:
        SinglyLinkedList(): _head(NULL) {}
        ~SinglyLinkedList() { delete _head; }
        void insert_front(const T &element);
        void remove_front() throw (ListIsEmpty);
        Iterator begin() const { return Iterator(this->_head); }
        Iterator end() const { return Iterator(NULL); }
        
};

// SinglyLinkedList Definition

template <typename T>
void SinglyLinkedList<T>::insert_front(const T& element) {
    Node *_newNode = new Node(element);
    if(this->_head == NULL) this->_head = _newNode;
    else {
        _newNode->_next = this->_head;
        this->_head = _newNode;
    }
}

template <typename T>
void SinglyLinkedList<T>::remove_front() throw (ListIsEmpty) {
    if(this->_head == NULL) throw ListIsEmpty("List IS Empty");
    this->_head = this->_head->_next;
}

// Node Declaration

template <typename T>
class SinglyLinkedList<T>::Node {
    private:
        Node *_next;
        T _element;
        friend class SinglyLinkedList;
    private:
        Node(const T &element): _next(NULL), _element(element) {}
};

// Iterator Class

template <typename T>
class SinglyLinkedList<T>::Iterator {
    private:
        Node *_cursor;
    private:
        Iterator(Node *cursor): _cursor(cursor) {}
        friend class SinglyLinkedList;
    public:
        Iterator(): Iterator(NULL) {}
        Iterator &operator++();
        const T &operator*() const { return this->_cursor->_element; }
        bool operator!=(const Iterator &iterator) const { return this->_cursor != iterator._cursor; }
        
};

// Singly Linked List Iterator Definition

template <typename T>
typename SinglyLinkedList<T>::Iterator::Iterator &SinglyLinkedList<T>::Iterator::operator++() {
    this->_cursor = this->_cursor->_next;
    return *this;
}

#endif /* SINGLY_LINKED_LIST_H */

