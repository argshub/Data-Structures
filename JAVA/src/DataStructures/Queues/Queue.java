/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures.Queues;
import DataStructures.Exceptions.QueueIsEmpty;
import DataStructures.Exceptions.QueueIsFull;
/**
 *
 * @author argshub
 */
public class Queue<T> {
    
    private int capacity, counter;
    
    private Node head, tail;
    
    public Queue(int capacity) {
        this.capacity = capacity;
        this.counter = 0;
        this.head = this.tail = null;
    }
    
    public Queue() {
        this(20);
    }
    
    public void enqueue(final T element) throws QueueIsFull {
        if(this.counter >= this.capacity) throw new QueueIsFull("Queue is Full", this.capacity);
        Node newNode = new Node(element);
        if(this.head == null) this.head = this.tail = newNode;
        else this.tail = this.tail.next = newNode;
        this.counter++;
    }
    
    public void dequeue() throws QueueIsEmpty {
        if(this.head == null) throw new QueueIsEmpty("Queue is Empty");
        if(this.head == this.tail) this.head = this.tail = null;
        else this.head = this.head.next;
        this.counter--;
    }
    
    public T front() throws QueueIsEmpty {
        if(this.head == null) throw new QueueIsEmpty("Queue is Empty");
        return this.head.element;
    }
    
    private class Node {
        private T element;
        private Node next;
        
        private Node(final T element) {
            this.element = element;
            this.next = null;
        }
    }
    
}
