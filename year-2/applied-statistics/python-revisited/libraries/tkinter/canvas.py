import tkinter as tk

WIDTH = 400
HEIGHT = 400

root = tk.Tk()

canvas = tk.Canvas(root, width=WIDTH, height=HEIGHT)
canvas.pack()

button = tk.Button(root, text="Click me!", bg='blue', fg='white')
button.pack()

root.mainloop()