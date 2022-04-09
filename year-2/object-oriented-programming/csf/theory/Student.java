import java.util.*;
class Student
{   
    String s;
    int rollno;
    double age;
    
    Student()
    {
        System.out.println("Constructor Created");
        
    }
    
    void setData(String n,int r,double a)
    {
       rollno = r;
       age = a;
       s = n;
    }
    void getData()
    {
        System.out.println("NAME: "+s);
        System.out.println("ROLLNO.: "+rollno);
        System.out.println("AGE: "+age);
        
    }

    public static void main(String[] args) 
    {
        
        Student st = new Student();
        
        st.setData("Divyam",12,19);
        st.getData();
        System.out.println("Divyam Kumar\n500083141");
    }

}


