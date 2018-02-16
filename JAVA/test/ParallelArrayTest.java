/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Exceptions.DataStructuresExceptions;
import DataStructures.Arrays.ParallelArray;
/**
 *
 * @author argshub
 */
public class ParallelArrayTest {
    
    public static void main(String arg[]) {
        try {
            
        ParallelArray<Integer, String, Double> parallelArray = new ParallelArray(6);
        
        parallelArray.atIndex(0, 6043, "ShazzadHossain", 4.4);
        parallelArray.atIndex(1, 6028, "RaselAhmed", 5.0);
        parallelArray.atIndex(2, 6033, "MasumBillah", 5.0);
        parallelArray.atIndex(3, 6071, "AsikHasan", 5.0);
        parallelArray.atIndex(4, 6016, "AhasanKhan", 5.0);
        parallelArray.atIndex(5, 6086, "KrisnaGhosh", 5.0);
        
        parallelArray.atIndex(0);
        parallelArray.atIndex(5);
       
        } catch(DataStructuresExceptions exceptions) {
            System.out.printf("Message: %s & Capacity: %d", exceptions.getMessage(), exceptions.getCapacity());
        }
    }
    
}
