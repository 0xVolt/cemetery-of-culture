object Main {
	def factorial(n: Int): Int = {
		if (n == 0) 1
		else n * factorial(n - 1)
	}

	def seriesSum(n: Int): Double = {
		if (n == 1) 1
		else factorial(n) / n + seriesSum(n - 1)
	}

	def main(args: Array[String]): Unit = {
		val n = 5

		val sum = seriesSum(n)
		
		println(s"The sum of the series 1!/1 + 2!/2 + 3!/3 + 4!/4 + 5!/5 is: $sum")
	}
}