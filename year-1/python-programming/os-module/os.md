# OS module in Python 
## File and Directory management

List of commands under file and dir management

    import os

    # List all sub-dirs and 
    files - ls command
    print(os.listdir())

    # Check pwd
    print(os.getcwd())

    # To change directories
    print(os.chdir('newdirpath'))

    # Make and Remove an empty directory
    os.mkdir('dirname')
    os.rmdir('dirname')

    # To rename a dir
    os.rename('oldname', 'newname')

    # To remove a file
    os.remove()

### Example

Print those files or directories starting with the letters `py`

    import os

    for f in os.listdir
        if f.startsWith('py')
            print(f)

## Process Creation

- When you call `fork()`, a copy of the program execution is created. All of the variables and the state of the prog is stored.

- When you call `fork()`, two processes are created.

- To differentiate between parent and child (clone) system calls, we use the process id.

- `fork()` returns a value in ecah proecss to differentiate between them

- `fork()` returns **0** in **child** process and returns **pid** in the **parent** process.

- External commands like ls, cal, etc. `fork()` is called and a child process is created.

#### Taking the example of `ls` command
- Bash shell is the parent proecss and immediately after a command is typed, `wait()` is called to wait for the complete execution of the child process, i.e. listing out all of the directories in the dir.

- 