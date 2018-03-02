/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures.Deques;
import DataStructures.Iter.Iterable;
import DataStructures.Iter.Iterator;
import DataStructures.Exceptions.DequeIsEmpty;
/**
 *
 * @author argshub
 */
public class Deque<T> implements Iterable {
    
    private Node header, trailer;
    
    public Deque() {
        this.header = new Node();
        this.trailer = new Node();
        this.header.next = this.trailer;
        this.trailer.previous = this.header;
    }
    
    public void insertFront(final T element) {
        this.insert(this.header.next, element);
    }
    
    public void insertBack(final T element) {
        this.insert(this.trailer, element);
    }
    
    public T front() throws DequeIsEmpty {
        if(this.header.next == this.trailer) throw new DequeIsEmpty("Deque is Empty");
        return this.header.next.element;
    }
    
    public T back() throws DequeIsEmpty {
        if(this.header.next == this.trailer) throw new DequeIsEmpty("Deque is Empty");
        return this.trailer.previous.element;
    }
    
    public void removeFront() throws DequeIsEmpty {
        if(this.header.next == this.trailer) throw new DequeIsEmpty("Deque Is Empty");
        this.remove(this.header.next);
    }
    
    public void removeBack() throws DequeIsEmpty {
        if(this.header.next == this.trailer) throw new DequeIsEmpty("Deque Is Empty");
        this.remove(this.trailer.previous);
    }
    
    private void remove(Node follower) {
        Node next = follower.next;
        Node previous = follower.previous;
        next.previous = previous;
        previous.next = next;
    }
    
    private void insert(Node follower, final T element) {
        Node newNode = new Node();
        newNode.element = element;
        newNode.next = follower;
        newNode.previous = follower.previous;
        follower.previous = follower.previous.next = newNode;
    }
    
    @Override
    public Iterator iterator() {
        return new DequeIterator(this.header.next, this.trailer);
    }
    
    private class Node {
        
        private Node previous, next;
        private T element;
        private Node() {
            this.previous = this.next = null;
        }
        
    }
    
    private class DequeIterator implements Iterator<T> {
        
        private Node start;
        private final Node end;
        
        private DequeIterator(Node start, Node end) {
            this.start = start;
            this.end = end;
        }
        
        @Override
        public boolean hasNext() {
            return this.start != this.end;
        }
        
        
        @Override
        public T next() {
            T element = this.start.element;
            this.start = this.start.next;
            return element;
        }
    }
}
