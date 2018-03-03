/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Sets.Set;
import DataStructures.Exceptions.DataStructuresExceptions;
/**
 *
 * @author argshub
 */
public class SetTest {
    
    
    public static void main(String arg[]) {
        
        try {
            Set set = new Set();
            set.insert(50);
            set.insert(100);
            set.insert(200);
            set.insert(500);
            set.insert(50);
            
            set.printAllElements();
            
            set.remove(50);
            set.remove(200);
            
            set.printAllElements();
            
            set.remove(400);
        } catch(DataStructuresExceptions exceptions) {
            System.out.println(exceptions.getMessage());
        }
    }
    
}
