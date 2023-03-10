// Write a scala program to calculate the average value of an array of element
import scala.io.StdIn.readLine

object Main {
	def main(args: Array[String]): Unit = {
		print("Enter the number of elements in the array: ")
		val n = readLine().toInt

		val arr = new Array[Double](n)

		for (i <- 0 until n) {
			print(s"Enter element ${i + 1}: ")
			arr(i) = readLine().toDouble
		}

		val avg = findAverage(arr)

		println(s"Average value: $avg")
	}

	def findAverage(arr: Array[Double]): Double = {
		val sum = arr.sum
		sum / arr.length
	}
}