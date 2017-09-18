//
// Created by argshub on 9/17/2017.
//

#ifndef CPP_SET_H
#define CPP_SET_H

template <typename T>
class set {
private:
    class Node;
public:
    class Iterator;

public:
    class SetOperation;

private:
    Node *_header, *_trailer;
public:
    set();
    ~set();
    Iterator begin() const ;
    Iterator end() const ;
    void add(const T &element);
    void remove(const T &element);
    void emptySet();

private:
    void insert(const Iterator &iterator, const T &element);
    void removeContent(Iterator &iterator);
};

template <typename T>
void set<T>::emptySet() {
    Iterator iterator;
    for (iterator = begin(); iterator != end(); ++iterator)
        removeContent(iterator);
}

template <typename T>
void set<T>::remove(const T &element) {
    Iterator iterator;
    for (iterator = begin(); iterator != end() ; ++iterator)
        if(*iterator == element) {
            removeContent(iterator);
            break;
        }

}


template <typename T>
void set<T>::removeContent(Iterator &iterator) {
    Node *_node = iterator._position;
    Node *_next = _node->_next;
    Node *_previous = _node->_previous;
    _previous->_next = _next;
    _next->_previous = _previous;
}


template <typename T>
set<T>::set() {
    _header = new Node;
    _trailer = new Node;
    _header->_next = _trailer;
    _trailer->_previous = _header;
}

template <typename T>
void set<T>::add(const T &element) {
    Iterator iterator = begin();
    for (iterator; iterator != end(); ++iterator)
        if(element == *iterator) return;
        else if(element < *iterator) break;
    insert(iterator, element);
}

template <typename T>
set<T>::~set() {
    delete _header, _trailer;
}

template <typename T>
typename set<T>::Iterator set<T>::begin() const {
    return Iterator(_header->_next);
}

template <typename T>
typename set<T>::Iterator set<T>::end() const {
    return Iterator(_trailer);
}

template <typename T>
void set<T>::insert(const Iterator &iterator, const T &element) {
    Node *_old = iterator._position;
    Node *_newNode = new Node;
    _newNode->_element = element;
    _newNode->_next = _old;
    _newNode->_previous = _old->_previous;
    _old->_previous = _old->_previous->_next = _newNode;
}


// Node definition
template <typename T>
class set<T>::Node {
    private:
        Node *_next, *_previous;
        T _element;
        friend class set;
    private:
        Node();
};

template <typename T>
set<T>::Node::Node() {
    _next = _previous = NULL;
}

// iterator definition
template <typename T>
class set<T>::Iterator {
    private:
        Node *_position;
        friend class set;
    public:
        Iterator(Node *position = NULL);
        Iterator operator++();
        bool operator!=(const Iterator &iterator) const ;
        const T &operator*() const { return _position->_element; };
};

template <typename T>
set<T>::Iterator::Iterator(Node *position) {
    _position = position;
}

template <typename T>
typename set<T>::Iterator set<T>::Iterator::operator++() {
    _position = _position->_next;
    return *this;
}

template <typename T>
bool set<T>::Iterator::operator!=(const Iterator &iterator) const {
    return _position != iterator._position;
}


// set operation

template <typename T>
class set<T>::SetOperation {
public:
    SetOperation();
    void setUnion(const set<T> &a, const set<T> &b, set<T> &c);
    void setIntersection(const set<T> &a, const set<T> &b, set<T> &c);
    void setDifference(const set<T> &a, const set<T> &b, set<T> &c);
};

template <typename T>
set<T>::SetOperation::SetOperation() {}

template <typename T>
void set<T>::SetOperation::setUnion(const set<T> &a, const set<T> &b, set<T> &c) {
    Iterator iterator1, iterator2;
    iterator1 = a.begin();
    iterator2 = b.begin();
    c.emptySet();
    while (iterator1 != a.end() && iterator2 != b.end()) {
        if(*iterator1 < *iterator2) {
            c.add(*iterator1);
            ++iterator1;
        } else if(*iterator1 == *iterator2) {
            c.add(*iterator1);
            ++iterator1;
            ++iterator2;
        } else {
            c.add(*iterator2);
            ++iterator2;
        }
    }
    while (iterator1 != a.end()) {
        c.add(*iterator1);
        ++iterator1;
    }
    while (iterator2 != b.end()) {
        c.add(*iterator2);
        ++iterator2;
    }
}


template <typename T>
void set<T>::SetOperation::setIntersection(const set<T> &a, const set<T> &b, set<T> &c) {
    Iterator iterator, iterator1;
    iterator = a.begin();
    iterator1 = b.begin();
    c.emptySet();
    while (iterator != a.end() && iterator1 != b.end()) {
        if(*iterator < *iterator1) ++iterator;
        else if(*iterator == *iterator1) {
            c.add(*iterator);
            ++iterator, ++iterator1;
        } else ++iterator1;
    }
}

template <typename T>
void set<T>::SetOperation::setDifference(const set<T> &a, const set<T> &b, set<T> &c) {
    Iterator iterator, iterator1;
    iterator = a.begin();
    iterator1 = b.begin();
    c.emptySet();
    while (iterator != a.end() && iterator1 != b.end()) {
        if(*iterator < *iterator1) {
            c.add(*iterator);
            ++iterator;
        }
        else if(*iterator == *iterator1) {
            ++iterator; ++iterator1;
        }
        else ++iterator1;
    }
}
#endif //CPP_SET_H
