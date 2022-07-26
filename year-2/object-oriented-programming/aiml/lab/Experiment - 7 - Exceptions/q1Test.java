// Code by Desh Iyer

class Student {
    private int rno;
    private String name;

    public Student() {}

    public Student(int rno, String name) {
        this.rno = rno;
        this.name = name;
    }

    public void printData() {
        System.out.printf("Roll No: %d\nName: %s\n", rno, name);
    }
}

public class q1Test {
    public static void main(String[] args) {
        Student[] studentArray = new Student[1];

        try {
            studentArray[0] = new Student(0, "A");
            studentArray[1] = new Student(1, "B");
        } catch(Exception E) {
            System.out.println(E);
        }

        System.out.println("At EOF!");
    }
}
