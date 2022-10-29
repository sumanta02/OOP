import java.util.*;
import java.text.SimpleDateFormat;

public class Employee {
    String name, joindate, department;
    int empid, fbscore;
    double salary;
    boolean promotion;
    static String orgname;

    Employee(String name, String joindate, String department, int empid, int fbscore, double salary) {
        this.name = name;
        this.joindate = joindate;
        this.department = department;
        this.empid = empid;
        this.fbscore = fbscore;
        this.salary = salary;
    }

    void display() {
        System.out.println("\nOrganization: " + orgname + "\nName: " + name + "\njoindate: " + joindate
                + "\nDepartment: " + department + "\nempid: " + empid + "\nfbscore: " + fbscore + "\nSalary: " + salary
                + "\nPromotion: " + promotion);
    }

    static class increment {
        static double cal_increment(String joindate, int fbscore) {
            String currDate = new SimpleDateFormat("dd/MM/yyyy").format(new Date());
            double years = Integer.parseInt(currDate.substring(6)) - Integer.parseInt(joindate.substring(6));
            double months = Integer.parseInt(currDate.substring(3, 5)) - Integer.parseInt(joindate.substring(3, 5));
            double days = Integer.parseInt(currDate.substring(0, 2)) - Integer.parseInt(joindate.substring(0, 2));
            double year = years + (months / 12) + (days / 365);
            double incr = (year * 10000 + fbscore * 20000);
            return incr;
        }
    }

    class promotion {
        boolean promote(double increment) {
            if (increment > (0.5 * salary)) {
                return true;
            }
            return false;
        }

    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the number of employees in the organization: ");
        int num = sc.nextInt();
        sc.skip("\n");
        Employee[] e = new Employee[num];
        System.out.print("\nEnter the name of the organization: ");
        Employee.orgname = sc.nextLine();
        for (int i = 0; i < num; i++) {
            System.out.print("\nEnter details for employee [" + (i + 1) + "]:\n");
            System.out.print("Enter Name: ");
            String name = sc.nextLine();
            System.out.print("Enter Date of Joining: ");
            String joindate = sc.nextLine();
            System.out.print("Enter Dept.: ");
            String department = sc.nextLine();
            System.out.print("Enter Employee ID: ");
            int empid = sc.nextInt();
            System.out.print("Enter Feedback Score: ");
            int fbscore = sc.nextInt();
            System.out.print("Enter Salary: ");
            double salary = sc.nextInt();
            e[i] = new Employee(name, joindate, department, empid, fbscore, salary);
            sc.skip("\n");
        }
        /*
         * e[0]=new Employee("Arin","12/05/15","CSE",20,30,1000000);
         * e[1]=new Employee("Sohom","02/03/10","ECE",24,35,2000000);
         * e[2]=new Employee("Samaresh","05/07/17","Biotechnology",36,25,900000);
         * e[3]=new Employee("Sumanta","09/08/19","Civil",15,20,1500000);
         */
        for (Employee employee : e) {
            Employee.promotion a = employee.new promotion();
            double incr = increment.cal_increment(employee.joindate, employee.fbscore);
            employee.promotion = a.promote(incr);
        }
        System.out.println("\nEmployee Details:");
        for (Employee employee : e) {
            employee.display();
        }
        sc.close();
    }
}