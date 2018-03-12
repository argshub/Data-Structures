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
public class Vector<T> {
    
    private int capacity;
    private int counter;
    
    private T data[];
    
    public Vector(int capacity) {
        this.capacity = capacity;
        this.counter = 0;
        this.data = (T[]) new Object[this.capacity];
    }
    
    public Vector() {
        this(50);
    }
    
    public void add(T data) {
        if(this.counter >= this.capacity) reserve(this.capacity * 2);
        this.data[this.counter++] = data;
    }
    
    private void reserve(int capacity) {
        T datas[] = (T[]) new Object[capacity];
        for(int i = 0; i < this.counter; i++) {
            datas[i] = this.data[i];
        }
        this.data = null;
        this.data = datas;
        this.capacity = capacity;
    }
    
    public void atIndex(int index, T data) throws IndexOutOfRange {
        if(this.counter < index) throw new IndexOutOfRange("Index Out of Range ", this.counter);
        if(this.counter >= this.capacity) reserve(this.capacity * 2);
        this.data[this.counter++] = data;
    }
    
    
    public T atIndex(int index) throws IndexOutOfRange {
        if(index >= this.counter) throw new IndexOutOfRange("Index out of Range ", this.counter);
        return this.data[index];
    }
    
    public int size() {
        return this.counter;
    }
}
