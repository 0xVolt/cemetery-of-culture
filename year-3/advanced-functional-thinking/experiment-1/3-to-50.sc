// Randomly generate a number between 0 - 10, multiply it iteratively so long as the product is less than 50 and display the result.

object Main {
    def iterativeProduct(number: Int): Unit = {
        var product = number;
        var index = 1;

        println("Number: " + product);

        while (product * 4 <= 50) {
            product *= 4;
            index += 1;

            println("Iteration #" + index + ": " + product);
        }
    }

    def main(args: Array[String]): Unit = {
        val rand = new scala.util.Random;
        var number = rand.nextInt(10);

        println("Randomly generated number between 0 - 10: " + number);
        
        iterativeProduct(number);
    }
}