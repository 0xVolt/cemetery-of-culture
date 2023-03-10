// Write a scala program to find the maximum and minimum value of an array of integers
import scala.io.StdIn.readLine

object Main {
	def main(args: Array[String]): Unit = {
		print("Enter the number of elements in the array: ")
		val n = readLine().toInt

		val arr = new Array[Int](n)

		for (i <- 0 until n) {
			print(s"Enter element ${i + 1}: ")
			arr(i) = readLine().toInt
		}

		val (max, min) = findMaxMin(arr)

		println(s"Maximum value: $max")
		println(s"Minimum value: $min")
	}

	def findMaxMin(arr: Array[Int]): (Int, Int) = {
		var max = arr(0)
		var min = arr(0)
		
		for (i <- 1 until arr.length) {
				if (arr(i) > max) {
					max = arr(i)
				}

				if (arr(i) < min) {
					min = arr(i)
				}
		}
		(max, min)
	}
}

