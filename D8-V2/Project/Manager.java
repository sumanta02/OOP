package Project;

import organization.Employee;
import java.util.*;

public class Manager extends Employee {

    String projName;
    int teams;

    protected Manager(String name, String DOB, String department, int empid, String projName, int teams) {
        super(name, DOB, department, empid);
        this.projName = projName;
        this.teams = teams;
    }
    
    protected void display() {
        System.out.println("\nName: " + name + "\nDOB: " + DOB
                + "\nDepartment: " + department + "\nempid: " + empid + "\nProject Name: " + projName + "\nNo. of teams: "+ teams);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the number of managers in the organization: ");
        int num = sc.nextInt();
        sc.skip("\n");
        Manager[] m = new Manager[num];
        for (int i = 0; i < num; i++) {
            System.out.print("\nEnter details for manager [" + (i + 1) + "]:\n");
            System.out.print("Enter Name: ");
            String name = sc.nextLine();
            System.out.print("Enter Date of Joining: ");
            String DOB = sc.nextLine();
            System.out.print("Enter Dept.: ");
            String department = sc.nextLine();
            System.out.print("Enter Project Name: ");
            String projName = sc.nextLine();
            System.out.print("Enter Employee ID: ");
            int empid = sc.nextInt();
            System.out.print("Enter no. of teams: ");
            int teams = sc.nextInt();
            m[i] = new Manager(name, DOB, department, empid, projName, teams);
            sc.skip("\n");
        }
        /*
         * e[0]=new Employee("Arin","12/05/15","CSE",20,30,1000000);
         * e[1]=new Employee("Sohom","02/03/10","ECE",24,35,2000000);
         * e[2]=new Employee("Samaresh","05/07/17","Biotechnology",36,25,900000);
         * e[3]=new Employee("Sumanta","09/08/19","Civil",15,20,1500000);
         */
        System.out.println("\nManager Details:");
        for (Manager manager : m) {
            manager.display();
        }
        sc.close();
    }
}