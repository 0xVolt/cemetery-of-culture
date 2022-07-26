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
        System.out.printf("Roll No: %d\nName: %s\n\n", rno, name);
    }
}

public class q1 {
    public static void main(String[] args) {
        Student[] studentArray = new Student[10];

        try {
            studentArray[0] = new Student(0, "A");
            studentArray[1] = new Student(1, "B");
            studentArray[2] = new Student(2, "C");
            studentArray[3] = new Student(3, "D");
            studentArray[4] = new Student(4, "E");
            studentArray[5] = new Student(5, "F");
            studentArray[6] = new Student(6, "G");
            studentArray[7] = new Student(7, "H");
            studentArray[8] = new Student(8, "I");
            studentArray[9] = new Student(9, "J");
            
            studentArray[10] = new Student(10, "K"); // Problematic statement
        } catch(Exception E) {
            System.out.println("ERROR!");
            System.out.println(E);
        }

        for (int i = 0; i < studentArray.length; i++) {
            System.out.printf("Index #%d\n", i);
            studentArray[i].printData();
        }

        System.out.println("At EOF!");
    }
}
