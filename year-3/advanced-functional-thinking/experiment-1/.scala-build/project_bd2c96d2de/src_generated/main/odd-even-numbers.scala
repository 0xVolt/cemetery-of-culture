



object `odd-even-numbers` {
/*<script>*/// A program to print odd and even numbers from a range

object Main {
    def main(args: Array[String]): Unit = {
        val numbers = List(1, 2, 3, 4, 5, 7, 9, 11, 14, 12, 16)

        println("Original list:")
        println(numbers)   
        
        val even_numbers = numbers.filter(_ % 2 ==0) 
        println("Even number of the said list:")
        println(even_numbers)
        
        val odd_numbers = numbers.filter(_ % 2 != 0) 
        println("Odd number of the said list:")
        println(odd_numbers)   
    }  
}

/*</script>*/ /*<generated>*/
def args = `odd-even-numbers_sc`.args$
  /*</generated>*/
}

object `odd-even-numbers_sc` {
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
    `odd-even-numbers`.hashCode() // hasCode to clear scalac warning about pure expression in statement position
  }
}

