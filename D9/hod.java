import java.util.*;

interface admin {
    void select_cr(int year, String Sec);
    public static final String colg_Name = "Heritage Institute Of Technology";
}

abstract class faculty {
    protected String name;
    protected String faculty_id;

    protected faculty(String name, String faculty_id) {
        this.name = name;
        this.faculty_id = faculty_id;
    }

    public void display() {
        System.out.println("\nFaculty Name: " + name + "\nFaculty ID: " + faculty_id);
    }

    public void teaches(int semester) {
        System.out.println("\nFaculty: " + name + " teaches: Semester: " + semester);
    }
}

public class hod extends faculty implements admin{

    protected hod(String name, String faculty_id) {
        super(name, faculty_id);
        
    }
    public void select_cr(int year, String Sec) {
        System.out.println("Hod: " + super.name + " Selected CR from: Year: " + year + " Section: " + Sec);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter name of HOD: ");
        String name = sc.nextLine();
        System.out.print("\nEnter faculty ID of HOD: ");
        String faculty_id = sc.nextLine();
        hod h = new hod(name, faculty_id);
        System.out.print("\nEnter semester number which hod teaches: ");
        int sem = sc.nextInt();
        System.out.print("\nEnter year number of CR: ");
        int year = sc.nextInt();
        sc.skip("\n");
        System.out.print("\nEnter section of CR: ");
        String Sec = sc.nextLine();
        h.display();
        h.teaches(sem);
        h.select_cr(year, Sec);
        sc.close();
    }
}