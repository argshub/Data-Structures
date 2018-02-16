/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Iter.Iterator;
import DataStructures.Lists.SinglyLinkedList;
import DataStructures.Exceptions.DataStructuresExceptions;
/**
 *
 * @author argshub
 */
public class SinglyLinkedListTest {
    
    
    public static void main(String arg[]) {
        try {
            SinglyLinkedList<Integer> singlyLinkedList = new SinglyLinkedList();
            Iterator iterator;
            for(int i = 0; i < 20; i++) singlyLinkedList.addFront(i * 100);
            
             singlyLinkedList.removeFront();
            
             iterator = singlyLinkedList.iterator();
            while(iterator.hasNext()) {
                System.out.printf("%d\t", iterator.next());
            }
            
        } catch(DataStructuresExceptions exceptions) {
            System.out.println(exceptions.getMessage());
        }
    }
}
