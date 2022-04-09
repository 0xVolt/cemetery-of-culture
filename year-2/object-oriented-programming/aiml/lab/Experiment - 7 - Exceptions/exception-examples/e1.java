public class e1 {
    public static void main(String[] args) {
        String a, b;
        char c;

        a = "abc";
        // a = "abcdef";
        // a = "abcdefghikjk";

        try {
            b = a.substring(2, 5);
            System.out.println(b);

            c = a.charAt(9);
            System.out.println(c);
        } catch(Exception E) {
            System.out.println("Exception caught: " + E);
        }

        System.out.println("Outside exception!");
    }
}