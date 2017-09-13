//
// Created by argshub on 8/22/2017.
//
#include "ListEmptyExceptions.h"
#ifndef CPP_CIRCULARLINKEDLIST_H
#define CPP_CIRCULARLINKEDLIST_H

template <typename T>
class CircularLinkedList {
    private:
        class Node;

    private:
        Node *_cursor;

    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void insert(const T &element);
        const T &front() const throw(ListEmptyExceptions);
        void advance() throw(ListEmptyExceptions);
        void remove() throw(ListEmptyExceptions);
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList() {
    _cursor = NULL;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    delete _cursor;
}

template <typename T>
void CircularLinkedList<T>::insert(const T &element) {
    Node *_node = new Node;
    _node->_element = element;
    if(_cursor == NULL) {
        _cursor = _node->_next = _node;
        return;
    }
    _node->_next = _cursor->_next;
    _cursor->_next = _node;
}

template <typename T>
const T &CircularLinkedList<T>::front() const throw(ListEmptyExceptions) {
    if(_cursor == NULL) throw ListEmptyExceptions("list is empty");
    return _cursor->_element;
}

template <typename T>
void CircularLinkedList<T>::advance() throw (ListEmptyExceptions) {
    if(_cursor == NULL) throw ListEmptyExceptions("list is empty");
    _cursor = _cursor->_next;
}

template <typename T>
void CircularLinkedList<T>::remove() throw(ListEmptyExceptions) {
    if(_cursor == NULL) throw ListEmptyExceptions("list is empty");
    if(_cursor->_next == _cursor) { _cursor = NULL; return; }
    _cursor->_next = _cursor->_next->_next;
}

// node definition

template <typename T>
class CircularLinkedList<T>::Node {
    private:
        T _element;
        Node *_next;
        friend class CircularLinkedList;
    private:
        Node();
};

template <typename T>
CircularLinkedList<T>::Node::Node() {
    _next = NULL;
}

#endif //CPP_CIRCULARLINKEDLIST_H
