//
// Created by argshub on 9/5/2017.
//

#include "KeyNotExist.h"

#ifndef CPP_AP_H
#define CPP_AP_H

template <typename T, typename V>
class Map {
private:
    class Node;
private:
    class Entry;
public:
    class Iterator;

private:
    Node *_header, *_trailer;
    int _size;
public:
    Map();
    Iterator begin() { return Iterator(_header->_next); }
    Iterator end() { return Iterator(_trailer); }
    void put(const T &keyToInsert, const V &value);
    inline const int getSize() const { return _size; }
    const V &get(const T &keyToSearch) throw(KeyNotExist);
    void remove(const T &keyToDelete) throw(KeyNotExist);
private:
    void insert(const Iterator &iterator, const T &key, const V &value);
    void removeFrom(const Iterator &iterator);
};

template <typename T, typename V>
Map<T, V>::Map() {
    _header = new Node;
    _trailer = new Node;
    _header->_next = _trailer;
    _trailer->_previous = _header;
    _size = 0;
}

template <typename T, typename V>
void Map<T, V>::remove(const T &keyToDelete) throw(KeyNotExist) {
    Iterator iterator;
    for (iterator = begin(); iterator != end(); ++iterator) {
        if(iterator.key() == keyToDelete) {
            removeFrom(iterator);
            _size--;
            return;
        }
    }
    throw KeyNotExist("value not exist with the associated key");
}

template <typename T, typename V>
void Map<T, V>::removeFrom(const Iterator &iterator) {
    Node *_node = iterator._position;
    Node *_next = _node->_next;
    Node *_previous = _node->_previous;
    _previous->_next = _next;
    _next->_previous = _previous;
}

template <typename T, typename V>
void Map<T, V>::put(const T &keyToInsert, const V &value) {
    Iterator iterator;
    for (iterator = begin(); iterator != end(); ++iterator) {
        if(iterator.key() == keyToInsert) {
            iterator.setValue(value);
            return;
        }
    }
    insert(end(), keyToInsert, value);
}

template <typename T, typename V>
const V &Map<T, V>::get(const T &keyToSearch) throw(KeyNotExist) {
    Iterator iterator;
    for (iterator = begin(); iterator != end(); ++iterator) {
        if(iterator.key() == keyToSearch) {
            return iterator.value();
        }
    }
    throw KeyNotExist("value not exist with the associated key");
};

template <typename T, typename V>
void Map<T, V>::insert(const Iterator &iterator, const T &key, const V &value) {
    Node *_node = iterator._position;
    Node *_newNode = new Node;
    _newNode->_element = new Entry(key, value);
    _newNode->_next = _node;
    _newNode->_previous = _node->_previous;
    _node->_previous = _node->_previous->_next = _newNode;
    _size++;
}

// node definition

template <typename T, typename V>
class Map<T, V>::Node {
private:
    Entry *_element;
    Node *_next, *_previous;
private:
    Node();
    friend class Map;
};

template <typename T, typename V>
Map<T, V>::Node::Node() {
     _next = _previous = NULL;
};

// iterator definition

template <typename T, typename V>
class Map<T, V>::Iterator {
private:
    Node *_position;
public:
    Iterator(Node *position = NULL);
    Iterator &operator++() { _position = _position->_next; return *this; }
    bool operator!=(const Iterator &iterator) { return _position != iterator._position; }
    const T &key() const { return _position->_element->_key; }
    const V &value() const { return _position->_element->_value; }
    void setValue(const V &value) { _position->_element->_value = value; }
    friend class Map;
};

template <typename T, typename V>
Map<T, V>::Iterator::Iterator(Node *position) {
    _position = position;
}


// entry definition
template <typename T, typename V>
class Map<T, V>::Entry {
private:
    T _key;
    V _value;
private:
    Entry(const T &key = T(), const V &value = V()):_key(key), _value(value) {};
    friend class Map;
};
#endif //CPP_AP_H
