// Code by Desh Iyer

// 9.Find the first word of 4 letters. In above case good. Assume such word present at least once.

public class q9 {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Ram is a good boy");
        int firstspace = sb.indexOf(" ");
        System.out.println(firstspace); // space values shows up
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
        // String str8=str7.substring(0,fifthspace);
        // System.out.println(str8);
        if (str.length() == 4) {
            System.out.println(str);
        } else if (str1.length() == 4) {
            System.out.println(str1);
        } else if (str2.length() == 4) {
            System.out.println(str2);
        } else if (str3.length() == 4) {
            System.out.println(str3);
        } else if (str4.length() == 4) {
            System.out.println(str4);
        } else if (str5.length() == 4) {
            System.out.println(str5);
        } else if (str6.length() == 4) {
            System.out.println(str6);
        } else if (str7.length() == 4) {
            System.out.println(str7);
        } else {
            System.out.println("error");
        }
    }
}
