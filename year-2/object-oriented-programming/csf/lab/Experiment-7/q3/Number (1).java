public class Number {
    private int n;

    public Number(int number) throws LessThanException {
        if (number < 500) {
            throw new LessThanException("Number entered < 500: " + number);
        } else {
            this.n = number;
            System.out.println("Object created!");
        }
    }
}