ls = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

elt = int(input("Enter element to delete from list (1-10): "))

new_ls = [i for i in ls if i != elt]
print('The updated list is:\n' + str(new_ls))