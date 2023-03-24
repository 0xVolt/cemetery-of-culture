object Main {
	def gcd(a: Int, b: Int): Int = {
		if (b == 0) a
		else gcd(b, a % b)
	}

	def main(args: Array[String]): Unit = {
		println("Enter two numbers to find their GCD: ")

		val a = scala.io.StdIn.readInt()
		val b = scala.io.StdIn.readInt()

		println(s"The GCD of $a and $b is: " + gcd(a, b))
	}
}