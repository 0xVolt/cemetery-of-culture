def testFunc(*args):
    return sum(args) / len(args)

ls = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(testFunc(*ls))