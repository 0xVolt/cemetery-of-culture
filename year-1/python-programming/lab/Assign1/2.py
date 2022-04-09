# Code by Desh Iyer

def func(l):
    count = 0
    for c in l:
        if (c.isupper()):
            count +=1
    return count

f1 = open('myfile.txt', 'r')

l = f1.read()

print('\n Number of Upper Case alphabets : ', func(l))
print('\n')