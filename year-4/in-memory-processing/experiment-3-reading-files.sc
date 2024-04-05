import org.apache.spark.{SparkConf, SparkContext}

object Main {
    def main(args: Array[String]): Unit = {
        val conf = new SparkConf().setAppName("ReadTextFileIntoRD").setMaster("local")
        val spark = new SparkContext(conf)
    
        val tData = spark.textFile("./docs/IndiaMaxTemp.txt")

        tData.collect().foreach(println)

        val januaryMaxTemp = try {
            val filteredRDD = tData
                .filter(line => !line.contains("Keywords"))
                .map(_.split("\\|"))
                .filter(fields => fields.length == 14)
                .map(fields => fields(1).toFloat)
            
            if (filteredRDD.isEmpty()) {
                println("No temperature data found.")
                Float.NaN // or any default value you prefer
            } else {
                filteredRDD.max()
            }
        } catch {
            case e: Exception =>
                println(s"An error occurred: ${e.getMessage}")
                Float.NaN // or any default value you prefer
        }

        println(s"Max temperature of January in 107 years: $januaryMaxTemp")

        spark.stop()
    }
}