/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Exceptions.DataStructuresExceptions;
import DataStructures.Deques.Deque;
import DataStructures.Iter.Iterator;
/**
 *
 * @author argshub
 */
public class DequeTest {
    
    
    public static void main(String arg[]) {
        try {
            
            Deque<Integer> deque =  new Deque();
            Iterator iterator;
            deque.insertFront(100);
            deque.insertFront(200);
            deque.insertBack(300);
            deque.insertBack(400);
            
            
            iterator = deque.iterator();
            
            while(iterator.hasNext()) System.out.printf("%d\t", iterator.next());

            deque.removeFront();
            deque.removeBack();
            deque.removeFront();
            deque.removeBack();
            
        } catch(DataStructuresExceptions exceptions) {
            System.out.println(exceptions.getMessage());
        }
    }
}
