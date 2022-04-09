public class q1 {
    public static void main(String[] args) {
        int[] testArray = new int[10000];

        int x = Integer.parseInt(args[0]);
        int y = Integer.parseInt(args[1]);

        int index = x - y;
        // System.out.println("Index = " + index);

        try {
            testArray[index] = 5;
            System.out.println(x);
        } catch(ArrayIndexOutOfBoundsException e) {
            System.out.println(y);
        }
    }
}