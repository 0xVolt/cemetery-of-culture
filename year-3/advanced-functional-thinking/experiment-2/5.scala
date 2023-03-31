// Write a scala program to find a contiguous sub-array within a given array of integers which has the largest sum
import scala.io.StdIn.{readInt, readLine}

object Main {
	def main(args: Array[String]): Unit = {
		val range = readRange()
		val arr = readLine("Enter space-separated integers: ").split(" ").map(_.toInt).slice(0, range)
		val (subStart, subEnd, maxSum) = maxSubArray(arr)
		
		println(s"The maximum sub-array is ${arr.slice(subStart, subEnd + 1).mkString("[", ", ", "]")} with sum $maxSum")
	}

	def readRange(): Int = {
		var range = 0
		var validInput = false

		while (!validInput) {
			print("Enter the range of integers to be taken as the input array: ")
			range = readInt()

			if (range > 0) validInput = true
			else println("Invalid range: range must be a positive integer")
		}

		range
	}

	def maxSubArray(arr: Array[Int]): (Int, Int, Int) = {
		var (start, end) = (0, 0)
		var (maxStart, maxEnd) = (0, 0)
		var maxSum = arr(0)
		var sum = arr(0)

		for (i <- 1 until arr.length) {
			if (arr(i) > sum + arr(i)) {
				start = i
				end = i
				sum = arr(i)
			} else {
				end = i
				sum += arr(i)
			}

			if (sum > maxSum) {
				maxStart = start
				maxEnd = end
				maxSum = sum
			}
		}

		(maxStart, maxEnd, maxSum)
	}
}