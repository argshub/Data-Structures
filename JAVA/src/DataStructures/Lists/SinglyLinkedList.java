/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures.Lists;

import DataStructures.Exceptions.ListIsEmpty;
import DataStructures.Iter.Iterable;
import DataStructures.Iter.Iterator;
/**
 *
 * @author argshub
 */
public class SinglyLinkedList<T> implements Iterable {
    
    private Node head;
    
    public SinglyLinkedList() {
        this.head = null;
    }
    
    public void addFront(final T element) {
        Node newNode = new Node(element);
        if(this.head == null) this.head = newNode;
        else {
            newNode.next = this.head;
            this.head = newNode;
        }
    }
    
    public void removeFront() throws ListIsEmpty {
        if(this.head == null) throw new ListIsEmpty("List is Empty");
        this.head = this.head.next;
    }
    
    @Override
    public Iterator iterator() {
        return new SinglyLinkedListIterator(this.head);
    }
    
    private class Node {
        private T element;
        private Node next;
        private Node(final T element) {
            this.element = element;
            this.next = null;
        }
    }
    
    private class SinglyLinkedListIterator implements Iterator<T> {
        
        private Node cursor;
        
        private SinglyLinkedListIterator(Node cursor) {
            this.cursor = cursor;
        }
        
        @Override
        public boolean hasNext() {
            return this.cursor != null;
        }
        
        @Override
        public T next() {
            T element = this.cursor.element;
            this.cursor = this.cursor.next;
            return element;
        }
        
    }
}
