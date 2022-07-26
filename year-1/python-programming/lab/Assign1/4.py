# Code by Desh Iyer

def countOE(file, letter):
    file = open(file, 'r')

    text = file.read()
    text = text.upper()

    return text.count(letter)

print('Occurence of E or e : ')
print(countOE('myfile.txt', 'E'))
print('Occurence of O or o : ')
print(countOE('myfile.txt', 'O'))