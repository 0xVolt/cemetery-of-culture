// Code by Desh Iyer

//16.Reverse each word. In above case output is maR si a doog yob.
public class q16 {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Ram is a good boy");
        sb.reverse(); /// reversed it new added
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
        System.out.println("=============main==============");
        String finalstring = str7 + " " + str6 + " " + str4 + " " + str2 + " " + str;
        System.out.println(finalstring);
    }
}
