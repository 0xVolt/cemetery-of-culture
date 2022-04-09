def convert_name(name):
    name = name[0] + '. '
    name = name.upper()

    return name

if __name__ == '__main__':
    full_name = input("Enter a person's full name: ")

    # Convert string into list
    name_list = full_name.split()
    n = len(name_list)

    for i in range(n - 1):
        name_list[i] = convert_name(name_list[i])
    
    name_list[n - 1] = name_list[n - 1].capitalize()

    # Printing list as a sentence
    print(''.join(map(str, name_list)))