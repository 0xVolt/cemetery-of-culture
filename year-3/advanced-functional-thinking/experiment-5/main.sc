object Main {
    def main(args: Array[String]): Unit = {
        question3()
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

    def question3() {
        val x = List(1, 2, 3, 4).map(_ + 10).filter(_ % 2 == 0).map(_ * 3)
        println(x)
    }

    def question4() {
        val m1 = Map(3 -> "geeks", 4 -> "for", 2 -> "cs")
        val result = m1.transform((key,value) => value.toUpperCase)
        println(result)
    }

    def question5() {
        val m1 = List(2, 3, 5, 7, 8)
        val result = m1.map(x => x*3)
        println(result)
    }

    def question6() {
        val m1 = List(5, 12, 3, 13)
        val result = m1.filter(_ < 10)
        println(result)
    }

    def question7() {
        val x = List(1,2,3,4).map(_ + 10).filter(_ % 2 == 0).map(_ * 3)
        println(x)
    }

    def question8() {
        val m1 = Map(3 -> "geeks", 4 -> "for", 2 -> "cs")
        val result = m1.transform((key,value) => value.toUpperCase)
        println(result)
    }

    def question9() {
        val m1 = Map(3 -> "geeks", 4 -> "for", 2 -> "cs")
        val result = m1.toList
        println(result)
    }

    def question10() {
        val name = Seq("Nidhi", "Singh")
        val result1 = name.map(_.toLowerCase)
        println(result1)
        val result2 = result1.flatten
        println(result2)
        val result3 = name.flatMap(_.toUpperCase)
        println(result3)
    }

    def question11() {
        val list = List(4, 7, 9)
        def f(x:Int) = List(x*2, x, x*3)
        val result1 = list.Map(y => f(y))
        println(result1)
        val result2 = list.flatMap(y => f(y))
        println(result2)
    }

    def question12() {
        val collection = List(1, 5, 7, 8)
        val new_collection = collection.map(x => (x,1))
        val res = new_collection.reduce( (a,b) => ( a._1 + b._1, a._2 + b._2 ) )
        println(res)
        println("Average="+ res._1/res._2.toFloat)
    }

    def question13() {
        var a = 5
        def fun() = {
            a += 1;
            a
        }
    }

    def question14() {
        lazy val seq1 = Stream.continually( fun() )
        (seq1 take 10) foreach {
            x => println(x)
        }
    }
}