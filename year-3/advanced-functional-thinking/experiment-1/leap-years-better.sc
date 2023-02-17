object Main {  
    def main(args: Array[String]) = {  
        var year: Int = 0;
        
        print("Enter number: ")
        year=scala.io.StdIn.readInt()
        
        if( (year%4==0 && year%100!=0) || (year%4==0 && year%100==0 && year%400==0) )
            println("Given YEAR is leap year")
        else
            println("Given YEAR is not leap year")
    }
}