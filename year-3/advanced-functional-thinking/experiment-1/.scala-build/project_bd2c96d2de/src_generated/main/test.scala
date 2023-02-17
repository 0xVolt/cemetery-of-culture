



object test {
/*<script>*/object Sample {  
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
}/*</script>*/ /*<generated>*/
def args = test_sc.args$
  /*</generated>*/
}

object test_sc {
  private var args$opt0 = Option.empty[Array[String]]
  def args$set(args: Array[String]): Unit = {
    args$opt0 = Some(args)
  }
  def args$opt: Option[Array[String]] = args$opt0
  def args$: Array[String] = args$opt.getOrElse {
    sys.error("No arguments passed to this script")
  }
  def main(args: Array[String]): Unit = {
    args$set(args)
    test.hashCode() // hasCode to clear scalac warning about pure expression in statement position
  }
}

