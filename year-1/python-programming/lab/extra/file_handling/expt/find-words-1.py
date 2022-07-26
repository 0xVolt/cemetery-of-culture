def endingWithR():
    fin = open('testFile.txt', 'r')

    content = fin.read()
    words = content.split()

    count = 0
    for word in words:
        if word[-1] == 'r':
            count += 1

    fin.close()

    return count

numberOfWords = endingWithR()
print('Number of words ending with "r" = {}'.format(numberOfWords))