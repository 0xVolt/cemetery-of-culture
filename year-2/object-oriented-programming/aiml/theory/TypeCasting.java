public class TypeCasting {

    public static void main(String[] args) {
        /*
        * widening casting (auto) -> smaller type to larger type in widening type
        * there is no chance of losing data 
        * ex: int will always fit in a long byte - short - char - int - long - float - double 
        * this is usually implicit
        */

        /* 
        * Narrowing (manual) -> converting larger to smaller type
        * double - float - long - int - char - short - byte 
        */

        byte b = 5;
        int convertB = b; // converts b automatically since byte fits inside int

        System.out.printf("Converted byte to int: %d", convertB);

        // Note: you can use %d for bytes

        int convertedToInt = 10;
        b = (byte) convertedToInt; // converts integer value to byte value explicitly

        char c = 'd';
        int charInt = (int) c;
        System.out.println(charInt);
    }
}
