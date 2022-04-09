def gtoq():
    with open('C:\\Users\\Volt\\Code\\uni\\year-1\\python-programming\\a\\myfile.txt', 'r') as fin:
        text = fin.read()

    text = text.replace('g', 'q')

    with open('C:\\Users\\Volt\\Code\\uni\\year-1\\python-programming\\a\\myfile.txt', 'w') as fout:
        fout.write(text)

gtoq()