import org.apache.spark.{ SparkConf, SparkContext }

val conf = new SparkConf().setAppName("ReadTextFileIntoRD").setMaster("local")
val sc = new SparkContext(conf)

val temperatureData = sc.textFile("./docs/IndiaMaxTemp.txt")

temperatureData.collect().foreach(println)

val lineCount = temperatureData.count()
println(s"Number of lines in the RDD: $lineCount")

// Answer to question 1
val januaryMaxTemp = temperatureData.filter(line => !line.contains("Keywords")).map(_.split("\\|")).filter(fields => fields.length == 14).map(fields => fields(1).toFloat).max()

println(s"Max temperature of January in 107 years: $januaryMaxTemp")

sc.stop()