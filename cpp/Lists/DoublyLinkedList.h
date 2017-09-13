//
// Created by argshub on 8/21/2017.
//
#include "ListEmptyExceptions.h"

#ifndef CPP_DOUBLYLINKEDLIST_H
#define CPP_DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList {
    private:
        class DoublyNode;
    private:
        DoublyNode *_header, *_trailer;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insertFront(const T &element);
        void insertBack(const T &element);
        const T &front() const throw(ListEmptyExceptions);
        const T &back() const throw(ListEmptyExceptions);
        void removeFront() throw (ListEmptyExceptions);
        void removeBack() throw (ListEmptyExceptions);

    private:
        void insert(DoublyNode *doublyNode, const T &element);
        void remove(DoublyNode *doublyNode);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    _header = new DoublyNode;
    _trailer = new DoublyNode;
    _header->_next = _trailer;
    _trailer->_previous = _header;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    delete _header;
    delete _trailer;
}

template <typename T>
void DoublyLinkedList<T>::insert(DoublyNode *doublyNode, const T &element) {
    DoublyNode *_node = new DoublyNode;
    _node->_element = element;
    _node->_next = doublyNode;
    _node->_previous = doublyNode->_previous;
    doublyNode->_previous = doublyNode->_previous->_next = _node;
}

template <typename T>
void DoublyLinkedList<T>::insertFront(const T &element) {
    this->insert(_header->_next, element);
}

template <typename T>
const T &DoublyLinkedList<T>::front() const throw(ListEmptyExceptions) {
    if(_header->_next == _trailer) throw ListEmptyExceptions("list is empty");
    return _header->_next->_element;
}

template <typename T>
const T &DoublyLinkedList<T>::back() const throw(ListEmptyExceptions) {
    if(_header->_next == _trailer) throw ListEmptyExceptions("list is empty");
    return _trailer->_previous->_element;
}

template <typename T>
void DoublyLinkedList<T>::insertBack(const T &element) {
    this->insert(_trailer, element);
}

template <typename T>
void DoublyLinkedList<T>::removeFront() throw(ListEmptyExceptions) {
    if(_header->_next == _trailer) throw ListEmptyExceptions("list is empty");
    this->remove(_header->_next);
}

template <typename T>
void DoublyLinkedList<T>::removeBack() throw(ListEmptyExceptions) {
    if(_header->_next == _trailer) throw ListEmptyExceptions("list is empty");
    this->remove(_trailer->_previous);
}

template <typename T>
void DoublyLinkedList<T>::remove(DoublyNode *doublyNode) {
    DoublyNode *_next, *_previous;
    _next = doublyNode->_next;
    _previous = doublyNode->_previous;
    _previous->_next = _next;
    _next->_previous = _previous;
}

// Node Definition

template <typename T>
class DoublyLinkedList<T>::DoublyNode {
    private:
        T _element;
        DoublyNode *_next, *_previous;
        friend class DoublyLinkedList;
    private:
        DoublyNode();
};


template <typename T>
DoublyLinkedList<T>::DoublyNode::DoublyNode() {
    _next = _previous = NULL;
}

#endif //CPP_DOUBLYLINKEDLIST_H
