# Code by Desh Iyer

def func(l):
    count = 0 
    for line in l:
        if line[0] == 'A':
            count += 1
    return count

f1 = open('myfile.txt', 'r')

l = f1.readlines()

print('\n Number of Lines starting with A : ', func(l))
print('\n')