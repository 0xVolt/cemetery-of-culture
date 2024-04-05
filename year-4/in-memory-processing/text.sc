import org.apache.spark.sql.SparkSession

object MySparkProgram {
  def main(args: Array[String]): Unit = {
    val spark = SparkSession.builder()
      .appName("MySparkProgram")
      .getOrCreate()

    val data = spark.range(1, 100)
    println("Count of elements: " + data.count())

    spark.stop()
  }
}