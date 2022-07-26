public class q3 {
    public static void main(String[] args) {
        int[] testArray = new int[1000];

        int x = Integer.parseInt(args[0]);
        int y = Integer.parseInt(args[1]);

        int index = x - y;

        try {
            testArray[index] = 5;
            int testZeroDiv = 5 / index;
            System.out.println(1);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(2);
        } catch (ArithmeticException e) {
            System.out.println(0);
        }
    }
}
