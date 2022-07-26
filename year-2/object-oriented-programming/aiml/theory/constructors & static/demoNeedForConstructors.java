class Student {
    private String name;
    private String city;
    private double cgpa;

    public void getData(String name, String city, double cgpa) {
        this.name = name;
        this.city = city;
        this.cgpa = cgpa;
    }

    public void putData() {
        System.out.println("Printing data:");
        System.out.println("Name: " + name);
        System.out.println("City: " + city);
        System.out.println("CGPA: " + cgpa);
    }
}

public class demoNeedForConstructors {
    public static void main(String[] args) {
        Student stu1 = new Student();
        stu1.getData("Amit", "Bangalore", 7.34);
        stu1.putData();
    }
}
