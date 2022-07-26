// Code by Desh Iyer

// 11. Find last letter of first word.

public class q11 {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Ram is a good boy");
        int firstspace = sb.indexOf(" ");
        System.out.println(firstspace); // 3 pe space aaya
        String str = sb.substring(0, firstspace);
        System.out.println(str); // print ram

        System.out.println("last letter of first word is: " + str.charAt(str.length() - 1));

    }
}
