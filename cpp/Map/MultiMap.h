//
// Created by argshub on 9/6/2017.
//

#include "KeyNotExist.h"

#ifndef CPP_MULTIMAP_H
#define CPP_MULTIMAP_H

template <typename K, typename V>
class MultiMap {
private:
    class Node;
public:
    class Iterator;
private:
    class Entry;

private:
    Node *_header, *_trailer;
    int _size;
public:
    MultiMap();
    Iterator begin() const { return Iterator(_header->_next); }
    Iterator end() const { return Iterator(_trailer); }
    void put(const K &key, const V &value);
    void removeAll(const K &keyTo) throw(KeyNotExist);
    inline const int getSize() const { return _size; }

private:
    void insert(const Iterator &iterator, const K &keyTo, const V &valueTo);
    void remove(const Iterator &iterator);

};

template <typename K, typename V>
void MultiMap<K, V>::removeAll(const K &keyTo) throw(KeyNotExist) {
    bool checkKey = false;
    Iterator iterator;
    for (iterator = begin(); iterator != end() ; ++iterator) {
        if(iterator.key() == keyTo) { checkKey = true; remove(iterator); }
    }
    if(!checkKey) throw KeyNotExist("no value exist associated with the key");
}

template <typename K, typename V>
void MultiMap<K, V>::remove(const Iterator &iterator) {
    Node *_node = iterator._position;
    Node *_next = _node->_next;
    Node *_previous = _node->_previous;
    _next->_previous = _previous;
    _previous->_next = _next;
    _size--;
}

template <typename K, typename V>
void MultiMap<K, V>::put(const K &key, const V &value) {
    insert(end(), key, value);
}

template <typename K, typename V>
void MultiMap<K, V>::insert(const Iterator &iterator, const K &keyTo, const V &valueTo) {
    Node *_node = iterator._position;
    Node *_newNode = new Node;
    _newNode->_entry = new Entry(keyTo, valueTo);
    _newNode->_next = _node;
    _newNode->_previous = _node->_previous;
    _node->_previous = _node->_previous->_next = _newNode;
    _size++;
}

template <typename K, typename V>
MultiMap<K, V>::MultiMap() {
    _header = new Node;
    _trailer = new Node;
    _header->_next = _trailer;
    _trailer->_previous = _header;
}

// node definition

template <typename K, typename V>
class MultiMap<K, V>::Node {
private:
    Entry *_entry;
    Node *_next, *_previous;
private:
    Node();
    friend class MultiMap;
};

template <typename K, typename V>
MultiMap<K, V>::Node::Node() {
    _next = _previous = NULL;
};

// entry definition
template <typename K, typename V>
class MultiMap<K, V>::Entry {
private:
    K _key;
    V _value;
private:
    Entry(const K &key = K(), const V &value = V());
    friend class MultiMap;
};


template <typename K, typename V>
MultiMap<K, V>::Entry::Entry(const K &key, const V &value): _key(key), _value(value) {};


// iterator definition

template <typename K, typename V>
class MultiMap<K, V>::Iterator {
private:
    Node *_position;
    friend class MultiMap;
public:
    Iterator(Node *position = NULL): _position(position) {}
    Iterator &operator++() { _position = _position->_next; return *this; }
    bool operator!=(const Iterator &iterator) const { return _position != iterator._position; }
    const K &key() const { return _position->_entry->_key; }
    const V &value() const { return _position->_entry->_value; }
};

#endif //CPP_MULTIMAP_H
