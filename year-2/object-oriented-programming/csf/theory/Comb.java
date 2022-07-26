import java.util.*;
class Comb
{
public static void main(String[] args) 
{
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();    
    int b = in.nextInt();
    int c = in.nextInt();
    int [] d = {a,b,c};
    for(int i= 0; i<3;i++)
    {
        for(int j= 0; j<3;j++)
        {
            for(int k= 0; k<3;k++)
            {
                if(i!=j && j!=k && k!=i)   
                System.out.println(d[i]+" "+d[j]+" "+d[k]);
            }
        }
   }
   System.out.println("DivyamKumar \n500083141");
}
}
