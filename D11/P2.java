package D11;

import java.util.*;
import java.lang.Exception;
import java.lang.Thread;

class myThread extends Thread {

    public void run()
    {
 
        for (int i = 0; i < 5; i++) {
           
            System.out.println("Hello World");
        }
    }
}

public class P2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean flag = true;
        while (flag) {
            System.out.print("\n~~~~~Menu~~~~~\n1 - ArrayIndexOutOfBoundsException\n2 - NullPointerException\n3 - ArithmeticException\n4 - NumberFormatException\n5 - ClassCastException\n6 - InputMismatchException\n7 - IllegalStateException\n8 - Exit\nEnter Your Choice: ");
            int Choice = sc.nextInt();
            switch (Choice) {
                case 1:
                    try {
                        System.out.println("\nCreating an array of size 5..\nTrying to execute: arr[5] = 5;");
                        int[] arr = new int[5];
                        arr[5] = 5;
                    } catch (ArrayIndexOutOfBoundsException e) {
                        System.out.println("Caught: " + e + "\n");
                    }
                    break;
                case 2:
                    try {
                        System.out.println("\nTrying to execute:\nint[] arr = null;\narr[5] = 5;");
                        int[] arr = null;
                        arr[5] = 5;
                    } catch (NullPointerException e) {
                        System.out.println("Caught: " + e + "\n");
                    }
                    break;
                case 3:
                    try {
                        System.out.println("\nTrying to execute: int a = 10 / 0;");
                        int a = 10 / 0;
                    } catch (ArithmeticException e) {
                        System.out.println("Caught: " + e + "\n");
                    }
                    break;
                case 4:
                    try {
                        System.out.println("\nTrying to execute: int a = Integer.parseint(\"aa\");");
                        int a = Integer.parseInt("aa");
                    } catch (NumberFormatException   e) {
                        System.out.println("Caught: " + e + "\n");
                    }
                    break;
                case 5:
                    try {
                        System.out.println("\nTrying to execute:\nObject o = new Object();\nString S = (String)o;");
                        Object o = new Object();
                        String S = (String)o;
                    } catch (ClassCastException e) {
                        System.out.println("Caught: " + e + "\n");
                    }
                    break;
                case 6:
                    try {
                        System.out.println("\nTrying to execute: System.out.println(\"Enter any float number: \");\nint a = sc.nextInt();");
                        System.out.println("\nEnter any float number: ");
                        Integer a = sc.nextInt();
                    } catch (InputMismatchException e) {
                        System.out.println("Caught: " + e + "\n");
                        sc.nextLine();
                        
                    }
                    break;
                case 7:
                    try {
                        System.out.println("\nTrying to execute: myThread t = new myThread();\nt.start();\nt.start();");
                        myThread t = new myThread();
                        t.start();
                        t.start();
                    } catch (IllegalThreadStateException e) {
                        System.out.println("Caught: " + e + "\n");
                    }
                    break;
                case 8:
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