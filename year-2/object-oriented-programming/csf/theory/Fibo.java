class Fibo
{
public static void main(String args[])
{
	int a=0,b=1,c,n=10;
	System.out.print(a + " ");
	System.out.print(b + " ");
	for(int i=2;i<n;i++)
	{	
		c=a+b;
		System.out.print(" " + c);
		a=b;
		b=c;
	}
	
	System.out.println("\n Divyam Kumar \n 500083141");
}
}		