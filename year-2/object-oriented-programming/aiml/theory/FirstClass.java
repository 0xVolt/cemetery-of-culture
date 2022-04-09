public class FirstClass {
    public static void main(String[] args) {
        int firstInteger = 10;

        System.out.println(firstInteger);

        // wrapper classes
        int x = 10, y = 15;
        int maxOfTwo = Integer.compare(x, y); // here, 'Integer' is the wrapper class with offers some functions unique to the primitive datatype
        System.out.println(maxOfTwo);

        long maxValueEver = Long.MAX_VALUE;
        // if you add to max value, you get a negative number
        // if you subtract from min value, you get a positive number
        
        System.out.println(maxValueEver);
    }
}
