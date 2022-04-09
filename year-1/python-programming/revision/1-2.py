def count(lines):
    count = 0
    for line in lines:
        for i in line:
            if i.isupper():
                count += 1

    return count

fin = open('C:\\Users\\Volt\\Code\\uni\\year-1\\python-programming\\a\\myfile.txt', 'r')

lines = fin.readlines()

print(count(lines))

fin.close()