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
public class StackOverflow extends DataStructuresExceptions {
    
    public StackOverflow(String message, int capacity) {
        super(message, capacity);
    }
    
}
