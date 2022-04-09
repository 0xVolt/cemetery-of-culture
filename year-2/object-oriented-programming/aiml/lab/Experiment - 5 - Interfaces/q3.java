// Code by Desh Iyer

interface Constants {
    double PLANCK_CONSTANT = 6.62606896e-34;
    
    double PI = 3.14154;
}

class ReduceConstants implements Constants {
    public double getReducedPlanks() {
        return PLANCK_CONSTANT / (2 * PI);
    }

    public double getPlanks() {
        return PLANCK_CONSTANT;
    }

    public double getPI() {
        return PI;
    }
}

public class q3 {
    public static void main(String[] args) {
        ReduceConstants R = new ReduceConstants();

        double reducedPlanksConst = R.getReducedPlanks();
        double Planks = R.getPlanks();
        double PI = R.getPI();

        System.out.println("Planks Constant = " + Planks);
        System.out.println("PI = " + PI);
        System.out.println("Reduced Planks = PLANCK_CONSTANT / (2 * PI) = " + reducedPlanksConst);
    }
}
