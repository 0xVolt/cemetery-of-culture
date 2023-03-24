object Main {
	def factorial(n: Int): Int = {
		if (n < 0) {
			throw new IllegalArgumentException("Factorial of negative numbers is undefined.")
		} else if (n == 0) {
			1
		} else {
			n * factorial(n - 1)
		}
	}

	def main(args: Array[String]): Unit = {
		println("Enter a non-negative number to calculate its factorial:")

		val n = scala.io.StdIn.readInt()
		
		try {
			println(s"The factorial of $n is: " + factorial(n))
		} catch {
			case illegalArgExcept: IllegalArgumentException => {
				println(illegalArgExcept);
			}
		}
	}
}
