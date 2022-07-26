// Code by Desh Iyer

// 13. Find first letter of every word.

public class q13 {
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

        System.out.println("=================main===============");
        System.out.println("first letter first word  " + str + " -> " + str.charAt(0));
        System.out.println("first letter second word " + str2 + " -> " + str2.charAt(0));
        System.out.println("first letter third word " + str4 + " -> " + str4.charAt(0));
        System.out.println("first letter fourth word " + str6 + " -> " + str6.charAt(0));
        System.out.println("first letter fifth word " + str7 + " -> " + str7.charAt(0));

    }
}
