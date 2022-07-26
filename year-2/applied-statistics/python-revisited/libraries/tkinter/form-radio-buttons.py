from tkinter import *


def username():
    pname = uia.get()
    print("User name is :", pname)


def click():
    print("Button was Clicked")


def sel():
    selection = "You selected the option " + str(var.get())
    label.config(text=selection)
    print(selection)


root = Tk()
root.geometry('500x500')
root.title("FIRST TKINTER APP")
l = Label(root, text="Hello").pack()
user_name = Label(root, text="Username :").place(x=100, y=100)
uia = Entry(root)
uia.pack(padx=100, pady=80)

b1 = Button(root, text='Click Me', border=5, bg="blue", fg="white",
            width=10, command=click).place(x=200, y=300)
b2 = Button(root, text='Stop', border=5, width=10, bg="black",
            fg="white", command=root.destroy).place(x=200, y=350)
b3 = Button(root, text='Submit', border=5, bg="blue", fg="white",
            width=10, command=username).place(x=200, y=130)

var = IntVar()
R1 = Radiobutton(root, text="1.First", variable=var, value=1,
                 command=sel)
R1.pack()

R2 = Radiobutton(root, text="2.Second", variable=var, value=2,
                 command=sel)
R2.pack()

R3 = Radiobutton(root, text="3.Third", variable=var, value=3,
                 command=sel)
R3.pack()

label = Label(root)
label.pack()
root.mainloop()
