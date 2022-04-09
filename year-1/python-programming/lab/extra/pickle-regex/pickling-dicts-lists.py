import pickle

mydir = "C:/Users/Volt/code/uni/year-1/python-programming/lab/pickle-regex"

month_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
month_dict = {'Jan': 31, 'Feb': 28, 'Mar': 31}

with open(mydir + 'months', 'wb') as outf:
    pickle.dump(month_dict, outf)
    pickle.dump(month_list, outf)

with open(mydir + 'months', 'rb') as inf:
    read_dict = pickle.load(inf)
    read_list = pickle.load(inf)

    if read_dict == month_dict:
        print('Dictionaries are same (==)!')
    
    if read_dict is month_dict:
        print('Dictionaries are same (is)!')
    else:
        print('Dictionaries do not show up as same when using "is"')

    if read_list == month_list:
        print('Lists are same (==)!')

    if read_list == month_list:
        print('Lists are same (is)!')