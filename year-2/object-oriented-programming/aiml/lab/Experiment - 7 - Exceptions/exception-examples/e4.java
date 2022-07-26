import java.io.DataInputStream;

class xyz {
    public int read1() { 
        int i=2;
        String a;

        try{
            DataInputStream o = new DataInputStream(System.in);
            a = o.readLine();
            i = Integer.parseInt(a);
        }

        catch (Exception t) { 
            System.out.println("Not a number" + t); 
        }
        return i;
    }
}

public class e4 {
    public static void main(String[] args) {
        xyz O = new xyz();

        int i, a; 
        int[] f = {10, 20, 30, 40};
        a = O.read1();
    
        try {
            System.out.println(f[a]);
            int x = 25/0;
        } catch(Exception t) { 
            System.out.println("stop" + t);
        }
    }
}