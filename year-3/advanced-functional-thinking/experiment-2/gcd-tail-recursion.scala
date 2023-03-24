object Main {
	def gcd(a: Int, b: Int): Int = {
		def gcdTail(a: Int, b: Int, res: Int): Int = {
			if (b == 0) res
			else gcdTail(b, a % b, b)
		}

		gcdTail(a, b, a)
	}

	def main(args: Array[String]): Unit = {
		println("Enter two numbers (on two lines) to find their GCD: ")

		val a = scala.io.StdIn.readInt()
		val b = scala.io.StdIn.readInt()

		println(s"The GCD of $a and $b is: " + gcd(a, b))
	}
}