



object `1-to-50` {
/*<script>*/// Define a number from 0 - 10, multiply it iteratively so long as the product is less than 50 and display the result.

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
        iterativeProduct(2);
    }
}/*</script>*/ /*<generated>*/
def args = `1-to-50_sc`.args$
  /*</generated>*/
}

object `1-to-50_sc` {
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
    `1-to-50`.hashCode() // hasCode to clear scalac warning about pure expression in statement position
  }
}

