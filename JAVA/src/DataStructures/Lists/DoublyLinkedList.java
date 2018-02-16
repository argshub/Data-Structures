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
public class DoublyLinkedList<T> implements Iterable {
    
    private Node header, footer;
    
    private int counter;
    
    public DoublyLinkedList() {
        this.header = new Node();
        this.footer = new Node();
        this.header.next = this.footer;
        this.footer.previous = this.header;
        this.counter = 0;
    }
    
    public void inserFront(final T element) {
        this.insert(this.header.next, element);
    }
    
    public void insertBack(final T element) {
        this.insert(this.footer, element);
    }
    
    private void insert(Node follower, final T element) {
        Node newNode = new Node();
        newNode.element = element;
        newNode.next = follower;
        newNode.previous = follower.previous;
        follower.previous = follower.previous.next = newNode;
        this.counter++;
    }
    
    public int size() {
        return this.counter;
    }
   
    public void removeFront() throws ListIsEmpty {
        if(this.header.next == this.footer) throw new ListIsEmpty("List is empty");
        this.remove(this.header.next);
    }
    
    public void removeBack() throws ListIsEmpty {
        if(this.header.next == this.footer) throw new ListIsEmpty("List is Empty");
        this.remove(this.footer.previous);
    }
    
    private void remove(Node follower) {
        Node next = follower.next, previous = follower.previous;
        previous.next = next;
        next.previous = previous;
        this.counter--;
    }
    
    @Override
    public Iterator iterator() {
        return new DoublyLinkedListIterator(this.header.next, this.footer);
    }
    
    private class DoublyLinkedListIterator implements Iterator<T> {
        
        private Node header, footer;
        
        private DoublyLinkedListIterator(Node header, Node footer) {
            this.header = header;
            this.footer = footer;
        }
        
        @Override
        public boolean hasNext() {
            return this.header != this.footer;
        }
        
        @Override
        public T next() {
            T element = this.header.element;
            this.header = this.header.next;
            return element;
        }
    }
    
    
    private class Node {
        private T element;
        private Node next, previous;
        
        private Node() {
            this.next = this.previous = null;
        }
    }
    
}
