// Code by Desh Iyer

// 14. Replace first letter of every word by x. In above case xam xs x xood xoy.
public class q14 {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Ram is a good boy");
        int firstspace = sb.indexOf(" ");
        System.out.println(firstspace); // 3 pe space aaya
        String str = sb.substring(0, firstspace);
        System.out.println(str); // print ram

        String str1 = sb.substring(firstspace + 1);
        System.out.println(str1); // is a good boy
        int secondspace = str1.indexOf(" ");
        System.out.println(secondspace);
        String str2 = str1.substring(0, secondspace);
        System.out.println(str2); // print is

        String str3 = str1.substring(secondspace + 1); // print a good boy
        System.out.println(str3);
        int thirdspace = str3.indexOf(" ");
        System.out.println(thirdspace);
        String str4 = str3.substring(0, thirdspace);
        System.out.println(str4);

        String str5 = str3.substring(thirdspace + 1);
        System.out.println(str5); // print good boy
        int fourthspace = str5.indexOf(" ");
        System.out.println(fourthspace);
        String str6 = str5.substring(0, fourthspace);
        System.out.println(str6);

        String str7 = str5.substring(fourthspace + 1);
        System.out.println(str7);
        int fifthspace = str7.indexOf(" ");
        System.out.println(fifthspace);

        // replacement of characters starts here
        System.out.println(str.charAt(0));
        char replace1 = str.charAt(0);
        String s1 = Character.toString(replace1);
        String repl = str.replaceAll(s1, "x");
        System.out.println(repl); // xam

        char replace2 = str2.charAt(0);
        String s2 = Character.toString(replace2);
        String repl1 = str2.replaceAll(s2, "x");
        System.out.println(repl1); // xs

        char replace3 = str4.charAt(0);
        String s3 = Character.toString(replace3);
        System.out.println(s3);// a
        String repl2 = str4.replaceAll(s3, "x");
        System.out.println(repl2); // a -> x

        char replace4 = str6.charAt(0);
        String s4 = Character.toString(replace4);
        System.out.println(str6); // good
        String repl3 = str6.replaceAll(s4, "x");
        System.out.println(repl3);

        char replace5 = str7.charAt(0);
        String s5 = Character.toString(replace5);
        System.out.println(str7);
        String repl4 = str7.replaceAll(s5, "x");
        System.out.println(repl4);

        // repls are the changed ones
        System.out.println("The input string is " + sb);
        String finallstring = repl + " " + repl1 + " " + repl2 + " " + repl3 + " " + repl4;
        System.out.println(finallstring);
    }
}
