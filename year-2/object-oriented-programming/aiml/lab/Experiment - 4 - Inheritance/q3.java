// Code by Desh Iyer

// Write a class Worker and derive classes DailyWorker and SalariedWorker from it. Every worker has a name and a salary rate. Write method ComPay (int hours) to compute the week pay of every worker. A Daily Worker is paid on the basis of the number of days he/she works. The Salaried Worker gets paid the wage for 40 hours a week no matter what the actual hours are. Test this program to calculate the pay of workers. You are expected to use the concept of polymorphism to write this program.

class Worker {
    public String name;
    public float salaryRate;
    public int hours;
    
    public Worker() {}
    
    public Worker(String a, float b, int c) {
        name = a;
        salaryRate = b;
        hours = c;
    }
    
    public void printData() {
        System.out.printf("\nName: %s\nSalary Rate: Rs. %.2f\nHours worked: %d", name, salaryRate, hours);
    }
}

class DailyWorker extends Worker {
    public float pay;
    
    public DailyWorker() {}
    
    public DailyWorker(String a, float b, int c) {
        super(a, b, c);
    }
    
    public void comPay() {
        int numberOfDays = this.hours / 24;
        this.pay = numberOfDays * this.salaryRate;
    }
    
    public void printData() {
        super.printData();
        System.out.println("\nPay: " + pay);
    }
}

class SalariedWorker extends Worker {
    public float pay;
    
    public SalariedWorker() {}
    
    public SalariedWorker(String a, float b, int c) {
        super(a, b, c);
        pay = 0;
    }
    
    public void comPay() {
        if (this.hours >= 40) {
            this.pay = salaryRate;
        } else {
            this.pay = 0;
        }
    }
    
    public void printData() {
        super.printData();
        System.out.println("\nPay: " + pay);
    }
}

public class q3 {
    public static void main(String[] args) {
        // 500 rs a day for 120 hrs i.e. 5 days
        DailyWorker D = new DailyWorker("DW1", 500, 120);
        D.comPay();
        D.printData();

        SalariedWorker S = new SalariedWorker("SW1", 500, 120);
        S.comPay();
        S.printData();
    }
}