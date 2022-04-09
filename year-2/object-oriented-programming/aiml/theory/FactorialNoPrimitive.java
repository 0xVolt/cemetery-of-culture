import java.math.BigInteger;

public class FactorialNoPrimitive {
    public static BigInteger getFactorial(int num) {
        BigInteger result = BigInteger.ONE;

        for (int i = 1; i <= num; i++)
            result = result.multiply(BigInteger.valueOf(i));
            
        return result;
    }

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);

        BigInteger result = getFactorial(n);

        System.out.println("Result: " + result);
    }
}