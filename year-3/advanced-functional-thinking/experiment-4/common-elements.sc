object Main {
	def main(args: Array[String]): Unit = {
		val arr1 = Array("apple", "banana", "orange", "pear")
		val arr2 = Array("banana", "cherry", "orange", "grape")
		
		val common = findCommonElements(arr1, arr2)
		
		println(s"Common elements: ${common.mkString(", ")}")
	}

	def findCommonElements(arr1: Array[String], arr2: Array[String]): Array[String] = {
		arr1.intersect(arr2)
	}
}
