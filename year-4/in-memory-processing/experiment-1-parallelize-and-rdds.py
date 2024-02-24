from pyspark import SparkContext

def main():
    # Create a SparkContext object
    sc = SparkContext("local", "RDDExample")

    # Create an RDD using parallelize
    rdd = sc.parallelize([1, 2, 3, 4, 5])

    # Use collect to return all elements of the RDD
    all_elements = rdd.collect()
    print("All elements:", all_elements)

    # Use take to return a specified number of elements from the RDD
    first_three_elements = rdd.take(3)
    print("First three elements:", first_three_elements)

    # Use first to return the first element of the RDD
    first_element = rdd.first()
    print("First element:", first_element)

    # Stop the SparkContext
    sc.stop()

if __name__ == "__main__":
    main()
