/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Exceptions.DataStructuresExceptions;
import DataStructures.Arrays.CircularBuffer;
/**
 *
 * @author argshub
 */
public class CircularBufferTest {
    
    
    public static void main(String arg[]) {
        try {
            CircularBuffer<Integer> circularBuffer = new CircularBuffer(13);
            
            circularBuffer.put(100);
            circularBuffer.put(200);
            circularBuffer.put(300);
            circularBuffer.put(400);
            circularBuffer.put(500);
            circularBuffer.put(600);
            circularBuffer.put(700);
            circularBuffer.put(800);
            circularBuffer.put(900);
            circularBuffer.put(1000);
            circularBuffer.put(1100);
            circularBuffer.put(1200);
            circularBuffer.put(1300);
            
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            circularBuffer.put(1400);
            circularBuffer.put(1500);
            
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
            System.out.println(circularBuffer.remove());
        
        } catch(DataStructuresExceptions exceptions) {
            System.out.println(exceptions.getMessage());
        }
    }
    
}
