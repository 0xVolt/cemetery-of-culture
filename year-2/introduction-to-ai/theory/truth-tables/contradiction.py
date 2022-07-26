P = [True, False]
result = []

for i in P:
    result.append(P[i] and not P[i])

separator = ','

# print(separator.join(P))
print(*P, sep='\n')

# print(f"P\t: {P}\n~P\t: {[not P[i] for i in P]}\nP^~P    : {result}")