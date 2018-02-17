/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import DataStructures.Stacks.Stack;
import DataStructures.Exceptions.DataStructuresExceptions;
/**
 *
 * @author argshub
 */
public class StackTest {
    
    
    public static void main(String arg[]) {
        try {   
            Stack<Integer> stack = new Stack(10);
            
            stack.push(900);
            stack.push(800);
            stack.push(700);
            stack.push(600);
            stack.push(500);
            stack.push(400);
            stack.push(300);
            stack.push(200);
            stack.push(100);
            stack.push(1000);
            
            System.out.printf("%d\n", stack.top());
            stack.pop();
            stack.pop();
            stack.pop();

            System.out.printf("%d\n", stack.top());

        } catch(DataStructuresExceptions exceptions) {
            System.out.printf("Message: %s & Capacity: %d\n", exceptions.getMessage(), exceptions.getCapacity());
        }
    }
}
