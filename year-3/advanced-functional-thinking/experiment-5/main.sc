object Main {
    def main(args: Array[String]): Unit = {
        question2()
    }

    def question1() {
        val m1 = List(2, 3, 5, 7, 8)
        val result = m1.map(x => x * 3)
        println(result)
    }

    def question2() {
        val m1 = List(5, 12, 3, 13) 
        val result = m1.filter(_ < 10)
        println(result)
    }
}