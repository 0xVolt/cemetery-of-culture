// Code by Desh Iyer

// 2. Write a program to make a package Balance. This has an Account class with Display_Balance method.
// Import Balance package in another program to access Display_Balance method of Account class.

import java.util.Scanner;
import Balance.Account;

public class q2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Account obj = new Account();
        System.out.println("Enter Name, Account number, and Balance of the user: ");
        String name = input.nextLine();
        int ac_no = input.nextInt();
        float bal = input.nextFloat();
        obj.Display_Balance(name, ac_no, bal);
        input.close();
    }

}
