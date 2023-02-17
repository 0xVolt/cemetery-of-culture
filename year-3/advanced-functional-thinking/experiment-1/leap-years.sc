// Print the leap years given a range of years

object Main {
    def main(args: Array[String]): Unit = {
        var startYear = 2000;
        var endYear = 2023;

        var j = 0;

        println("Printing the leap years between 2000 and 2023:");
        for (i <- startYear to endYear) {
            if (i % 4 == 0 || i % 100 == 0) {
                    println(i);
                    j += 1;
                }
            }
        
        if(j == 0) {
            println("There are no leap years in that range");
        }
    }
}
