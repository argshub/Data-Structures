/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "exceptions.h"
/* 
 * File:   set.h
 * Author: argshub
 *
 * Created on March 3, 2018, 2:27 PM
 */

#ifndef SET_H
#define SET_H

template <typename T>
class Set {
    private:
        class Node;
        public:
        class Iterator;
        class SetOperation;
        
        private:
            Node *_header, *_trailer;
    public:
        Set();
        void insert(const T &element);
        void remove(const T &element) throw (SetElementNotExist);
        bool isExistElement(const T &element);
        void removeAll();
        Iterator begin() const { return Iterator(this->_header->_next); }
        Iterator end() const { return Iterator(this->_trailer); }
        
        private:
            void insertIntoSet(Node *follower, const T &element);
            void removeFromSet(Node *follower);
};

// Set Operation Class

template <typename T>
class Set<T>::SetOperation {
    public:
        SetOperation() {}
        void setUnion(Set &setA, Set &setB, Set &setC);
        void setIntersection(Set &setA, Set &setB, Set &setC);
        void setDifference(Set &setA, Set &setB, Set &setC);
};

// Set Operation Definition

template <typename T>
void Set<T>::SetOperation::setUnion(Set &setA, Set &setB, Set &setC) {
    Iterator iterator1 = setA.begin();
    Iterator iterator2 = setB.begin();
    
    while(iterator1 != setA.end() && iterator2 != setB.end()) {
        if(*iterator1 == *iterator2) {
            setC.insert(*iterator1);
            ++iterator1;
            ++iterator2;
        } else if(*iterator1 < *iterator2) {
            setC.insert(*iterator1);
            ++iterator1;
        } else {
            setC.insert(*iterator2);
            ++iterator2;
        }
    }
    while(iterator1 != setA.end()) {
        setC.insert(*iterator1);
        ++iterator1;
    }
    
    while(iterator2 != setB.end()) {
        setC.insert(*iterator2);
        ++iterator2;
    }
}

template <typename T>
void Set<T>::SetOperation::setIntersection(Set &setA, Set &setB, Set &setC) {
    Iterator iterator1 = setA.begin();
    Iterator iterator2 = setB.begin();
    
    while(iterator1 != setA.end() && iterator2 != setB.end()) {
        if(*iterator1 < *iterator2) ++iterator1;
        else if(*iterator1 > *iterator2) ++iterator2;
        else {
            setC.insert(*iterator1);
            ++iterator1;
            ++iterator2;
        }
    }
}

template <typename T>
void Set<T>::SetOperation::setDifference(Set &setA, Set &setB, Set &setC) {
    Iterator iterator1 = setA.begin();
    Iterator iterator2 = setB.begin();
    while(iterator1 != setA.end() && iterator2 != setB.end()) {
        if(*iterator1 < *iterator2) {
            setC.insert(*iterator1);
            ++iterator1;
        } else if(*iterator1 > *iterator2) ++iterator2;
        else {
            ++iterator1;
            ++iterator2;
        }
    }
    while(iterator1 != setA.end()) {
        setC.insert(*iterator1);
        ++iterator1;
    }
}

// Iterator class

template <typename T>
class Set<T>::Iterator {
    private:
        Node *_cursor;
    private:
        Iterator(Node *cursor): _cursor(cursor) {}
        friend class Set;
        public:
            Iterator(): Iterator(NULL) {}
            Iterator &operator++() { _cursor = _cursor->_next; return *this; }
            bool operator!=(const Iterator &iterator) const  { return _cursor != iterator._cursor; }
            const T &operator*() const { return _cursor->_element; }
            
};
// Set Definition

template <typename T>
void Set<T>::removeAll() {
    this->_header->_next = this->_trailer;
    this->_trailer->_previous = this->_header;
}

template <typename T>
bool Set<T>::isExistElement(const T &element) {
    Iterator iterator = this->begin();
    while(iterator != this->end()) {
        if(*iterator == element) return true;
        ++iterator;
    }
    return false;
}

template <typename T>
Set<T>::Set() {
    this->_header = new Node;
    this->_trailer  =  new Node;
    this->_header->_next = this->_trailer;
    this->_trailer->_previous = this->_header;
}

template <typename T>
void Set<T>::insert(const T& element) {
    Node *_cursor = this->_header->_next;
    while(_cursor != this->_trailer) {
        if(_cursor->_element == element) return;
        if(_cursor->_element > element) break;
        _cursor = _cursor->_next;
    }
    this->insertIntoSet(_cursor, element);
}

template <typename T>
void Set<T>::insertIntoSet(Node* follower, const T& element) {
    Node *_newNode = new Node;
    _newNode->_element = element;
    _newNode->_next = follower;
    _newNode->_previous = follower->_previous;
    follower->_previous = follower->_previous->_next = _newNode;
}

template <typename T>
void Set<T>::removeFromSet(Node* follower) {
    Node *_next = follower->_next;
    Node *_previous = follower->_previous;
    _next->_previous = _previous;
    _previous->_next = _next;
}

template <typename T>
void Set<T>::remove(const T& element) throw (SetElementNotExist) {
    Node *_cursor = this->_header->_next;
    while(_cursor != this->_trailer) {
        if(_cursor->_element == element) {
            this->removeFromSet(_cursor);
            return;
        }
        _cursor = _cursor->_next;
    }
    throw SetElementNotExist("Set Element Not Exists");
}

// Node class

template <typename T>
class Set<T>::Node {
    private:
        Node *_previous, *_next;
        T _element;
        friend class Set;
        Node(): _previous(NULL), _next(NULL) {}
};


#endif /* SET_H */

