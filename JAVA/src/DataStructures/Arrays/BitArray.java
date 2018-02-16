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
public class BitArray {
    
    private int capacity, arraySize;
    private int arrayOfData[];
    
    public BitArray(int capacity) {
        this.capacity = capacity;
        this.arraySize = this.capacity / 32 + 1;
        this.arrayOfData = new int[this.arraySize];
        for(int i = 0; i < this.arrayOfData.length; i++) this.arrayOfData[i] = 0;
    }
    
    public BitArray() {
        this(64);
    }
    
    public void setBit(int index) throws IndexOutOfRange {
        if(index >= this.capacity) throw new IndexOutOfRange("Index out of Range", this.capacity);
        this.arrayOfData[index / 32] |= (1 << (index % 32));
    }
    
    public void clearBit(int index) throws IndexOutOfRange {
        if(this.capacity <= index) throw new IndexOutOfRange("Index out of Range", this.capacity);
        this.arrayOfData[index / 32] &= ~(1 << (index % 32));
    }
    
    public boolean checkBit(int index) throws IndexOutOfRange {
        if(index >= this.capacity) throw new IndexOutOfRange("Index Out Of range", this.capacity);
        return (this.arrayOfData[index / 32] & (1 << (index % 32))) != 0;
    }
    
}
