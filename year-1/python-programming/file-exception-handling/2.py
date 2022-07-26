with open('myfile.txt', 'w') as fout:
        fout.write('1000 test1 30\n')
        fout.write('1001 test2 31\n')
        fout.write('1002 test3 32\n')
        # fout closed automatically after with

# Displaying
with open('myfile.txt') as fin: # opening in read mode by default
    print(f'{"ID":<10}{"Name":<10}{"Marks":>5}') # header
    for line in fin:
        sapid, name, marks = line.split() # unpacking strings on line to return a list 
        # split by default does the split on the space
        print(f'{sapid:<10}{name:<10}{marks:>5}')

print("\n\n-----------------------------\n\n")

# Changing
with open('temp.txt', 'w') as temp, open('myfile.txt') as fin:
    for line in fin:
        sapid, name, marks = line.split()
        if name == 'test1':
            temp.write('1001 Vader 40 (changed)\n')
        else:
            temp.write(line)

# Opening two file with 'with'
# Modify record where id == 1001 to change name to Vader
""" with open('temp.txt', 'w') as temp, open('myfile.txt') as fin:
    for line in fin:
        sapid, name, marks = line.split()
        if name == 'test1':
            modLine = ' '.join([sapid, 'changed value!', marks]) # creates a single string which is space separated
            temp.write(modLine+'')
        else:
            temp.write(line) """

with open('temp.txt') as fin: # opening in read mode by default
    print(f'{"ID":<10}{"Name":<10}{"Marks":>5}') # header
    for line in fin:
        sapid, name, marks = line.split() # unpacking strings on line to return a list 
        # split by default does the split on the space
        print(f'{sapid:<10}{name:<10}{marks:>5}')

import os
os.remove('myfile.txt')
os.remove('temp.txt', 'myfile.txt')