//
// Created by argshub on 8/23/2017.
//


#ifndef CPP_LISTS_H
#define CPP_LISTS_H


template <typename T>
class Lists {
    private:
        class Node;
    public:
        class Iterator;

    private:
        Node *_header, *_trailer;
    public:
        Lists();
        ~Lists();
        Iterator begin() { return Iterator(_header->_next); }
        Iterator end() { return Iterator(_trailer); }
        void insert(const Iterator &it, const T &element);
        void insertFront(const T &element);
        void insertBack(const T &element);
        void eraseFront();
        void eraseBack();
        void erase(const Iterator &iterator);
};


template <typename T>
Lists<T>::Lists() {
    _header = new Node;
    _trailer = new Node;
    _header->_next = _trailer;
    _trailer->_previous = _header;
}

template <typename T>
Lists<T>::~Lists() {
    delete _header, _trailer;
}

template <typename T>
void Lists<T>::insertFront(const T &element) {
    this->insert(begin(), element);
}

template <typename T>
void Lists<T>::insertBack(const T &element) {
    this->insert(end(), element);
}

template <typename T>
void Lists<T>::insert(const Iterator &it, const T &element) {
    Node *_node = it._position;
    Node *_newNode = new Node;
    _newNode->_element = element;
    _newNode->_next = _node;
    _newNode->_previous = _node->_previous;
    _node->_previous = _node->_previous->_next = _newNode;
}

template <typename T>
void Lists<T>::eraseFront() {
    this->erase(begin());
}

template <typename T>
void Lists<T>::eraseBack() {
    this->erase(--end());
}

template <typename T>
void Lists<T>::erase(const Iterator &it) {
    Node *_node = it._position;
    Node *_nxt = _node->_next;
    Node *_pre = _node->_previous;
    _pre->_next = _nxt;
    _nxt->_previous = _pre;
}
// Node definition

template <typename T>
class Lists<T>::Node {
    private:
        Node *_next, *_previous;
        T _element;
        friend class Lists;

    private:
        Node();
        ~Node();
};

template <typename T>
Lists<T>::Node::Node() {
    _next = _previous = NULL;
}

template <typename T>
Lists<T>::Node::~Node() {
    delete _next, _previous;
}


// Iterator definition

template <typename T>
class Lists<T>::Iterator {
    private:
        Node *_position;
        friend class Lists;
    public:
        Iterator(Node *node = NULL): _position(node) {}
        Iterator &operator++() { _position = _position->_next; return *this; }
        Iterator &operator--() { _position = _position->_previous; return *this; }
        bool operator!=(const Iterator &it) { return _position != it._position; }
        bool operator==(const Iterator &iterator) { return _position == iterator._position; }
        const T operator*() { return _position->_element; }
};



#endif //CPP_LISTS_H
