from pyspark.sql import SparkSession

# Initialize SparkSession
spark = SparkSession.builder \
    .appName("RDDTransformations") \
    .master("local[*]") \
    .getOrCreate()

# Create an RDD
data = [1, 2, 3, 4, 5]
rdd = spark.sparkContext.parallelize(data)

squared_rdd = rdd.map(lambda x: x * x)
print(squared_rdd.collect())  # Output: [1, 4, 9, 16, 25]