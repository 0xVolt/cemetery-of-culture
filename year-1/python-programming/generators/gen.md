# Generators in Python

- These functions are special functions that return an *iterator* instead of a *value*

###### *iterators: object which can be traversed one-by-one. eg: list, tuple. Also, it can be defined as an object having an next method*

- Generators are objects that you can loop over like a list

- Lazy iterators can be looped over like a list. They do not store their content in memory.

- Use `yield()` instead of `return()` to suspend the state and resume the function later. The functions execution will resume to where it was last yielded.

###### *Note: You cab have more than one `yield()` statement in the generator*

- When the generator is called later, the same state will be resumed.

### Example of a generator

    def my_gen():
        n - 1
        print('First')

        # This statement separates 
        regular fns from generators
        
        yield n 
        
        # Generator is giving up 
        control so the fn is suspended 
        after saving its state

        n += 1
        print('Second')
        yield n

    # Can loop over returned 
    iterator
    
    for item in my_gen():
        print(item)

###### *Note: we could use the flg code instead of the for loop*
    obj = my_gen()
    # First
    print(next(obj))

    # To call is again

    # Second
    print(next(obj))

    # Calling it again will result in 
    an error and an exception 
    StopIteration will be raised

## Example of an infinite loop

    def my_seq():
        num = 0
        while True:
            yield num
            num += 1

    for i in my_seq():
        print(i)

## Generator Expressions

They look similar to list comprehension but we use `()` instead of `[]`

### List comprehension
    l = [3, 4, 5, 6, 7, 1]
    new_l = [x for x in l if x > 3]

### Generator expression
    l = 3, 4, 5, 6, 7, 1]
    gen_x = (x for x in l if x > 3)

    for item in genx:
        print(item)

Here the `gen_x` variable stores the generator object