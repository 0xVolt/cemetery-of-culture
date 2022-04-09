// import java.util.Scanner;

public class BankAccount {
    private String accountNumber;
    private String accountOwnerName;
    private String accountOwnerEmail;
    private double totalBalance;
    private int accountOwnerAge;

    public static void main(String[] args) {
        // Scanner input = new Scanner(System.in);
        BankAccount account = new BankAccount();

        account.setAccountNumber("500081889");
        account.setTotalBalance(100.0);
        account.deposit(150);

        System.out.println(account.getTotalBalance());
    }

    // method to withdraw money from the account
    public void withdraw(double amount) {
        // check apt conditions when withdrawing
        if (amount < 0 || amount > this.totalBalance || this.totalBalance - amount <= 0) {
            System.out.println("Invalid amount entered to withdraw!");
            System.out.printf("\nTotal Balance is: %d", this.totalBalance);
        } else {
            this.totalBalance -= amount;
        }
    }

    // method to deposit money into the account
    public void deposit(double amount) {
        if (amount <= 0) {
            return;
        } else {
            this.totalBalance += amount;
        }
    }

    // Setter and Getter functions 

    public String getAccountNumber() {
        return this.accountNumber;
    }

    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }

    public String getAccountOwnerName() {
        return this.accountOwnerName;
    }

    public void setAccountOwnerName(String accountOwnerName) {
        this.accountOwnerName = accountOwnerName;
    }

    public String getAccountOwnerEmail() {
        return this.accountOwnerEmail;
    }

    public void setAccountOwnerEmail(String accountOwnerEmail) {
        this.accountOwnerEmail = accountOwnerEmail;
    }

    public double getTotalBalance() {
        return this.totalBalance;
    }

    public void setTotalBalance(double totalBalance) {
        this.totalBalance = totalBalance;
    }

    public int getAccountOwnerAge() {
        return this.accountOwnerAge;
    }

    public void setAccountOwnerAge(int accountOwnerAge) {
        this.accountOwnerAge = accountOwnerAge;
    }
}
