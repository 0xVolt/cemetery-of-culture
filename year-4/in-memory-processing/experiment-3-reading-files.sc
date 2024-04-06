import org.apache.spark.SparkContext
import org.apache.spark.sql.SparkSession
import org.apache.spark.rdd.RDD

object Main {
    // Function to clean the data imported into the RDD according to the problem statement sheet
    def cleanRDD(rdd: RDD[String]): RDD[String] = {
        // Step 1: Filter out lines that do not contain valid temperature info
        val filteredData = rdd.filter(!_.contains("TEMPERATURE"))

        // Step 2: Extract region, year, and temperature information
        val region = filteredData.map(_.split('|')).map(_(0).substring(0, 5))
        val year = filteredData.map(_.split('|')).map(_(0).substring(5, 9))
        val tempr = filteredData.map(_.substring(11))

        // Step 3: Combine region, year, and temperature into a single RDD
        val joined = region.zip(year).zip(tempr).map { case ((reg, yr), tmp) => s"$reg|$yr|$tmp" }

        joined
    }

    def importAndCleanRDD(spark: SparkSession): RDD[String] = {
        val tData = spark.sparkContext.textFile("./docs/IndiaMaxTemp.txt")

        // println("Printing the imported RDD:\n")
        // tData.collect().foreach(println)

        val tDataCleaned = cleanRDD(tData)

        println("\n\nPre-processed RDD:\n")
        tDataCleaned.collect().foreach(println)

        tDataCleaned
    }

    def question1(spark: SparkSession, tData: RDD[String]): Unit = {
        val januaryMaxTemp: Int = try {
            val filteredRDD = tData
                .filter(line => !line.contains("Keywords"))
                .map(_.split("\\|"))
                .filter(fields => fields.length == 14)
                .map(fields => fields(1).toFloat)

            if (filteredRDD.isEmpty()) {
                println("No temperature data found.")
                Float.NaN.toInt
            } else {
                filteredRDD.max().toInt
            }
        } catch {
            case e: Exception =>
                println(s"An error occurred: ${e.getMessage}")
                Float.NaN.toInt
        }

        println(s"\nThe year in which the temperature of January was maximum in 107 years: $januaryMaxTemp")
    }

    def question2(spark: SparkSession, tData: RDD[String]): Unit = {
        val januaryData = tData.filter(line => line.split("\\|")(1).endsWith("01"))
        val temperatures = januaryData.map(line => line.split("\\|").drop(2).map(_.toDouble))
        val flatTemperatures = temperatures.flatMap(array => array)
        val maxTemperature = flatTemperatures.max()

        println(s"Maximum temperature of January for All India region: $maxTemperature °C")
    }

    def main(args: Array[String]): Unit = {
        val spark: SparkSession = SparkSession.builder()
            .appName("ReadTextFileIntoRDD")
            .master("local[1]") // Set master URL appropriately
            .getOrCreate()

        val tData = importAndCleanRDD(spark)

        // question1(spark, tData)

        question2(spark, tData)

        spark.stop()
    }
}