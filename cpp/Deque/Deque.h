//
// Created by argshub on 8/22/2017.
//
#include "DequeEmpty.h"

#ifndef CPP_DEQUE_H
#define CPP_DEQUE_H

template <typename T>
class Deque {
    private:
        class Node;

    private:
        Node *_header, *_trailer;
        int _size;

    public:
        Deque();
        ~Deque();
        void insertFront(const T &element);
        const T &front() throw(DequeEmpty);
        void insertBack(const T &element);
        const T &back() throw(DequeEmpty);
        inline const int getSize() const { return _size; }
        void removeFront() throw(DequeEmpty);
        void removeBack() throw(DequeEmpty);

    private:
        void insert(Node *node, const T &element);
        void remove(Node *node);
};


template <typename T>
Deque<T>::Deque() {
    _header = new Node;
    _trailer = new Node;
    _header->_next = _trailer;
    _trailer->_previous = _header;
    _size = 0;
}


template <typename T>
Deque<T>::~Deque() {
    delete _header, _trailer;
}

template <typename T>
void Deque<T>::insertFront(const T &element) {
    this->insert(_header->_next, element);
}

template <typename T>
void Deque<T>::insert(Node *node, const T &element) {
    Node *_newNode = new Node;
    _newNode->_element = element;
    _newNode->_next = node;
    _newNode->_previous = node->_previous;
    node->_previous = node->_previous->_next = _newNode;
    _size++;
}

template <typename T>
const T& Deque<T>::front() throw(DequeEmpty) {
    if(_header->_next == _trailer) throw DequeEmpty("deque is empty");
    return _header->_next->_element;
}


template <typename T>
void Deque<T>::insertBack(const T &element) {
    this->insert(_trailer, element);
}

template <typename T>
const T& Deque<T>::back() throw(DequeEmpty) {
    if(_header->_next == _trailer) throw DequeEmpty("deque is empty");
    return _trailer->_previous->_element;
}


template <typename T>
void Deque<T>::remove(Node *node)  {
    Node *_next = node->_next;
    Node *_previous = node->_previous;
    _previous->_next = _next;
    _next->_previous = _previous;
    _size--;
}

template <typename T>
void Deque<T>::removeFront() throw(DequeEmpty) {
    if(_header->_next == _trailer) throw DequeEmpty("deque is empty");
    this->remove(_header->_next);
}

template <typename T>
void Deque<T>::removeBack() throw(DequeEmpty) {
    if(_header->_next == _trailer) throw DequeEmpty("deque is empty");
    this->remove(_trailer->_previous);
}

// Node Definition

template <typename T>
class Deque<T>::Node {
    private:
        T _element;
        Node *_next, *_previous;
        friend class Deque;

    private:
        Node();
};

template <typename T>
Deque<T>::Node::Node() {
    _next = _previous = NULL;
}

#endif //CPP_DEQUE_H
