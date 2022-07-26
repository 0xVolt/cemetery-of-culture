def isSmall():
    fin = open('testFile.txt', 'r')

    content = fin.read()
    words = content.split()

    count = 0
    for word in words:
        if len(word) < 4:
            print('{}\n'.format(word))

    fin.close()

isSmall()