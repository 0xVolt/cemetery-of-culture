import scala.io.StdIn.readLine

object Main {
	def main(args: Array[String]): Unit = {
		val str = readLine("Enter a string: ")

		val reversedStr = str.reverse
		
		println(s"The original string is: $str")
		println(s"The reversed string is: $reversedStr")
	}
}
