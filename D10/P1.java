package D10;

import java.lang.Thread;
import java.util.Random;

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
    Random rand = new Random();

    public T1(Stack m1)
    {
        this.m = m1;
        new Thread(this,"Push").start();
    }

    public void run()
    {
        for(int i=0;i<10;i++)
        {
            m.Push(rand.nextInt(1000));
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
        for(int i=0;i<10;i++)
        {
            m.Pop();
        }
    }
} 

public class P1 {
    public static void main(String args[])
    {
        Stack s = new Stack(1);
        new T1(s);
        new T2(s);

        System.out.println("\n");
    }
}
