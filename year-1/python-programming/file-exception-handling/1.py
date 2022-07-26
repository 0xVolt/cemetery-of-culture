with open('myfile.txt', 'w') as fout:
        fout.write('1000 test1 30\n')
        fout.write('1001 test2 31\n')
        fout.write('1002 test3 32\n')
        # fout closed automatically after with

with open('myfile.txt') as fin: # opening in read mode by default
    print(f'{"ID":<10}{"Name":<10}{"Marks":>5}') # header
    for line in fin:
        sapid, name, marks = line.split() # unpacking strings on line to return a list 
        # split by default does the split on the space
        print(f'{sapid:<10}{name:<10}{marks:>5}')