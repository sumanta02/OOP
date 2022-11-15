package D10;

import java.util.*;
import java.lang.Thread;

class Stack {
    boolean flag = false;
    int arr[];
    int top;
    int capacity;

    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    public synchronized void Push(int num) {
        if (flag) {
           try {
              wait();
           } catch (InterruptedException e) {
              e.printStackTrace();
           }
        }
        arr[++top] = num;
        System.out.println("\nPushed " + arr[top]);
        flag = true;
        notify();
     }
  
     public synchronized void Pop() {
        if (!flag) {
           try {
              wait();
           } catch (InterruptedException e) {
              e.printStackTrace();
           }
        }
        System.out.println("\nPopped " + arr[top--]);
        flag = false;
        notify();
     }
}

class T1 implements Runnable
{
    Stack m;
    int[] values;

    public T1(Stack m1, int[] values)
    {
        this.m = m1;
        this.values = values;
        new Thread(this,"Push").start();
    }

    public void run()
    {
        for(int i=0;i<m.arr.length;i++)
        {
            m.Push(values[i]);
        }
    }
}

class T2 implements Runnable
{
    Stack m;

    public T2(Stack m2)
    {
        this.m = m2;
        new Thread(this,"Pop").start();
    }

    public void run()
    {
        for(int i=0;i<m.arr.length;i++)
        {
            m.Pop();
        }
    }
} 

public class P1 {
    public static void main(String args[])
    {

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter the number of elements to push/pop : ");
        
        int pushLen = sc.nextInt();
        Stack s = new Stack(pushLen);

        int[] values = new int[pushLen];
        for(int i=0;i<pushLen;i++)
        {
            System.out.print("\nEnter Value to Push : ");
            values[i] = sc.nextInt();
        }
        new T1(s, values);
        new T2(s);

        System.out.println("\n");

        sc.close();
    }
}
