# List Comprehension
***
## 3/5/21

- List comp gives us concise way to create lists

## Example
### Create a list of even ints between 0 to 100

#### Without List comprehension

    l = []
    for i in range(1, 101):
        if i % 2 == 0:
            l.append(i)

    print(l)

#### With List comprehension

    l = [x for x in range(1, 100) if x % 2 == 0]

    print(l)

### More Examples

    