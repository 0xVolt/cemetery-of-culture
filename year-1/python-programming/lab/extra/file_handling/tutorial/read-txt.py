# Opening file in read mode
fin = open('testFile.txt', 'r')

print('Displaying file content!\n\n')
# Using the read() function 
print(fin.read())

fin.close()