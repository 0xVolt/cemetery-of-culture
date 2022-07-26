import java.util.Scanner;

public class Main {
    public static Employee createEmployee(String name, int age) throws NameException, AgeException {
        if (age > 50) {
            throw new AgeException();
        }
        try {
            Double.parseDouble(name);
            throw new NameException();
        } catch (NumberFormatException e) {
        }
        return new Employee(name, age);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        String name = in.nextLine();
        int age = Integer.parseInt(in.nextLine());
        
        try {
            createEmployee(name, age);
        } catch (Exception e) {
            System.out.println(e);
        }

        in.close();
    }
}