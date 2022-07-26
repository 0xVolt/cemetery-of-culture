# Regular Expressions

## 29/4/21

- Regex (Reg expressions) is a sequence of characters that forms a search pattern.

- Used to check if a string contains the given search pattern

- `import re` to import built in package `re`

- Functions: `search(), findall(), split(), sub()`

## Example
    import re
    txt = "This is a test!"
    x = re.findall('[\w]', txt)
    if x:
        print("At least one match!")
        print(x)
    else:
        print("No match")

- `\w` is a special seq which prints all the letters
- `\bis` matches those words starting with 'is'
- `is\b` matches those words ending in 'is'
- `^T` will match the beginning of the string (different from \b which matches beginning of a word) 
- `T$` will match for the end of a string

**_where T is a sequence of chars to look for_**

## Special Characters

* `.` matches ***any*** character
* `*` matches ***zero*** or more repetitions of the preceding repetitions
* `+` matches ***one*** or more repetitions of the preceding repetitions
* `^` matches ***start*** of a ***string***
* `$` matches ***end*** of the string or just ***before a newline***

###### *Note: `*` and `+` are greedy in the sense that they match as much as possible from the text*

## Example
    import re

    txt = input("Enter a string: ")

    x = re.search('o.*', txt)

    if x:
        print("Matches: ")
        print(x.group())
    else:
        print("No matches!")

* This would match everything following an `o`

###### *Note: search returns object of type match, to print the actual string, we use group()*

### How do we get around the greedy nature?

    x = re.search('o.+?d')

- `*?` and `+?` are the _**non-greedy**_ versions of `*` or `+`
- It returns early instead of continuing to search
- Acts as sort of a break statement to find the earliest match of a seq. of chars

## Example
    txt = (1+2) * (2+3)
    x = re.search('\(.*\)', txt)

This searches for any character between `(` and `)` since we have `.*` inside

This will print `(1+2) * (2+3)`

    txt = (1+2) * (2+3)
    x = re.search('\(.*?\)', txt)

This will print `(1+2)` being the ***non-greedy*** version of `*`

###### *Note: ? ensures 0 or 1 match*

***

## 3/5/21

## Substitute Method

    import re 
    txt = "this is a test string in python"

    # We want to replace python with C (replace a certain substring)

    print(txt)
    
    # Substitution of every occurrence
    result = re.sub('python', 'C', txt)

    print(result)

- Useful when replacing extra space characters in a document

- Subsitute all occurrences with 2 or more spaces with 1 space

##### Note: expression for space is \s

- `txt = re.sub('\s+', '\s', txt)` to replace all extra spaces with single space 

## Split Method

    import re

    txt = "This is a python course"
    print(txt)

    result = re.sub('python', 'C', txt)
    print(result)

    # Split the string by \s
    result2 = re.split(' ', txt)

- Returns list of strings like the default split method in python

## Compile Method

- Create pattern objects that can be used multiple times

        # Program to find spaces at the of a string
        
        import re

        txt = "This is a test string"

        # Saving pattern object to find spaces at the end of a string
        p = re.compile(r'\s+$')

        # Use pattern obj to call any method
        # Since pattern is saved, the pattern doesn't need to be passed

        result3 = p.sub('', txt)
        print(result3)

- This saved pattern maybe use to perform ops in diff strings

- Maybe worth saving pattern beforehand for better documentation