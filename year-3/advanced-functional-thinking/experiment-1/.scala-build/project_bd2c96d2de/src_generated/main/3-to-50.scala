



object `3-to-50` {
/*<script>*/// Randomly generate a number between 0 - 10, multiply it iteratively so long as the product is less than 50 and display the result.

object Main {
    def iterativeProduct(number: Int): Unit = {
        var product = number;
        var index = 1;

        println("Number: " + product);

        while (product * 4 <= 50) {
            product *= 4;
            index += 1;

            println("Iteration #" + index + ": " + product);
        }
    }

    def main(args: Array[String]): Unit = {
        val rand = new scala.util.Random;
        var number = rand.nextInt(10);

        println("Randomly generated number between 0 - 10: " + number);
        
        iterativeProduct(number);
    }
}/*</script>*/ /*<generated>*/
def args = `3-to-50_sc`.args$
  /*</generated>*/
}

object `3-to-50_sc` {
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
    `3-to-50`.hashCode() // hasCode to clear scalac warning about pure expression in statement position
  }
}

