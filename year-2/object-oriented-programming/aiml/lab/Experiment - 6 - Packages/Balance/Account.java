//2. Write a program to make a package Balance. This has an Account class with Display_Balance method.
// Import Balance package in another program to access Display_Balance method of Account class. 
// Code by Bhavy Kharbanda
//Sap Id: 500082531

package Balance;

public class Account {
    int acc_no;
    float balalance;
    String user;

    public void Display_Balance(String user, int acc_no, float balance) {
        System.out.println("\nDetails of the user: ");
        System.out.println("Name of the user of this account: " + user);
        System.out.println("Account number of the user: " + acc_no);
        System.out.println("Balance in this account: " + balance);
    }

}
