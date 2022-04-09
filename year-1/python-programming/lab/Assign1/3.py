# Code by Desh Iyer

def gtoq():
    with open('myfile.txt', 'r') as file :
        text = file.read()

    text = text.replace('g', 'q')

    print('Changed String is : ', text)
    
    with open('myfile.txt', 'w') as file:
        file.write(text)

gtoq()