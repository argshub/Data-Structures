/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Arrays.Vector;
import DataStructures.Exceptions.DataStructuresExceptions;
/**
 *
 * @author argshub
 */
public class VectorTest {
    
    
    public static void main(String arg[]) {
        try {
            Vector<Integer> vector = new Vector(10);
        
            for(int i = 0; i < 50; i++) {
                vector.add(i * i);
                System.out.println(vector.atIndex(i));
            }
        } catch(DataStructuresExceptions exception) {
            System.out.println(exception.getMessage());
        }
    }
}
