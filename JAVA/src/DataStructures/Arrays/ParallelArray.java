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
public class ParallelArray<A, B, C> {
    
    private int capacity;
    private A firstArray[];
    private B secondArray[];
    private C thirdArray[];
    
    public ParallelArray(int capacity) {
        this.capacity = capacity;
        this.firstArray = (A[]) new Object[this.capacity];
        this.secondArray = (B[]) new Object[this.capacity];
        this.thirdArray = (C[]) new Object[this.capacity];
    }
    
    public void atIndex(int index, A first, B second, C third) throws IndexOutOfRange {
        if(index >= this.capacity) throw new IndexOutOfRange("Index Out Of Range", this.capacity);
        this.firstArray[index] = first;
        this.secondArray[index] = second;
        this.thirdArray[index] = third;
    }
    
    public void atIndex(int index) throws IndexOutOfRange {
        if(index >= this.capacity) throw new IndexOutOfRange("Index out of Range", this.capacity);
        System.out.printf("First: %d Second: %s & Third: %f\n", this.firstArray[index], this.secondArray[index], this.thirdArray[index]);
    }
    
}
