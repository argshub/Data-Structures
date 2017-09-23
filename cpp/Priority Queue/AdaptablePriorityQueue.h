//
// Created by argshub on 9/23/2017.
//

#include "QueueEmptyException.h"
#ifndef CPP_ADAPTABLEPRIORITYQUEUE_H
#define CPP_ADAPTABLEPRIORITYQUEUE_H

template <typename K, typename V>
class AdaptablePriorityQueue {
private:
    class Entry;

public:
    class Iterator;

private:
    Entry *_front;

public:
    AdaptablePriorityQueue();
    ~AdaptablePriorityQueue();
    void insert(const K &key, const V &value);
    Iterator begin() { return Iterator(_front); }
    Iterator end() { return Iterator(NULL); }
    void replaceValue(Iterator &iterator, const V &value);
    void removeMin() throw(QueueEmptyException);
};

template <typename K, typename V>
void AdaptablePriorityQueue<K, V>::removeMin() throw(QueueEmptyException) {
    if(_front == NULL) throw QueueEmptyException("queue is empty");
    _front = _front->_next;
}

template <typename K, typename V>
void AdaptablePriorityQueue<K, V>::replaceValue(Iterator &iterator, const V &value) {
    iterator.setValue(value);
}

template <typename K, typename V>
AdaptablePriorityQueue<K, V>::AdaptablePriorityQueue() {
    _front = NULL;
}

template <typename K, typename V>
AdaptablePriorityQueue<K, V>::~AdaptablePriorityQueue() {
    delete _front;
}

template <typename K, typename V>
void AdaptablePriorityQueue<K, V>::insert(const K &key, const V &value) {
    Entry *_entry = new Entry(key, value);
    if(_front == NULL || _front->_key > key) {
        _entry->_next = _front;
        _front = _entry;
        return;
    }
    Entry *_head = _front, *_previous = _front;
    while (_head != NULL) {
        if(_head->_key > key) break;
        _previous = _head;
        _head = _head->_next;
    }
    _entry->_next = _head;
    _previous->_next = _entry;
}


// entry definition

template <typename K, typename V>
class AdaptablePriorityQueue<K, V>::Entry {
private:
    K _key;
    V _value;
    Entry *_next;
    friend class AdaptablePriorityQueue;

private:
    Entry(const K &key, const V &value);
};

template <typename K, typename V>
AdaptablePriorityQueue<K, V>::Entry::Entry(const K &key, const V &value) {
    _key = key;
    _value = value;
    _next = NULL;
};


// iterator definition
template <typename K, typename V>
class AdaptablePriorityQueue<K, V>::Iterator {
private:
    Entry *_position;
    friend class AdaptablePriorityQueue;
public:
    Iterator(Entry *position = NULL);
    Iterator &operator++() { _position = _position->_next;
        return *this; }
    bool operator!=(const Iterator &iterator) const { return _position != iterator._position;  }
    const Entry *operator*() const { return _position; }

public:
    void setValue(const V &value) { _position->_value = value; }

public:
    const K &key() const { return _position->_key; }
    const V &value() const { return _position->_value; }

};

template <typename K, typename V>
AdaptablePriorityQueue<K, V>::Iterator::Iterator(Entry *position) {
    _position = position;
};
#endif //CPP_ADAPTABLEPRIORITYQUEUE_H
