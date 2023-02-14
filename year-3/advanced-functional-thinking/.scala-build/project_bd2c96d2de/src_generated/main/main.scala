



object main {
/*<script>*/object Main extends App {
    println("Hello, world")
}/*</script>*/ /*<generated>*/
def args = main_sc.args$
  /*</generated>*/
}
object main_sc$$alias {
  val alias = main
}
object main_sc {
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
    main_sc$$alias.alias.hashCode() // hasCode to clear scalac warning about pure expression in statement position
  }
}

