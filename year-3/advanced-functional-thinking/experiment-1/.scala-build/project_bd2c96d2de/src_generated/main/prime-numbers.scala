



object `prime-numbers` {
/*<script>*/object Main {
    def isPrime(num: Int) : Boolean = (num > 1) && !(2 to scala.math.sqrt(num).toInt).exists(x => num % x == 0)
    
    def main(args: Array[String]) : Unit = {
        var sum = 0;
        
        for (i <- 0 to 5) {
            if (isPrime(i)) {
                sum += i;
            }
        }
        
        println("The sum of the first 5 prime numbers is: " + sum);
    }
}/*</script>*/ /*<generated>*/
def args = `prime-numbers_sc`.args$
  /*</generated>*/
}

object `prime-numbers_sc` {
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
    `prime-numbers`.hashCode() // hasCode to clear scalac warning about pure expression in statement position
  }
}

