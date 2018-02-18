/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Queues.Queue;
import DataStructures.Exceptions.DataStructuresExceptions;
/**
 *
 * @author argshub
 */
public class QueueTest {
    
    
    public static void main(String arg[]) {
        try {
            Queue<Integer> queue = new Queue(10);
            
            queue.enqueue(100);
            queue.enqueue(200);
            queue.enqueue(300);
            queue.enqueue(400);
            queue.enqueue(500);
            queue.enqueue(600);
            queue.enqueue(700);
            queue.enqueue(800);
            queue.enqueue(900);
            queue.enqueue(1000);
            
            queue.dequeue();
            
            System.out.printf("%d\t", queue.front());
            queue.dequeue();
            
        } catch(DataStructuresExceptions exceptions) {
            System.out.printf("Message: %s & Capacity: %d", exceptions.getMessage(), exceptions.getCapacity());
        }
    }
}
