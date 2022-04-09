def countLines():
    fin = open('testFile.txt', 'r')
    content = fin.read()
    # Split takes a delimiter that specifies how the string is split
    # Using '\n' as delim, we split the file according to lines and then we iterate over the list
    lines = content.split('\n')
    count = 0

    for line in lines:
        if line[0] == 'A':
            count += 1

    print('\n\nThe number of lines in the file starting with "A" = {}'.format(count))
    fin.close()

countLines()