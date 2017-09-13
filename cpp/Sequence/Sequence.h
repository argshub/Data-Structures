//
// Created by argshub on 8/24/2017.
//

#ifndef CPP_SEQUENCE_H
#define CPP_SEQUENCE_H

template <typename T>
class Sequence {
    private:
        class Node;
    public:
        class Iterator;

    private:
        Node *_header, *_trailer;
    public:
        Sequence();
        Iterator begin() { return Iterator(_header->_next);}
        Iterator end() { return Iterator(_trailer);}
        void insert(const Iterator &it, const T &element);
        void insertFront(const T &element);
        void insertBack(const T &element);
        void erase(const Iterator &iterator);
        void eraseFront();
        void eraseBack();
        int indexOf(const Iterator &iterator);
        Iterator atIndex(int index);
};

template <typename T>
Sequence<T>::Sequence() {
    _header = new Node;
    _trailer = new Node;
    _header->_next = _trailer;
    _trailer->_previous = _header;
}

template <typename T>
void Sequence<T>::insert(const Iterator &it, const T &element) {
    Node *_node = it._position;
    Node *_newNode = new Node;
    _newNode->_element = element;
    _newNode->_next = _node;
    _newNode->_previous = _node->_previous;
    _node->_previous = _node->_previous->_next = _newNode;
}

template <typename T>
void Sequence<T>::insertFront(const T &element) {
    this->insert(begin(), element);
}

template <typename T>
void Sequence<T>::insertBack(const T &element) {
    this->insert(end(), element);
}

template <typename T>
void Sequence<T>::erase(const Iterator &iterator) {
    Node *_node = iterator._position;
    Node *_next = _node->_next;
    Node *_previous = _node->_previous;
    _next->_previous = _previous;
    _previous->_next = _next;
}

template <typename T>
void Sequence<T>::eraseFront() {
    this->erase(begin());
}

template <typename T>
void Sequence<T>::eraseBack() {
    this->erase(--end());
}

template <typename T>
typename Sequence<T>::Iterator Sequence<T>::atIndex(int index) {
    Iterator iterator = begin();
    for (int  i = 0; i < index; i++) ++iterator;
    return iterator;
}

template <typename T>
int Sequence<T>::indexOf(const Iterator &iterator) {
    Iterator it;
    int _count = 0;
    for (it = begin(); it != iterator; ++it) _count++;
    return _count;
}

// Node definition

template <typename T>
class Sequence<T>::Node {
    private:
        Node *_next, *_previous;
        T _element;
        friend class Sequence;

    private:
        Node();
};

template <typename T>
Sequence<T>::Node::Node() {
    _next = _previous = NULL;
}

// Iterator definition

template <typename T>
class Sequence<T>::Iterator {
    private:
        Node *_position;
        friend class Sequence;
    public:
        Iterator(Node *node = NULL): _position(node) {}
        Iterator &operator++();
        Iterator &operator--();
        bool operator!=(const Iterator &iterator);
        bool operator==(const Iterator &iterator);
        const T &operator*();
};

template <typename T>
typename Sequence<T>::Iterator &Sequence<T>::Iterator::operator++() {
    _position = _position->_next;
    return *this;
}

template <typename T>
typename Sequence<T>::Iterator &Sequence<T>::Iterator::operator--() {
    _position = _position->_previous;
    return *this;
}

template <typename T>
bool Sequence<T>::Iterator::operator!=(const Iterator &iterator) {
    return _position != iterator._position;
}

template <typename T>
bool Sequence<T>::Iterator::operator==(const Iterator &iterator) {
    return _position == iterator._position;
}

template <typename T>
const T &Sequence<T>::Iterator::operator*() {
    return _position->_element;
}

#endif //CPP_SEQUENCE_H
