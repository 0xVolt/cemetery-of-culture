def count_char(char):
    count = 0

    with open('test.txt', 'r') as fin:
        for word in fin:
            for letter in word:
                if char == letter:
                    count += 1

    return count

    
if __name__ == "__main__":
    char = input('Enter character to count: ')

    cnt = count_char(char)
    
    print(f'Number of occurences of {char} = {cnt}')