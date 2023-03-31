import scala.collection.mutable.Map
import scala.io.StdIn.readLine

object Main {
	def findMaxOccurringChar(str: String): Char = {
		val charMap = Map[Char, Int]()
		var maxChar = ' '
		var maxCount = 0

		for (char <- str if char != ' ') {
			charMap(char) = charMap.getOrElse(char, 0) + 1

			if (charMap(char) > maxCount) {
				maxChar = char
				maxCount = charMap(char)
			}
		}

		maxChar
	}

	def main(args: Array[String]): Unit = {
		val str = readLine("Enter a string: ")
		val maxChar = findMaxOccurringChar(str)

		println(s"The maximum occurring letter in $str is '$maxChar'")
	}
}
