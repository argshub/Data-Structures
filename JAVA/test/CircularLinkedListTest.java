/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Exceptions.DataStructuresExceptions;
import DataStructures.Lists.CircularLinkedList;
/**
 *
 * @author argshub
 */
public class CircularLinkedListTest {
    
    
    public static void main(String arg[]) {
        try {
            CircularLinkedList<Integer> circularLinkedList = new CircularLinkedList();

            circularLinkedList.insert(100);
            circularLinkedList.insert(200);
            circularLinkedList.insert(300);

            System.out.println(circularLinkedList.front());

            circularLinkedList.advance();

            System.out.println(circularLinkedList.front());

            circularLinkedList.advance();

            circularLinkedList.remove();

            System.out.println(circularLinkedList.front());

            circularLinkedList.remove();
            
            
            System.out.println(circularLinkedList.front());
            
            circularLinkedList.remove();
            circularLinkedList.remove();
        } catch(DataStructuresExceptions exceptions) {
            System.out.println(exceptions.getMessage());
        }
    }
    
}
