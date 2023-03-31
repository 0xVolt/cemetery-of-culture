object Main {
	def fibonacci(n: Int): Int = {
		if (n < 0) {
			throw new IllegalArgumentException("The number of terms needs to be a positive integer!")
		}

		if (n <= 1) n
		else fibonacci(n - 1) + fibonacci(n - 2)
	}

	def main(args: Array[String]): Unit = {
		println("Enter the number of terms to generate in the Fibonacci series: ")
		
		val n = scala.io.StdIn.readInt()
		
		println(s"The first $n terms of the Fibonacci series are:")
		
		try {
			for (i <- 0 until n) {
				println(fibonacci(i))
			}
		} catch {
			case i: IllegalArgumentException => {
				println(i)
			}
		}

	}
}