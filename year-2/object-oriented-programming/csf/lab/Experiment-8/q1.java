// Code by Divyam Kumar

// Write a program in Java to display the names and roll numbers of students. Initialize respective array variables for 10 students. Handle ArrayIndexOutOfBoundsExeption, so that any such problem doesn’t cause illegal termination of program

class Students {
    private int rno;
    private String name;

    Students() {}

    // For keepsake
    Students(int n, String a) {
        this.rno = n;
        this.name = a;
    }

    public void printData() {
        System.out.printf("Name: %s\nRno: %d\n", name, rno);
    }
}

public class q1 {
    public static void main(String[] args) {
        Students[] studentArray = new Students[10];

        // Declarations 
        for (int i = 0; i < 10; i++) {
            studentArray[i] = new Students();
        }
        
        try {
            // Problematic statement
            studentArray[10] = new Students(10, "Im an Error");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error encountered! The error is ArrayIndexOutOfBounds!");
        }
    }
}