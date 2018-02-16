/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Arrays.BitArray;
import DataStructures.Exceptions.DataStructuresExceptions;

/**
 *
 * @author argshub
 */
public class BitArrayTest {
    
    public static void main(String arg[]) {
       try {
           
            BitArray bitArray = new BitArray(100);
        
            bitArray.setBit(0);
            bitArray.setBit(13);
            bitArray.setBit(31);
            bitArray.setBit(62);
            bitArray.setBit(76);
            bitArray.setBit(99);
            
            bitArray.clearBit(13);
            
            for(int i = 0; i < 100; i++) {
                if(bitArray.checkBit(i)) System.out.printf("%s : %d\n", i, 1);
                else System.out.printf("%s : %d\n", i, 0);
            }
           
       } catch(DataStructuresExceptions exceptions) {
            System.out.println(exceptions.getMessage());
       }
    }
    
}
