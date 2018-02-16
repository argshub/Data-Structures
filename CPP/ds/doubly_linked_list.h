/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "exceptions.h"
/* 
 * File:   doubly_linked_list.h
 * Author: argshub
 *
 * Created on February 15, 2018, 6:47 PM
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
class DoublyLinkedList {
    private:
        class Node;
        private:
            Node *_header, *_footer;
            int _counter;
    public:
        class Iterator;
    public:
        DoublyLinkedList();
        void insert_front(const T &element);
        void insert_back(const T &element);
        int size() const { return this->_counter; }
        void remove_front() throw (ListIsEmpty);
        void remove_back() throw (ListIsEmpty);
        Iterator begin() const { return Iterator(this->_header->_next); }
        Iterator end() const { return Iterator(this->_footer); }
        
        private:
            void insert(Node *follower, const T &element);
            void remove(Node *nodeToDelete);
};

// DoublyLinkedList Definition

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->_header = new Node;
    this->_footer = new Node;
    this->_header->_next = this->_footer;
    this->_footer->_previous = this->_header;
    this->_counter = 0;
}

template <typename T>
void DoublyLinkedList<T>::insert_back(const T &element) {
    this->insert(this->_footer, element);
}

template <typename T>
void DoublyLinkedList<T>::remove(Node* nodeToDelete) {
    Node *_next = nodeToDelete->_next, *_previous = nodeToDelete->_previous;
    _previous->_next = _next;
    _next->_previous = _previous;
}

template <typename T>
void DoublyLinkedList<T>::remove_front() throw (ListIsEmpty) {
    if(this->_header->_next == this->_footer) throw ListIsEmpty("List Is Empty");
    this->remove(this->_header->_next);
}


template <typename T>
void DoublyLinkedList<T>::remove_back() throw(ListIsEmpty) {
    if(this->_header->_next == this->_footer) throw ListIsEmpty("List IsEmpty");
    this->remove(this->_footer->_previous);
}

template <typename T>
void DoublyLinkedList<T>::insert_front(const T& element) {
    this->insert(this->_header->_next, element);
}

template <typename T>
void DoublyLinkedList<T>::insert(Node* follower, const T& element) {
    Node *newNode = new Node;
    newNode->_element = element;
    newNode->_next = follower;
    newNode->_previous = follower->_previous;
    follower->_previous = follower->_previous->_next = newNode;
    this->_counter++;
}

// Node Declaration

template <typename T>
class DoublyLinkedList<T>::Node {
    private:
        Node *_next, *_previous;
        T _element;
        friend class DoublyLinkedList;
    public:
        Node(): _next(NULL), _previous(NULL) {}
};

// Iterator Declaration

template <typename T>
class DoublyLinkedList<T>::Iterator {
    private:
        Node *_cursor;
    
        private:
            Iterator(Node *cursor): _cursor(cursor) {}
            friend class DoublyLinkedList;
    public:
        Iterator(): _cursor(NULL) {}
        bool operator!=(const Iterator &iterator) const  { return this->_cursor != iterator._cursor; }
        const T &operator*() const { return this->_cursor->_element; }
        Iterator &operator++();
};

// Iterator Definition

template <typename T>
typename DoublyLinkedList<T>::Iterator &DoublyLinkedList<T>::Iterator::operator++() {
    this->_cursor = this->_cursor->_next;
    return *this;
}

#endif /* DOUBLY_LINKED_LIST_H */

