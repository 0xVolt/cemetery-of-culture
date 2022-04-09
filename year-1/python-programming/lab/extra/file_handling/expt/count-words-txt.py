def countWords():
    fin = open('testFile.txt', 'r')

    content = fin.read()
    # No delimiter splits the string by words
    words = content.split()
    count = 0

    for word in words:
        count += 1

    print('\nNumber of words in the file = {}'.format(count))

    fin.close()

countWords()