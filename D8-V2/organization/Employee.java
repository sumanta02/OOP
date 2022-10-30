package organization;

import java.util.*;

public class Employee {

    protected String name, DOB, department;
    protected int empid;

    protected Employee(String name, String DOB, String department, int empid) {
        this.name = name;
        this.DOB = DOB;
        this.department = department;
        this.empid = empid;
    }

    protected void display() {
        System.out.println("\nName: " + name + "\nDOB: " + DOB
                + "\nDepartment: " + department + "\nempid: " + empid);
    }


    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the number of employees in the organization: ");
        int num = sc.nextInt();
        sc.skip("\n");
        Employee[] e = new Employee[num];
        for (int i = 0; i < num; i++) {
            System.out.print("\nEnter details for employee [" + (i + 1) + "]:\n");
            System.out.print("Enter Name: ");
            String name = sc.nextLine();
            System.out.print("Enter Date of Joining: ");
            String DOB = sc.nextLine();
            System.out.print("Enter Dept.: ");
            String department = sc.nextLine();
            System.out.print("Enter Employee ID: ");
            int empid = sc.nextInt();
            e[i] = new Employee(name, DOB, department, empid);
            sc.skip("\n");
        }
        /*
         * e[0]=new Employee("Arin","12/05/15","CSE",20,30,1000000);
         * e[1]=new Employee("Sohom","02/03/10","ECE",24,35,2000000);
         * e[2]=new Employee("Samaresh","05/07/17","Biotechnology",36,25,900000);
         * e[3]=new Employee("Sumanta","09/08/19","Civil",15,20,1500000);
         */
        System.out.println("\nEmployee Details:");
        for (Employee employee : e) {
            employee.display();
        }
        sc.close();
    }
}