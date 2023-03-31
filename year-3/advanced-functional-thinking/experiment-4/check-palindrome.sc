import scala.io.StdIn.readLine

object Main {
	def isPalindrome(str: String): Boolean = {
		str == str.reverse
	}

	def main(args: Array[String]): Unit = {
		val str = readLine("Enter a string: ")
		val isPal = isPalindrome(str)
		
		if (isPal) {
			println(s"$str is a palindrome.")
		} else {
			println(s"$str is not a palindrome.")
		}
	}
}
