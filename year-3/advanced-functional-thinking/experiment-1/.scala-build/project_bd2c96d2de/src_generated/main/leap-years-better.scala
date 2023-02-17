



object `leap-years-better` {
/*<script>*/object Main {  
    def main(args: Array[String]) = {  
        var year: Int = 0;
        
        print("Enter number: ")
        year=scala.io.StdIn.readInt()
        
        if( (year%4==0 && year%100!=0) || (year%4==0 && year%100==0 && year%400==0) )
            println("Given YEAR is leap year")
        else
            println("Given YEAR is not leap year")
    }
}/*</script>*/ /*<generated>*/
def args = `leap-years-better_sc`.args$
  /*</generated>*/
}

object `leap-years-better_sc` {
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
    `leap-years-better`.hashCode() // hasCode to clear scalac warning about pure expression in statement position
  }
}

