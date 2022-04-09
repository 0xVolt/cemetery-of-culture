class Consover {

    int len, bre , hei;

    Consover(int a, int b, int c) {
        len = a;
        bre = b;
        hei = c;
    }

    Consover(int a, int b){
        len = a;
        bre= b;
    }

    int area(){
       int ar = len * bre;
       return ar;
    }

    int vol(){
        int vol = len * bre * hei;
        return vol;
    }
    public static void main(String[] args) {
        Consover a1 = new Consover(20 , 40 , 60);
        Consover a2 = new Consover(20 , 40);
    
        int  ar = a2.area();
        int vol = a1.vol(); 
        System.out.println("\nDivyam Kumar");
        System.out.println("500083141");
        System.out.println("Area = " + ar);
        System.out.println("Volume = " + vol);
        }
    
    
    
}
    
