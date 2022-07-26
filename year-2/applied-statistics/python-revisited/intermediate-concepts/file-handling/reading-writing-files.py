text_input = input('Enter text to write to file: ')

fout = open('test.txt', 'w')
fout.write(text_input)
fout.close()

with open('test.txt', 'r') as fin:
    print(fin.read())