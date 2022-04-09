from tkinter import *


def submitt():
    pname = uia.get()
    m1 = ma.get()
    m2 = mar.get()
    m3 = marks.get()
    avg = (int(m1)+int(m2)+int(m3))/3
    labe = Label(window, text="User name is : "+pname,
                 font="Arial").place(x=300, y=500)
    lab = Label(window, text="The average marks is : " +
                str(avg), font="Arial").place(x=300, y=550)


window = Tk()
window.geometry('800x800')
window.title("Student details")

l = Label(window, text="Fill up this Form", font="Arial").place(x=300, y=10)

user_name = Label(window, text="Username", font="Arial").place(x=200, y=55)
uia = Entry(window)
uia.place(x=300, y=60)


sub = Label(window, text="Select the Gender", font="Arial").place(x=110, y=140)
var = StringVar()
R1 = Radiobutton(window, text="Male", variable=var, value="Male", font="Arial")
R1.place(x=300, y=100)
R2 = Radiobutton(window, text="Female", variable=var,
                 value="Female", font="Arial")
R2.place(x=300, y=140)


sub = Label(window, text="Select the Qualification",
            font="Arial").place(x=80, y=260)
listbox = Listbox(window, height=4, width=20, font="Arial")
listbox.insert(1, "10+2 or Equivalent")
listbox.insert(2, "College Student")
listbox.insert(3, "Graduate")
listbox.insert(4, "Post Graduate")
listbox.insert(5, "Illiterate")
listbox.place(x=300, y=230)


sub = Label(window, text="Enter marks of Three subjects",
            font="Arial").place(x=200, y=350)
l1 = Label(window, text="Subject 1").place(x=240, y=390)
l2 = Label(window, text="Subject 2").place(x=240, y=430)
l3 = Label(window, text="Subject 3").place(x=240, y=470)
ma = Entry(window)
ma.place(x=300, y=390)
mar = Entry(window)
mar.place(x=300, y=430)
marks = Entry(window)
marks.place(x=300, y=470)
button = Button(window, text='Submit details', bd=10, width=25, bg="blue",
                fg="white", border=5, command=submitt).place(x=300, y=600)

window.mainloop()
