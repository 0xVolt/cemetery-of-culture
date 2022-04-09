# Writing to a file
fout = open('testFile.txt', 'w')
fout.write("This is a test to see how to use the write() function in python.\nThis is a test!")

# Reading a file
fin = open('testFile.txt', 'r')
print(fin.read())

# Closing files
fout.close()
fin.close()