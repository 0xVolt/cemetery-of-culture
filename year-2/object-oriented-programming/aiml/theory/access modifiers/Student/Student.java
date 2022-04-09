package Student;

public class Student {
    public String name;
    String city;
    private String phNumber;

    public void setPhNumber(String n) {
        phNumber = n;
    }

    public void getPhNumber() {
        System.out.println("Phone number: " + phNumber);
    }
}