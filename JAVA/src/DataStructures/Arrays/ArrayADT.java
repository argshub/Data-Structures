/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures.Arrays;
import DataStructures.Exceptions.IndexOutOfRange;

/**
 *
 * @author argshub
 */
public class ArrayADT<T> {
    
    private int capacity;
    private T arraysOfData[];
    
    public ArrayADT(int capacity) {
        this.capacity = capacity;
        this.arraysOfData = (T[]) new Object[this.capacity];
    }
    
    public ArrayADT() {
        this(20);
    }
    
    public void atIndex(int index, T data) throws IndexOutOfRange {
        if(index >= this.capacity) throw new IndexOutOfRange("Index Out of Range", this.capacity);
        this.arraysOfData[index] = data;
    }
    
    public T atIndex(int index) throws IndexOutOfRange {
        if(index >= this.capacity) throw new IndexOutOfRange("Index Out Of Range", this.capacity);
        return this.arraysOfData[index];
    }
    
}
