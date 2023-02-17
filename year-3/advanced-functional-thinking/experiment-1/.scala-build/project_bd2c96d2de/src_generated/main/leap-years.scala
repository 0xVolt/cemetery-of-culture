



object `leap-years` {
/*<script>*/// Print the leap years given a range of years

object Main {
    def main(args: Array[String]): Unit = {
        var startYear = 2000;
        var endYear = 2023;

        var j = 0;

        println("Printing the leap years between 2000 and 2023:");
        for (i <- startYear to endYear) {
            if (i % 4 == 0 || i % 100 == 0) {
                    println(i);
                    j += 1;
                }
            }
        
        if(j == 0) {
            println("There are no leap years in that range");
        }
    }
}
/*</script>*/ /*<generated>*/
def args = `leap-years_sc`.args$
  /*</generated>*/
}

object `leap-years_sc` {
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
    `leap-years`.hashCode() // hasCode to clear scalac warning about pure expression in statement position
  }
}

