"""Command line utility for creating a file that contains many copies of a
single word. 

Usage: word_writer.py FILE_NAME WORD COUNT

Example: 
$ python3 word_writer.py hellos.txt hello 3

Would result in the creation of a file named 'hellos.txt' with the 
contents: 

hello
hello
hello

This utility will do nothing if the file already exists.

This code available at : https://w3.cs.jmu.edu/lam2mo/cs240_2014_08/files/word_writer.py
"""

import sys

def print_words(file_name, word, count):
    """ Prints a given word to a newly created file some number of times. 

    Arguments:
        file_name --> A string containing the file name. 
        word      --> A string containing the word to write. 
        count     --> An integer indicating how many times to write the word. 

    No return value. 
    """
    print("-A-")
    try:
        # Possible PermissionError or FileExistsError!
        file_obj = open(file_name, 'x')
        for _ in range(count):
            file_obj.write(word + "\n")
        file_obj.close()

    except FileExistsError:
        print("-B-")

    print("-C-")

def main():
    """ The main obtains command line arguments and makes an appropriate 
    call to the print_words function.
    """
    print("-D-")
    try:
        file_name = sys.argv[1]   # Possible IndexError!
        word = sys.argv[2]        # Possible IndexError!
        count = int(sys.argv[3])  # Possible IndexError or ValueError!
        print("-E-")
        print_words(file_name, word, count)
        print("-F-")

    except IndexError:
        print("-G-")
    except ValueError:
        print("-H-")
    except FileExistsError:
        print("-I-")

    print("-J-")

if __name__ == "__main__":
    try:
        main()
    except Exception:
        print("-K-")