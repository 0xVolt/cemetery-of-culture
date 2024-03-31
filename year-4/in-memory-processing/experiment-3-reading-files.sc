import org.apache.spark.{ SparkConf, SparkContext }

val conf = new SparkConf().setAppName("ReadTextFileIntoRD").setMaster("local")
val sc = new SparkContext(conf)

// Read text file into RDD
val rdd = sc.textFile("./docs/IndiaMaxTemp.txt")

val lineCount = rdd.count()

println(s"Number of lines in the RDD: $lineCount")

sc.stop()