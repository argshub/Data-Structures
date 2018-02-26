/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures.Lists;

import DataStructures.Exceptions.ListIsEmpty;

/**
 *
 * @author argshub
 */
public class CircularLinkedList<T> {
    
    private Node head;
    
    public CircularLinkedList() {
        this.head = null;
    }
    
    public void insert(final T element) {
        Node newNode = new Node(element);
        if(this.head == null) {
            this.head = newNode;
            this.head.next = newNode;
        } else {
            newNode.next = this.head.next;
            this.head.next = newNode;
        }
    }
    
    public void advance() throws ListIsEmpty {
        if(this.head == null) throw new ListIsEmpty("List Is Empty");
        this.head = this.head.next;
    }
    
    public void remove() throws ListIsEmpty {
        if(this.head == null) throw new ListIsEmpty("List is Empty");
        if(this.head.next == this.head) this.head = null;
        else this.head.next = this.head.next.next;
    }
    
    public T front() throws ListIsEmpty {
        if(this.head == null) throw new ListIsEmpty("List Is Empty");
        return this.head.element;
    }
    
    private class Node {
        private Node next;
        private T element;
        private Node(final T element) {
            this.next = null;
            this.element = element;
        }
        
    }
    
}
