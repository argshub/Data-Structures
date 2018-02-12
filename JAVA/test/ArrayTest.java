/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Arrays.ArrayADT;
import DataStructures.Exceptions.DataStructuresExceptions;
/**
 *
 * @author argshub
 */
public class ArrayTest {
    
    public static void main(String arg[]) {
        try {
            ArrayADT<Integer> array = new ArrayADT(10);

            for(int i = 0; i < 10; i++) array.atIndex(i, i * i);
            for(int i = 0; i < 10; i++) System.out.printf("%d\t", array.atIndex(i));
        } catch(DataStructuresExceptions exceptions) {
            System.out.printf("Message: %s & Capacity: %d", exceptions.getMessage(), exceptions.getCapacity());
        }
    }
    
}
