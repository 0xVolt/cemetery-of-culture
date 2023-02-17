object Sample {  
    def main(args:Array[String]): Unit={  
        var num1:Int=0
        var num2:Int=4
        var mult:Int=0
        var count:Int=0

        print("Enter number1: ")
        num1=scala.io.StdIn.readInt()
        
        count = 1
        
        while(count<=num2)
        {
            mult += num1
            count=count+1
        }
        
        for (mult <- 0 to 50 by 1)
        {
            println(mult*num1)
        }
    }  
}