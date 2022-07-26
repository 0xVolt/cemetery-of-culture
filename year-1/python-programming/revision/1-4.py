def countEO(file, letter):
    count = 0

    with open(file, 'r') as fin:
        text = fin.read()
        text = text.upper()
        count = text.count(letter)

    return count

countE = countEO('C:\\Users\\Volt\\Code\\uni\\year-1\\python-programming\\a\\myfile.txt', 'E')
countO = countEO('C:\\Users\\Volt\\Code\\uni\\year-1\\python-programming\\a\\myfile.txt', 'O')

print("E or e: {}\nO or o: {}".format(countE, countO))