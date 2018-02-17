/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures.Stacks;
import DataStructures.Exceptions.StackOverflow;
import DataStructures.Exceptions.StackIsEmpty;

/**
 *
 * @author argshub
 */
public class Stack<T> {
    
    private int capacity, count;
    private Node top;
    
    public Stack(int capacity) {
        this.capacity = capacity;
        this.count = 0;
        this.top = null;
    }
    
    public Stack() {
        this(20);
    }
    
    public void push(final T element) throws StackOverflow {
        if(this.count == this.capacity ) throw new StackOverflow("Stack is Overflow", this.capacity);
        Node newNode = new Node(element);
        if(this.top == null) this.top = newNode;
        else {
            newNode.next = this.top;
            this.top = newNode;
        }
        this.count++;
    }
    
    public T top() throws StackIsEmpty {
        if(this.top == null) throw new StackIsEmpty("Stack Is Empty");
        return this.top.element;
    }
    
    public void pop() throws StackIsEmpty {
        if(this.top == null) throw new StackIsEmpty("Stack Is Empty");
        this.top = this.top.next;
        this.count--;
    }
    
    private class Node {
        private T element;
        private Node next;
        
        private Node(final T element) {
            this.element = element;
        }
        
    }
    
}
