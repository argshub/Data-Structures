package DataStructures.Arrays;
import DataStructures.Exceptions.BufferIsEmpty;
import DataStructures.Exceptions.BufferIsFull;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author argshub
 */
public class CircularBuffer<T> {
    
    private int capacity, counter, pointer;
    private T storage[];
    
    public CircularBuffer(int capacity) {
        this.capacity = capacity;
        this.storage  = (T[]) new Object[this.capacity];
        this.counter = this.pointer = 0;
    }
    
    public void put(final T element) throws BufferIsFull {
        if(this.counter >= this.capacity) throw new BufferIsFull("Buffer Is Full", this.capacity);
        this.storage[((this.pointer + this.counter++) % this.capacity)] = element;
    }
    
    public T remove() throws BufferIsEmpty {
        if(this.counter == 0) throw new BufferIsEmpty("Buffer Is Empty");
        T element = this.storage[this.pointer++];
        this.pointer = this.pointer == this.capacity ? 0 : this.pointer;
        this.counter--;
        return element;
    }
}
