//
// Created by argshub on 9/18/2017.
//

#ifndef CPP_MULTISET_H
#define CPP_MULTISET_H
template <typename T>
class MultiSet {
private:
    class Node;
public:
    class Iterator;
private:
    Node *_header, *_trailer;
public:
    MultiSet();
    ~MultiSet();
    Iterator begin() const ;
    Iterator end() const ;
    void add(const T &element);
    void remove(const T &element);

private:
    void insert(const Iterator &iterator, const T &element);
    void removeContent(Iterator &iterator);
};

template <typename T>
void MultiSet<T>::remove(const T &element) {
    Iterator iterator;
    for (iterator = begin(); iterator != end() ; ++iterator)
        if(*iterator == element) removeContent(iterator);
}


template <typename T>
void MultiSet<T>::removeContent(Iterator &iterator) {
    Node *_node = iterator._position;
    Node *_next = _node->_next;
    Node *_previous = _node->_previous;
    _previous->_next = _next;
    _next->_previous = _previous;
}


template <typename T>
MultiSet<T>::MultiSet() {
    _header = new Node;
    _trailer = new Node;
    _header->_next = _trailer;
    _trailer->_previous = _header;
}

template <typename T>
void MultiSet<T>::add(const T &element) {
    Iterator iterator = begin();
    for (iterator; iterator != end(); ++iterator)
        if(element <= *iterator) break;
    insert(iterator, element);
}

template <typename T>
MultiSet<T>::~MultiSet() {
    delete _header, _trailer;
}

template <typename T>
typename MultiSet<T>::Iterator MultiSet<T>::begin() const {
    return Iterator(_header->_next);
}

template <typename T>
typename MultiSet<T>::Iterator MultiSet<T>::end() const {
    return Iterator(_trailer);
}

template <typename T>
void MultiSet<T>::insert(const Iterator &iterator, const T &element) {
    Node *_old = iterator._position;
    Node *_newNode = new Node;
    _newNode->_element = element;
    _newNode->_next = _old;
    _newNode->_previous = _old->_previous;
    _old->_previous = _old->_previous->_next = _newNode;
}


// Node definition
template <typename T>
class MultiSet<T>::Node {
private:
    Node *_next, *_previous;
    T _element;
    friend class MultiSet;
private:
    Node();
};

template <typename T>
MultiSet<T>::Node::Node() {
    _next = _previous = NULL;
}

// iterator definition
template <typename T>
class MultiSet<T>::Iterator {
private:
    Node *_position;
    friend class MultiSet;
public:
    Iterator(Node *position = NULL);
    Iterator operator++();
    bool operator!=(const Iterator &iterator) const ;
    const T &operator*() const { return _position->_element; };
};

template <typename T>
MultiSet<T>::Iterator::Iterator(Node *position) {
    _position = position;
}

template <typename T>
typename MultiSet<T>::Iterator MultiSet<T>::Iterator::operator++() {
    _position = _position->_next;
    return *this;
}

template <typename T>
bool MultiSet<T>::Iterator::operator!=(const Iterator &iterator) const {
    return _position != iterator._position;
}

#endif //CPP_MULTISET_H
