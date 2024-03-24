from pyspark.sql import SparkSession

# Initialize SparkSession
spark = SparkSession.builder \
    .appName("RDDTransformations") \
    .master("local[*]") \
    .getOrCreate()

# Create an RDD
data = [1, 2, 3, 4, 5]
rdd = spark.sparkContext.parallelize(data)

# squared_rdd = rdd.map(lambda x: x * x)
# print(squared_rdd.collect())  # Output: [1, 4, 9, 16, 25]

# flat_mapped_rdd = rdd.flatMap(lambda x: [x, x * 2])
# print(flat_mapped_rdd.collect())  # Output: [1, 2, 2, 4, 3, 6, 4, 8, 5, 10]

filtered_rdd = rdd.filter(lambda x: x % 2 == 0)
print(f'Filtered RDD: {filtered_rdd.collect()}')  # Output: [2, 4]

distinct_rdd = rdd.union(spark.sparkContext.parallelize([3, 4, 5, 6])).distinct()
print(f'Distinct RDD: {distinct_rdd.collect()}')  # Output: [1, 2, 3, 4, 5, 6]

pair_rdd = rdd.map(lambda x: (x % 2, x))
grouped_rdd = pair_rdd.groupByKey().mapValues(list)
print(f'Grouped by RDD: {grouped_rdd.collect()}')  # Output: [(0, [2, 4]), (1, [1, 3, 5])]

sorted_rdd = pair_rdd.sortByKey()
print(f'Sort by RDD: {sorted_rdd.collect()}')  # Output: [(0, 2), (0, 4), (1, 1), (1, 3), (1, 5)]

sum_by_key_rdd = pair_rdd.reduceByKey(lambda x, y: x + y)
print(f'Reduce by RDD: {sum_by_key_rdd.collect()}')  # Output: [(0, 6), (1, 9)]