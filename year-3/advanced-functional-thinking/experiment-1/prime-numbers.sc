object Main {
    def isPrime(num: Int) : Boolean = (num > 1) && !(2 to scala.math.sqrt(num).toInt).exists(x => num % x == 0)
    
    def main(args: Array[String]) : Unit = {
        var sum = 0;
        
        for (i <- 0 to 5) {
            if (isPrime(i)) {
                sum += i;
            }
        }
        
        println("The sum of the first 5 prime numbers is: " + sum);
    }
}