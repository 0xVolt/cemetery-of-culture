import org.apache.spark.{SparkConf, SparkContext}

// Create a SparkConf object to configure Spark
val conf = new SparkConf().setAppName("RDDExample").setMaster("local")

// Create a SparkContext object
val sc = new SparkContext(conf)

// Create an RDD using parallelize
val rdd = sc.parallelize(List(1, 2, 3, 4, 5))

// Use collect to return all elements of the RDD
val allElements = rdd.collect()
println("All elements: " + allElements.mkString(", "))

// Use take to return a specified number of elements from the RDD
val firstThreeElements = rdd.take(3)
println("First three elements: " + firstThreeElements.mkString(", "))

// Use first to return the first element of the RDD
val firstElement = rdd.first()
println("First element: " + firstElement)

// Stop the SparkContext
sc.stop()
