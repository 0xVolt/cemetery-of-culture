import scala.io.StdIn.readLine

object ArraySorter {
	def sortNumericArray(arr: Array[Int]): Array[Int] = {
		arr.sorted
	}

	def sortStringArray(arr: Array[String]): Array[String] = {
		arr.sorted
	}

	def main(args: Array[String]): Unit = {
		val n = readLine("Enter the size of the numeric array: ").toInt
		val numericArray = Array.ofDim[Int](n)
		
		for (i <- 0 until n) {
			numericArray(i) = readLine(s"Enter element $i of the numeric array: ").toInt
		}
		
		val sortedNumericArray = sortNumericArray(numericArray)
		
		println(s"The sorted numeric array is: ${sortedNumericArray.mkString(", ")}")

		val m = readLine("Enter the size of the string array: ").toInt
		val stringArray = Array.ofDim[String](m)
		
		for (i <- 0 until m) {
			stringArray(i) = readLine(s"Enter element $i of the string array: ")
		}
		
		val sortedStringArray = sortStringArray(stringArray)
		
		println(s"The sorted string array is: ${sortedStringArray.mkString(", ")}")
	}
}
