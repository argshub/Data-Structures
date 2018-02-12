/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures.Exceptions;

/**
 *
 * @author argshub
 */
public abstract class DataStructuresExceptions extends Exception {
    
    private int capacity;
    
    public DataStructuresExceptions(String message, int capacity) {
        super(message);
        this.capacity = capacity;
    }
    
    public DataStructuresExceptions(String message) {
        this(message, 0);
    }
    
    public int getCapacity() {
        return this.capacity;
    }
    
}
