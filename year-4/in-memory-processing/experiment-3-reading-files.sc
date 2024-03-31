import org.apache.spark.{ SparkSession, SparkContext }

val conf = new SparkConf().setAppName('ReadTextFileIntoRDD').setMaster('local')
val sc = new SparkContext(conf)

// Read text file into RDD
rdd = sc.textFile('./docs/IndiaMaxTemp')

val lineCount = rdd.count()

println(s"Number of lines in the RDD: $lineCount")

sc.stop()