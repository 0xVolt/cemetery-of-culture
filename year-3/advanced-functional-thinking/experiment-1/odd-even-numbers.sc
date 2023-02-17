// A program to print odd and even numbers from a range

object Main {
    def main(args: Array[String]): Unit = {
        val numbers = List(1, 2, 3, 4, 5, 7, 9, 11, 14, 12, 16)

        println("Original list:")
        println(numbers)   
        
        val even_numbers = numbers.filter(_ % 2 ==0) 
        println("Even number of the said list:")
        println(even_numbers)
        
        val odd_numbers = numbers.filter(_ % 2 != 0) 
        println("Odd number of the said list:")
        println(odd_numbers)   
    }  
}

