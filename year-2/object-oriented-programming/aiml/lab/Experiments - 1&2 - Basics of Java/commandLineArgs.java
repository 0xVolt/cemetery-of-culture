// import java.util.*;

public class commandLineArgs {
    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new Student();

        // Assign first students details
        String student1Name = args[0];
        String student1City = args[1];
        int Student1Age = Integer.parseInt(args[2]);
        // int Student1Age = (int) args[2];
        
        // Assign second students details
        String student2Name = args[3];
        String student2City = args[4];
        int Student2Age = Integer.parseInt(args[5]);
        // int Student2Age = (int) args[5];

        s1.getData(student1Name, student1City, Student1Age);
        s2.getData(student2Name, student2City, Student2Age);

        System.out.println("Printing details:");
        s1.printData();
        s2.printData();
    }
}

class Student {
    private String name, city;
    private int age;

    public void getData(String x, String y, int t) {
        name = x;
        city = y;
        age = t;
    }

    public void printData() {
        System.out.println("Student name = " + name);
        System.out.println("Student city = " + city);
        System.out.println("Student age = " + age);
    }
}