# from pyspark.sql import SparkSession

# # Initialize SparkSession
# spark = SparkSession.builder \
#     .appName("RDDTransformations") \
#     .master("local[*]") \
#     .getOrCreate()

# # Create an RDD
# data = [1, 2, 3, 4, 5]
# rdd = spark.sparkContext.parallelize(data)

# # squared_rdd = rdd.map(lambda x: x * x)
# # print(squared_rdd.collect())  # Output: [1, 4, 9, 16, 25]

# # flat_mapped_rdd = rdd.flatMap(lambda x: [x, x * 2])
# # print(flat_mapped_rdd.collect())  # Output: [1, 2, 2, 4, 3, 6, 4, 8, 5, 10]

# filtered_rdd = rdd.filter(lambda x: x % 2 == 0)
# print(f'Filtered RDD: {filtered_rdd.collect()}')  # Output: [2, 4]

# distinct_rdd = rdd.union(spark.sparkContext.parallelize([3, 4, 5, 6])).distinct()
# print(f'Distinct RDD: {distinct_rdd.collect()}')  # Output: [1, 2, 3, 4, 5, 6]

# pair_rdd = rdd.map(lambda x: (x % 2, x))
# grouped_rdd = pair_rdd.groupByKey().mapValues(list)
# print(f'Grouped by RDD: {grouped_rdd.collect()}')  # Output: [(0, [2, 4]), (1, [1, 3, 5])]

# sorted_rdd = pair_rdd.sortByKey()
# print(f'Sort by RDD: {sorted_rdd.collect()}')  # Output: [(0, 2), (0, 4), (1, 1), (1, 3), (1, 5)]

# sum_by_key_rdd = pair_rdd.reduceByKey(lambda x, y: x + y)
# print(f'Reduce by RDD: {sum_by_key_rdd.collect()}')  # Output: [(0, 6), (1, 9)]

from pyspark.sql import SparkSession

# Create a SparkSession
spark = SparkSession.builder \
    .appName("RDDActions") \
    .getOrCreate()

# Create an RDD
data = [1, 2, 3, 4, 5]
rdd = spark.sparkContext.parallelize(data)

from operator import add

sum_result = rdd.reduce(add)
print(f'Reduced RDD: {sum_result}')  # Output: 15 (1 + 2 + 3 + 4 + 5)

collected_data = rdd.collect()
print(f'Collected data: {collected_data}')  # Output: [1, 2, 3, 4, 5]

num_elements = rdd.count()
print(f'Count: {num_elements}')  # Output: 5

first_element = rdd.first()
print(f'First: {first_element}')  # Output: 1

first_three = rdd.take(3)
print(f'Taken first 3: {first_three}')  # Output: [1, 2, 3]

counted_values = rdd.countByValue()
print('Counted by value: ', counted_values)  # Output: defaultdict(<class 'int'>, {1: 1, 2: 1, 3: 1, 4: 1, 5: 1})

pair_rdd = rdd.map(lambda x: (x % 2, x))
counted_keys = pair_rdd.countByKey()
print('Counted by keys: ', counted_keys)  # Output: defaultdict(<class 'int'>, {1: 3, 0: 2})

seq_op = lambda acc, val: acc + val
comb_op = lambda acc1, acc2: acc1 + acc2

agg_result = rdd.aggregate(0, seq_op, comb_op)
print('Aggregated result: ', agg_result)  # Output: 15 (same as sum, because initial value is 0)