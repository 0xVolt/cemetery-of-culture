public class labelsTut {
    public static void main(String[] args) {
        // outer loop label
        outer:
        for (int i = 0; i < 10; i++) {
            // inner loop label
            // inner:
            for (int j = 0; j < 10; j++) {
                if (j == 1) {
                    // break inner; & break; breaks the inner loop
                    break outer; // breaks the loop with outer label
                }
                System.out.print("j = " + j);
            }
            System.out.println("i = " + i);
        }
    }
}