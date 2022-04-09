def readLetters():
    fin = open('testFile.txt', 'r')

    content = fin.read()
    words = content.split()

    count = 0

    for word in words:
        for letter in word:
            if letter.isupper():
                count += 1

    fin.close()

    return count

numberUpperCase = readLetters()
print(f'The number of upper case letters = {numberUpperCase}')