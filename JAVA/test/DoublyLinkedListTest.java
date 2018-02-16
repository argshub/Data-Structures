/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import DataStructures.Lists.DoublyLinkedList;
import DataStructures.Exceptions.DataStructuresExceptions;
import DataStructures.Iter.Iterator;
/**
 *
 * @author argshub
 */
public class DoublyLinkedListTest {
    
    public static void main(String arg[]) {
        try {
            DoublyLinkedList<Integer> doublyLinkedList = new DoublyLinkedList();
            Iterator iterator;
            
            doublyLinkedList.inserFront(300);
            doublyLinkedList.inserFront(200);
            doublyLinkedList.inserFront(100);
            doublyLinkedList.insertBack(400);
            doublyLinkedList.insertBack(500);
            doublyLinkedList.insertBack(600);

            
            iterator = doublyLinkedList.iterator();
            
            while(iterator.hasNext()) {
                System.out.printf("%d\t", iterator.next());
            }
            
            doublyLinkedList.removeFront();
            doublyLinkedList.removeFront();

            doublyLinkedList.removeBack();
            doublyLinkedList.removeBack();
           
        } catch(DataStructuresExceptions exceptions) {
            System.out.println(exceptions.getMessage());
        }
    }
    
}
