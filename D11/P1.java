package D11;

import java.util.*;
import java.lang.Exception;

class overflow extends Exception {
    public String toString() {
        return "\nStack is full\n";
    }
}

class underflow extends Exception {
    public String toString() {
        return "\nStack is empty\n";
    }
}

class Stack {
    int arr[];
    int top;
    int capacity;

    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    public void push(int x) {
        try {
            if (isFull()) {
                throw new overflow();
            }
            System.out.println("Inserting " + x);
            arr[++top] = x;
        } catch (overflow e) {
            System.out.println("\nCaught: " + e.toString());
        }
        
      }
    
      public void pop() {

        try {
            if (isEmpty()) {
                throw new underflow();
            }
            System.out.println("\nPopped Element: " + arr[top--]);
        } catch (underflow e) {
            System.out.println("\nCaught: " + e.toString());
        }
      }
    
      public int getSize() {
        return top + 1;
      }
    
      public Boolean isEmpty() {
        return top == -1;
      }
    
      public Boolean isFull() {
        return top == capacity - 1;
      }

      public void display() {
        for (int i = 0; i <= top; i++) {
          System.out.print(arr[i] + ", ");
          System.out.println();
        }
      }
}


public class P1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter the size of the stack : ");
        int size = sc.nextInt();
        Stack s = new Stack(size);
        boolean flag = true;
        while (flag) {
            System.out.print("\n1 - Push\n2 - Pop\n3 - Display\n4 - Exit\nEnter Your Choice: ");
            int Choice = sc.nextInt();
            switch (Choice) {
                case 1:
                    System.out.print("\nEnter the number to be pushed to the stack: ");
                    int x = sc.nextInt();
                    s.push(x);
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.display();
                    break;
                case 4:
                    flag = false;
                    break;
                default:
                    System.out.println("\nInvalid Choice.");
                    break;
            }
        }
        sc.close();
    }
    
}
