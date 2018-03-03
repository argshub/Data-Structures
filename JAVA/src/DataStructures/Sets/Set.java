/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures.Sets;
import DataStructures.Exceptions.SetElementNotExist;
import DataStructures.Iter.Iterable;
import DataStructures.Iter.Iterator;
/**
 *
 * @author argshub
 */
public class Set {
    
    private Node header, trailer;
    
    public Set() {
        this.header = new Node();
        this.trailer = new Node();
        this.header.next = this.trailer;
        this.trailer.previous = this.header;
    }
    
    public void insert(final int element) {
        Node cursor = this.header.next;
        while(cursor != this.trailer) {
            if(cursor.element == element) return;
            if(cursor.element > element) break; 
            cursor = cursor.next;
        }
        this.insert(cursor, element);
    }
    
    
    public void remove(final int element) throws SetElementNotExist {
        Node cursor = this.header.next;
        while(cursor != this.trailer) {
            if(cursor.element == element) {
                this.remove(cursor);
                return;
            }
            cursor = cursor.next;
        }
        throw new SetElementNotExist("Set Element Not Exists");
    }
    
    private void insert(Node follower, final int element) {
        Node newNode = new Node();
        newNode.element = element;
        newNode.next = follower;
        newNode.previous = follower.previous;
        follower.previous = follower.previous.next = newNode;
    }
    
    public void printAllElements() {
        Node cursor = this.header.next;
        while(cursor != this.trailer) {
            System.out.printf("%d\t", cursor.element);
            cursor = cursor.next;
        }
        System.out.println();
    }
    
    private void remove(Node follower) {
        Node next = follower.next;
        Node previous = follower.previous;
        next.previous = previous;
        previous.next = next;
    }
    
    private class Node {
        private Node previous, next;
        private int element;
        private Node() {
            this.previous = this.next = null;
        }
    }
    
}
