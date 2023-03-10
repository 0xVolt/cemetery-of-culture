// Write a scala program to swap two numbers using a function
import scala.io.StdIn.readLine

object Main {
	def swapNumbers(a: Int, b: Int): (Int, Int) = {
		(b, a)
	}

	def main(args: Array[String]): Unit = {
		print("Enter the first number: ")
		val x = readLine().toInt

		print("Enter the second number: ")
		val y = readLine().toInt

		println(s"Before swapping: x = $x, y = $y")
		val (newX, newY) = swapNumbers(x, y)

		println(s"After swapping: x = $newX, y = $newY")
	}
}

