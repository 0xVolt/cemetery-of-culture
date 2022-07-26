l = [1, 2, 3]
ll = [2, 1, 4]

a = list(map(lambda x, y: min(x, y), l, ll))
print(a)