// 0 - 10, mul by 4 till 50 and print, then take input, then generate

// Define a number from 0 - 10, multiply it iteratively so long as the product is less than 50 and display the result.

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
        iterativeProduct(2);
    }
}