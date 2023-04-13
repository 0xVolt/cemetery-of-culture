object Main {
    def main(args: Array[String]): Unit = {
        var string1 = Stream(1, 2, 3)
        var string2 = Stream(5, 6, 7)
        var newString = string1.append(string2)
        
        println(s"Stream: $newString")

        // var length = newString.length
    }
}