// Write a scala program to convert a decimal number to a binary number using a function
import scala.io.StdIn.readLine

object Main {
	def decimalToBinary(decimal: Int): String = {
		if (decimal == 0) {
			"0"
		} else {
			var binary = ""
			var quotient = decimal

			while (quotient > 0) {
				binary = (quotient % 2).toString + binary
				quotient = quotient / 2
			}
			
			binary
		}
	}

	def main(args: Array[String]): Unit = {
		print("Enter a decimal number: ")

		val decimalNumber = readLine().toInt
		val binaryNumber = decimalToBinary(decimalNumber)
		
		println(s"The binary representation of $decimalNumber: $binaryNumber")
	}
}