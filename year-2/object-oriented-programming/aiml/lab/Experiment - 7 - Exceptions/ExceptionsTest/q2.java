public class q2 {
    public static void main(String[] args) {
        float[] testArray = new float[10000];

        float x = Float.parseFloat(args[0]);
        float y = Float.parseFloat(args[1]);
    
        int index = (int) x - (int) y;
        // System.out.println("Index = " + index);

        try {
            testArray[index] = 5;
            System.out.println(x);
        } catch(ArrayIndexOutOfBoundsException e) {
            System.out.println(y);
        }
    }
}
